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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void list_wp();
bool new_wp(char *exp);
void free_wp(int NO);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  nemu_state.state=NEMU_END;
  return -1;
}

static int cmd_help(char *args);

//执行n条指令
static int cmd_si(char *args) {
  
  if(args==NULL)
      cpu_exec(1); 
  else{
      char *arg = strtok(args, " ");
      int n=atoi(arg);
      if(n<0){
        printf("Please input nonnegative number\n");
      }
      else{
        cpu_exec((uint64_t)n);   
      }
  }
   
   
  return 0;
}

//打印程序状态：寄存器
static int cmd_info(char *args) {
  if(args==NULL){
    printf("info r-- List of integer registers and their contents.\n");
    printf("info w-- Status of watchpoints.\n"); 
  }
  else{
      char *arg = strtok(args, " ");
      if(!strcmp(arg,"r")) 
        isa_reg_display();
      else if(!strcmp(args,"w")){
        list_wp();
      }
      else{
        printf("info r-- List of integer registers and their contents.\n");
        printf("info w-- Status of watchpoints.\n"); 
      }
  }
  
 
   
   
  return 0;
}

//打印内存状态
static int cmd_examine(char *args) {
  
  if(args==NULL){
     printf("Argument required (starting display address).\n");
  }   
  else{
      int n;
      MUXDEF(PMEM64, uint64_t , uint32_t) addr;
      #ifdef PMEM64 
          sscanf(args, "%d %lx",&n,&addr);
      #else
          sscanf(args, "%d %x",&n,&addr);
      #endif

      #ifdef CONFIG_ISA64
          for(int i=0;i<n;i++){
            word_t data=paddr_read(addr+8*i,8);
            printf("%016lx\n",data);
          }
      #else
          for(int i=0;i<n;i++){
            word_t data=paddr_read(addr+4*i,4);
            printf("%08x\n",data);
          }
          //以取0x80000000处的指令为例解释大小端情况
          //pmem数组中前4个字节依次存放的是97 02 00 00，所以4字节的data数据存放情况也是97 02 00 00
          //那为什么printf输出的是00000297呢？因为调用printf函数时，操作系统知道你的电脑是小端顺序，所以会在输出时做处理，将顺序调整为正常顺序
      #endif
  } 
   
   
  return 0;
}

//计算表达式
static int cmd_p(char *args) {
  bool res;
  //printf(" %s",args);
  int ans=expr(args,&res);
  if(res)
    printf("计算结果：%d\n",ans);
  
  return 0;
}

static int cmd_wp(char *args){
#ifndef CONFIG_WATCHPOINT
    printf("WATCHPOINT FUNCTION IS NOT ENABLE\n");
    return 0;
#endif
    if(args==NULL){
       printf("Argument required (expression to compute).\n");
    }
    else{
       new_wp(args);
    }

    return 0;
}

static int cmd_del_wp(char *args){
#ifndef CONFIG_WATCHPOINT
    printf("WATCHPOINT FUNCTION IS NOT ENABLE\n");
    return 0;
#endif

    if(args==NULL){
       printf("Argument required (expression to compute).\n");
    }
    else{
      free_wp(atoi(args));
    }
    return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);//函数指针
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si","execute n instruction", cmd_si },
  { "info","print the status", cmd_info },
  { "x","examine the memory", cmd_examine },
  { "p","calculate the expression", cmd_p },
  { "watch","add the watchpoint", cmd_wp },
  { "d","delete the watchpoint", cmd_del_wp },
  /* TODO: Add more commands */
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;
   
  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

//主循环 
void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  //循环在命令行接收输入
  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }
     
    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
