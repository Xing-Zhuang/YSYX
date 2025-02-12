#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"// Include model header, generated from Verilating "top.v"
#include <stdio.h>
#include "svdpi.h"
#include "include/sdb.h"
#include "include/memory.h"
#include "include/ftrace.h"
#include "include/difftest.h"
#define DIFFTEST

int main_ret=0;
int clk=0;
bool flag=true;
VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vtop* top;
char* imgbin_path=NULL;
char* elf_file_path=NULL;
char* def_file_path=NULL;
int port=1234;
char  regs_name[32][10]={"zero","ra","sp","gp","tp","t0","t1","t2","s0/fp","s1","a0","a1","a2","a3","a4","a5","a6","a7","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","t3","t4","t5","t6"};

/*差分测试相关*/
bool dut_finish_one=false;
int  dut_finish_pc=0;
int  dut_store_type=0;
int  dut_store_addr=0;

bool dut_finish_one_pass=false;
int  dut_finish_pc_pass=0;
int  dut_store_type_pass=0;    
int  dut_store_addr_pass=0;  
/*差分测试相关*/


void init_disasm(const char *triple);
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

void init_log(){
    //清空文件   
    FILE *ifu_log_fp=NULL;
    ifu_log_fp=fopen("./log/ifu_log.txt", "w");
    if (ifu_log_fp == NULL) {
        perror("打开文件时出错");
        return;
    }
    fclose(ifu_log_fp);

    //清空文件
    FILE *exu_log_fp=NULL;
    exu_log_fp=fopen("./log/exu_log.txt", "w");
    if (exu_log_fp == NULL) {
        perror("打开文件时出错");
        return;
    }
    fclose(exu_log_fp);

}


//exu模块调用 表示下一个clk上升沿到来时刻就完成一条指令
extern "C" void finish_one(int finish_pc,int store_type,int store_addr){
   // printf("finish_one:   clk:%d  top->clk:%d  finish_pc:%x\n",clk,top->clk,finish_pc);
    dut_finish_one=true;
    dut_finish_pc=finish_pc;
    dut_store_type=store_type;
    dut_store_addr=store_addr;

} 

//记录ifu每个clk的指令情况
extern "C" void disassemble_ifu(uint32_t pc, uint32_t instr){
  if(instr==0){
      FILE *ifu_log_fp=NULL;
      ifu_log_fp=fopen("./log/ifu_log.txt", "a");
      if (ifu_log_fp == NULL) {
          perror("打开文件时出错");
          return;
      }
      fputs("NOP", ifu_log_fp);
      fputs("\n",ifu_log_fp);
      fclose(ifu_log_fp);
  }
  else {
    char str[100];
    disassemble(str, 100,(uint64_t)pc, (uint8_t *)&instr , 4);
    
    //将结果写入文件
    FILE *ifu_log_fp=NULL;
    ifu_log_fp=fopen("./log/ifu_log.txt", "a");
    if (ifu_log_fp == NULL) {
        perror("打开文件时出错");
        return;
    }
    char pc_str[100];  
    sprintf(pc_str, "%x", pc);
    fputs(pc_str, ifu_log_fp);

    fputs(" ", ifu_log_fp);
    char instr_str[100];  
    sprintf(instr_str, "%08x", instr);
    fputs(instr_str, ifu_log_fp);

    fputs(" ", ifu_log_fp);
    fputs(str, ifu_log_fp);
    

    fputs("\n",ifu_log_fp);
    fclose(ifu_log_fp);

    //printf("%x: %s\n",pc,str);
  }
    
}

//记录idu每个clk的指令情况
extern "C" void disassemble_idu(uint32_t pc, uint32_t instr){
  if(instr==0){
      FILE *idu_log_fp=NULL;
      idu_log_fp=fopen("./log/idu_log.txt", "a");
      if (idu_log_fp == NULL) {
          perror("打开文件时出错");
          return;
      }
      
      fputs("NOP", idu_log_fp);
      fputs("\n",idu_log_fp);
      fclose(idu_log_fp);
  }
  else{
    char str[100];
    disassemble(str, 100,(uint64_t)pc, (uint8_t *)&instr , 4);
    
    //将结果写入文件
    FILE *idu_log_fp=NULL;
    idu_log_fp=fopen("./log/idu_log.txt", "a");
    if (idu_log_fp == NULL) {
        perror("打开文件时出错");
        return;
    }
    char pc_str[100];  
    sprintf(pc_str, "%x", pc);
    fputs(pc_str, idu_log_fp);

    fputs(" ", idu_log_fp);
    char instr_str[100];  
    sprintf(instr_str, "%08x", instr);
    fputs(instr_str, idu_log_fp);


    fputs(" ", idu_log_fp);
    fputs(str, idu_log_fp);
    fputs("\n",idu_log_fp);

    fclose(idu_log_fp);
  }
    
}

