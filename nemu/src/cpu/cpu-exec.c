/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {}; 
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();
bool difftest();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); } //将s->logbuf输出到log文件  s->logbuf在前面exec_once的函数中被存入信息
  wr_iringbuf(_this->logbuf);//将该条指令的信息写入到iringbuf
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));//差分测试 在NEMU中执行完一条指令后, 就在difftest_step()中让REF执行相同的指令, 然后读出REF中的寄存器, 并进行对比.


  //观测wp变化
#ifdef CONFIG_WATCHPOINT
  if(difftest()){
    if(nemu_state.state!=NEMU_END) //防止pc越界溢出
      nemu_state.state=NEMU_STOP;
#ifdef CONFIG_ISA64
    printf("STOP at pc=0x%lx\n",cpu.pc);
#else
    printf("STOP at pc=0x%x\n",cpu.pc);
#endif
  }
#endif

}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc; //当前指令的pc
  s->snpc = pc; //下一条指令的PC，在isa_exec_once中s->snpc会+4
  isa_exec_once(s); //执行一条指令
  cpu.pc = s->dnpc; //正常情况下，s->dnpc=s->snpc;但如果执行了跳转指令，s->dnpc就跟s->snpc不一样了
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;         
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc); //pc写到s->logbuf  指针p直向末尾（snprintf返回写入长度，不包括末尾的0）
  int ilen = s->snpc - s->pc;//指令字节数
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);//指令写入s->logbuf
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);//将反汇编结果写入s->logbuf
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

//执行n条指令
static void execute(uint64_t n) {
  //printf("n:%lu\n",n);
  Decode s;
  for (;n > 0; n --) { 
    //printf("n:%lu",n );  
    exec_once(&s, cpu.pc); //执行一条指令 ：取指, 译码, 执行,更新PC
    g_nr_guest_inst ++; //总执行指令数
    trace_and_difftest(&s, cpu.pc); //记录日志 观测wp变化 
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer); //总执行时间
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst); //总执行指令数
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

 
/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
 
  g_print_step = (n < MAX_INST_TO_PRINT); //当n小于10时，将执行的指令信息进行打印
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

 
  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;
    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT:  statistic(); 
  }
     
  
}
