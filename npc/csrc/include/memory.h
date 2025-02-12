#ifndef MEMORY_H
#define MEMORY_H


#include <stdlib.h>
#include <stdlib.h> 
#include <stdint.h>
#include <string.h>


#define MEM_SIZE 0x8000000
#define CONFIG_MBASE 0x80000000

 


static const uint32_t img [] = {  
  0x00009117,
  0xFFF30313,   
  0x00100073,  // ebreak  00000000 00010000 00000000 01110011
  0xdeadbeef,  // some data  
};

static uint8_t mem[MEM_SIZE]  = {};  

int init_mem(char* img_file){
      if (img_file == NULL) {
        memcpy(mem, img, sizeof(img));
        
        return 4096; // built-in image size
      }

      FILE *fp = fopen(img_file, "rb");
      

      fseek(fp, 0, SEEK_END);
      int size = ftell(fp);

     

      fseek(fp, 0, SEEK_SET);
      int ret = fread(mem, size, 1, fp);
     

      fclose(fp);
      return size;


}

uint8_t* guest_to_host(uint32_t paddr) { return mem + paddr - CONFIG_MBASE; }

 
 
static uint64_t us=0;
extern "C"  uint32_t pmem_read(int addr) {//next_skip表示下一条执行是否需要跳过
   

    if(addr==0)//前1个clk时pc还未置位成0x0x80000000
      return 0;
    
    //访问时钟
    if(addr==0xa0000048+4||addr==0xa0000048){
      
      if(addr==0xa0000048+4){
         struct timespec now;
         clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
         us = now.tv_sec * 1000000 + now.tv_nsec / 1000; //系统启动的微妙数

        // printf("%lld s\n",us/1000000);
         return (uint32_t)(us>>32);
      }
      else
         return (uint32_t)us;
      
      
    }
     
    uint8_t* host_addr=mem+(addr-0x80000000);
    return *(uint32_t *)host_addr;
}

 

extern "C"  void pmem_write(int waddr,int wdata,int wmask){
    if(waddr==0xa00003f8){
      putchar(wdata);
      return;
    }
    
    uint8_t* host_addr=mem+(waddr-0x80000000);
    uint8_t* wdata_p = (uint8_t*)&wdata;
 

    for(int i=0;i<4;i++){
      if( ((wmask>>i)&1) ){
        *(host_addr+i)= *(wdata_p+i);
      }
    }

    
 
}


#endif