//记录exu每个clk的指令情况
extern "C" void disassemble_exu(uint32_t pc, uint32_t instr){
  if(instr==0){
      FILE *exu_log_fp=NULL;
      exu_log_fp=fopen("./log/exu_log.txt", "a");
      if (exu_log_fp == NULL) {
          perror("打开文件时出错");
          return;
      }
      fputs("NOP", exu_log_fp);
      fputs("\n",exu_log_fp);
      fclose(exu_log_fp);
  }
  else{
    char str[100];
    disassemble(str, 100,(uint64_t)pc, (uint8_t *)&instr , 4);
    
    //将结果写入文件
    FILE *exu_log_fp=NULL;
    exu_log_fp=fopen("./log/exu_log.txt", "a");
    if (exu_log_fp == NULL) {
        perror("打开文件时出错");
        return;
    }
    char pc_str[100];  
    sprintf(pc_str, "%x", pc);
    fputs(pc_str, exu_log_fp);

    fputs(" ", exu_log_fp);
    char instr_str[100];  
    sprintf(instr_str, "%08x", instr);
    fputs(instr_str, exu_log_fp);


    fputs(" ", exu_log_fp);
    fputs(str, exu_log_fp);
    fputs("\n",exu_log_fp);

    fclose(exu_log_fp);
  }
    
}

//verilator相关函数
void step_and_dump_wave(){
  top->eval();//同步电路状态
  contextp->timeInc(1);//将当前波形延迟1s
  
  tfp->dump(contextp->time());//保存波形 timeInc延迟的1s以及eval同步的电路状态
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vtop;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}
void sim_exit(){
  //step_and_dump_wave();
  tfp->close();
}

//在exu中调用
extern "C" void STOP(int stop_type,int instr){//1:exu执行ebreak指令  2.exu遇到未实现指令
  if(stop_type==1){
     
    if(!top->debug_regs[10]){
      printf("\033[32mnpc: exu执行ebreak指令 程序执行得到期望结果\033[0m\n");
    }
    else{
      main_ret=-1;
      printf("\033[31mnpc: exu执行ebreak指令 程序执行未得到期望结果 \033[0m\n");
    }
  }
  else if(stop_type==2){
    main_ret=-1;
    char str[100];           
    disassemble(str, 100,0, (uint8_t *)&instr , 4);
    printf("\033[31mnpc: exu模块未实现指令：%s\033[0m\n",str);
  }

  flag=false;
}
 
