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
#include <memory/paddr.h>

//iringbuf
#define IRINGBUF_SIZE 10
int max(int x,int y){ return x>y?x:y; };
char iringbuf[IRINGBUF_SIZE][128];
int wr_p=0;//写指针永远指向将要写入的地址
int curSize=0;
void wr_iringbuf(char *str){
    int lastIndx=wr_p-1==-1?9:wr_p-1;
    iringbuf[lastIndx][max(strlen(iringbuf[lastIndx])-13,0)]='\0'; //移除上一条记录的末尾的<------  HERE
    strcpy(iringbuf[wr_p],str);
    strcpy(iringbuf[wr_p]+strlen(str),"<------  HERE\0"); //在这条记录的末尾写入<------  HERE
    wr_p=(wr_p+1)%10;
    if(curSize<IRINGBUF_SIZE){
        curSize++;
    }
}
void print_iringbuf(){
    if(curSize<IRINGBUF_SIZE)
      for(int i=0;i<curSize;i++){
        printf("%s\n",iringbuf[i]);
      } 
    else
      for(int i=0;i<IRINGBUF_SIZE;i++){
        printf("%s\n",iringbuf[i]);
      } 

}


// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
};
//因为我的电脑是小端，所以内存中以img开头的首地址数据存放情况：
//97 02 00 00
//23 88 02 00
//...
//所以在调用memcpy时，也会将该数据顺序一模一样的复制给pmem数组

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = RESET_VECTOR;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
}

void init_isa() {
  cpu.csr[MSTATUS]=0x1800;//针对riscv32, 你需要将mstatus初始化为0x1800.  针对riscv64, 你需要将mstatus初始化为0xa00001800.
  //printf("cpu.csr[MSTATUS]:%x\n",cpu.csr[MSTATUS]);
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  /* Initialize this virtual computer system. */
  restart();
}
