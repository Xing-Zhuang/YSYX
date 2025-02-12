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
 
//mepc寄存器 - 存放触发异常的PC
//mstatus寄存器 - 存放处理器的状态
//mcause寄存器 - 存放触发异常的原因
// 在nemu中 ecall指令执行该函数
word_t isa_raise_intr(word_t NO, vaddr_t epc) {//
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  //printf("ecall调用isa_raise_intr函数\n");
#ifdef CONFIG_ETRACE
  printf("触发异常pc:0x%x  异常号:%d\n",epc,NO);
#endif

  cpu.csr[MEPC]=epc;
  cpu.csr[MCAUSE]=NO;
  //cpu.csr[MSTATUS]=...;//目前不实现

  return  cpu.csr[MTVEC];//返回异常处理函数的首地址 CSR[mtvec]
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