//sdb相关函数
int cmd_c(char *args){
  if(!flag){
    printf("已经执行完了所有指令，请重新运行程序\n");
    return 0;
  }
  while (flag) {    
       
      if(clk==9){
        
        //前半clk(低电平)
        top->rst=0b0;
        top->clk=!top->clk; 
        step_and_dump_wave();
       
        //后半clk(高电平)
        top->clk=!top->clk; 
        step_and_dump_wave();


        clk++;
      }
      else{
        

        //前半clk(拉低)（拉成低电平/下降沿）
        top->clk=!top->clk;         
        step_and_dump_wave();


#ifdef DIFFTEST
        if(dut_finish_one){
          dut_finish_one_pass=dut_finish_one;
          dut_finish_pc_pass=dut_finish_pc;
          dut_store_type_pass=dut_store_type;
          dut_store_addr_pass=dut_store_addr;

          dut_finish_one=false;
        }
#endif

        //后半clk(拉高)
        top->clk=!top->clk;
        step_and_dump_wave();

#ifdef DIFFTEST
       if(dut_finish_one_pass){
          //printf("检查时机：clk%d  top->clk:%d\n",clk,top->clk);
          wr_cpu_state();
 
          if(!difftest_step(dut_store_type_pass,dut_store_addr_pass)){
            printf("\n指令pc=0x%x\n\n",dut_finish_pc_pass);

            printf("NPC的寄存器值:\n");
            for(int i=0;i<32;i++){
              printf("%-5s x[%d]=%x\n",regs_name[i],i,top->debug_regs[i]);
            }
              
            step_and_dump_wave();
            tfp->close();
            exit(-1);
          }
          dut_finish_one_pass=false;
       }
#endif
        
        clk++;
        
      }
      
  }      
  tfp->close();//记得调用该函数，否则无法得到.vcd文件

  return 0;
}
int cmd_si(char *args){
 
  if(args==NULL){
    printf("please input a number after 'si'\n");
  }
  else{
      char *arg = strtok(args, " ");
      int n=atoi(arg);
      if(n<0){
        printf("Please input nonnegative number\n");
      }
      else{
        if(!flag){
          printf("已经执行完了所有指令，请重新运行程序\n");
          return 0;
        }
        for(int i=0;i<n;i++){
             if(clk==9){
                int tmp_pc=top->debug_pc;
                char str[100];
                
                disassemble(str, 100,top->debug_pc, (uint8_t *)&top->debug_instr , 4);
                printf("%x: %s\n",top->debug_pc,str);

                top->rst=0b0;
                top->clk=!top->clk; 
                step_and_dump_wave();

                
                top->clk=!top->clk; 
                step_and_dump_wave();

 

                clk++;
              }
              else{
                int tmp_pc=top->debug_pc;
                char str[100];
                 
                disassemble(str, 100,top->debug_pc, (uint8_t *)&top->debug_instr , 4);
                printf("%x: %s\n",top->debug_pc,str);
                
                top->clk=!top->clk;         
                step_and_dump_wave();
                
                top->clk=!top->clk;
                step_and_dump_wave();
 
                clk++;
              }
              if(!flag){
                tfp->close();
                break;
              }
        }   
      }
  }
 
  return 0;
}
int cmd_q(char *args){
  tfp->close();
  return -1;
}
int cmd_info(char *args){
  if(args==NULL){
    printf("info r-- List of integer registers and their contents.\n");
  }
  else{
      char *arg = strtok(args, " ");
      if(!strcmp(arg,"r")){
        printf("pc         0x%08X\n",top->debug_pc);
        for(int i=0;i<32;i++){
          printf("%-10s 0x%08X\n",regs[i],top->debug_regs[i]);
        }
      }      
      else{
        printf("info r-- List of integer registers and their contents.\n");
      }
  }
   
  return 0;
}
int cmd_examine(char *args){
   if(args==NULL){
     printf("Argument required (starting display address).\n");
  }   
  else{
      int n;
      uint32_t addr;
   
      sscanf(args, "%d %x",&n,&addr); 

      for(int i=0;i<n;i++){      
        uint32_t data=pmem_read(addr+4*i);
        printf("%08x\n",data);
      }
         
  } 
  return 0;
}
int cmd_help(char *args) {
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

int parse_args(int argc, char *argv[]) {
  
  int o;
  while ( (o = getopt(argc, argv, "i:e:d:")) != -1) {
    switch (o) {
      case 'i': imgbin_path = optarg;  break;
      case 'e': elf_file_path = optarg;  break;
      case 'd': def_file_path = optarg; break;
      default:
        printf("\t-i,                     imgbin file path\n");
        printf("\t-e                      elf file path for ftrace\n");
        printf("\t-d                      def.so file path for difftest\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void wr_cpu_state(){
   for(int i=0;i<32;i++){
    cpu.gpr[i]=top->debug_regs[i];
   }
   cpu.pc=top->debug_pc;
}
 
void Init(){
  
  int img_size=init_mem(imgbin_path);//初始化内存pmem
  init_ELF(elf_file_path);//解析elf文件 用于ftrace功能
  init_disasm("riscv32");//初始化llvm 用于itrace功能
  init_log();//初始化指令执行log文件
   
  sim_init(); 
  top->clk=1;
  top->rst=1;
  top->eval();//同步计算电路状态
  tfp->dump(contextp->time());//保存波形
   
  
  //前9个clk复位
  while(clk<9){   
      top->rst=0b1;
      top->clk=!top->clk; 
      step_and_dump_wave();
        
      top->rst=0b1;
      top->clk=!top->clk;
      step_and_dump_wave();

      clk++;
  } 
 
#ifdef DIFFTEST
  init_difftest(def_file_path,img_size,port);//初始化diff 用于difftest功能
#endif

}

int main(int argc,char *argv[]) {
   parse_args(argc,argv);
   //printf("%s\n%s\n%s\n",imgbin_path,elf_file_path,def_file_path);
   Init();
   sdb_mainloop();  

   return main_ret;
}