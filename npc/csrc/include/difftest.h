#ifndef DIFFTEST_H
#define DIFFTEST_H 

#include <dlfcn.h>
#include "memory.h"
#define RESET_VECTOR 0x80000000
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };
static bool is_skip_ref = false;

typedef  void (*ref_difftest_memcpy)(uint32_t, void*, uint32_t, bool);
typedef  void (*ref_difftest_regcpy)(void*, bool) ;
typedef  void (*ref_difftest_exec)(uint64_t) ;
typedef  void (*ref_difftest_raise_intr)(uint64_t) ;
typedef  void (*ref_difftest_init)(int);
ref_difftest_memcpy ref_difftest_memcpy_fun=NULL;
ref_difftest_regcpy ref_difftest_regcpy_fun=NULL;
ref_difftest_exec   ref_difftest_exec_fun=NULL;
ref_difftest_raise_intr ref_difftest_raise_intr_fun=NULL;
ref_difftest_init  ref_difftest_init_fun=NULL;

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
} CPU_state; 

CPU_state cpu;

void difftest_skip_ref() { 
  is_skip_ref = true;
}


//将npc top模块中引出的寄存器和pc 写入到cpu
void wr_cpu_state();

//利用动态加载库机制（注意动态链接库和动态加载库的区别）
void init_difftest(char *ref_so_file, long img_size, int port) {
  //printf("ref_so_file:%s \n img_size:%ld\n  port:%d\n",ref_so_file,img_size,port);
  
  assert(ref_so_file != NULL);

  wr_cpu_state();

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY); //打开传入的动态库文件ref_so_file  
  assert(handle);

  ref_difftest_memcpy_fun = (ref_difftest_memcpy)dlsym(handle, "difftest_memcpy"); 
  assert(ref_difftest_memcpy_fun);

  ref_difftest_regcpy_fun =  (ref_difftest_regcpy)dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy_fun);

  ref_difftest_exec_fun =  (ref_difftest_exec)dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec_fun);

  ref_difftest_raise_intr_fun =  (ref_difftest_raise_intr)dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr_fun);

  ref_difftest_init_fun = (ref_difftest_init) dlsym(handle, "difftest_init");
  assert(ref_difftest_init_fun);

  
 
  ref_difftest_init_fun(port);//对REF的DIffTest功能进行初始化, 具体行为因REF而异.
  ref_difftest_memcpy_fun(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF); 
  ref_difftest_regcpy_fun(&cpu, DIFFTEST_TO_REF);//将nemu的寄存器状态拷贝到REF中.
}

bool checkregs(CPU_state ref) {
    bool flag=true;
    for(int i=0;i<32;i++){
        if(ref.gpr[i]!=cpu.gpr[i]){
          printf("NPC与NEMU寄存器不同\nNPC：x[%d]=%x NEMU：x[%d]=%x\n",i,cpu.gpr[i],i,ref.gpr[i]);
          flag=false;
        }     
    }
    return flag;
    
    /*
    if(ref.pc!=cpu.pc){
      printf("Different  \nDUT：pc=%x REF：pc=%x\n",cpu.pc,ref.pc);
      return false;
    }*/
        
 
    return true;
}
 

//在DUT中执行完一条指令后, 就在difftest_step()中让REF执行相同的指令, 然后读出REF中的寄存器, 并进行对比.
bool difftest_step(int dut_store_type_pass,int dut_store_addr) {

  if (is_skip_ref) {
    //printf("Www\n");
    // to skip the checking of an instruction, just copy the reg state to reference design
    
    ref_difftest_regcpy_fun(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return true;//直接返回，不进行下面的检查了
  }
  

  ref_difftest_exec_fun(1);//在REF中执行一条指令 

  //对比REF与DUT的寄存器
  CPU_state ref_r;
  ref_difftest_regcpy_fun(&ref_r, DIFFTEST_TO_DUT);//将REF中的寄存器状态存入ref_r
  bool same=checkregs(ref_r);

  //对比内存（如果是存数指令，则检查存的那个地址的数据是否一致）
  if(dut_store_type_pass>0){
   
    uint32_t NPC_mem_data=*(uint32_t*)guest_to_host(dut_store_addr);//NPC对应内存地址的数据
    uint32_t NEMU_mem_data;//NEMU对应内存地址的数据
    ref_difftest_memcpy_fun(dut_store_addr, (void*)&NEMU_mem_data, 4, DIFFTEST_TO_DUT);   
    
    if(dut_store_type_pass==1){//SB
      if(*(uint8_t*)&NPC_mem_data!=*(uint8_t*)&NEMU_mem_data){
        printf("\nNPC与NEMU内存地址0x%x处的数据不同 \nNPC：0x%x NEMU：0x%x\n",dut_store_addr,NPC_mem_data,NEMU_mem_data);
        same=false;
      }
    }
    else if(dut_store_type_pass==2){//SH
      if(*(uint16_t*)&NPC_mem_data!=*(uint16_t*)&NEMU_mem_data){
        printf("\nNPC与NEMU内存地址0x%x处的数据不同 \nNPC：0x%x NEMU：0x%x\n",dut_store_addr,NPC_mem_data,NEMU_mem_data);
        same=false;
      }
    } 
    else{//SW
      if(NPC_mem_data!=NEMU_mem_data){
        printf("\nNPC与NEMU内存地址0x%x处的数据不同 \nNPC：0x%x NEMU：0x%x\n",dut_store_addr,NPC_mem_data,NEMU_mem_data);
        same=false;
      }
    }
    
    
  }
   

    




  
  return same; //检查REF和DUT寄存器状态是否一致
}
 
#endif