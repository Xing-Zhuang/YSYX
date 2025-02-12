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
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (2 * 1024 * 1024)

static uint8_t *io_space = NULL;//指向IO空间的首地址
static uint8_t *p_space = NULL;//指向IO空间当前未被分配的首地址

//在大小为IO_SPACE_MAX的IO空间中占用size字节的空间，返回占用空间的首地址
uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { 
    c(offset, len, is_write); 
  }
}

void init_map() {
  io_space =  malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

//读设备  参数： 内存物理地址  长度  映射关系对象
word_t map_read(paddr_t addr, int len, IOMap *map) {
  //printf("name:%s  addr:%x  len:%d\n",map->name,addr,len);
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read 调用设备的回调函数将数据存入IO空间 
  word_t ret = host_read(map->space + offset, len);//从IO空间中读取数据
  return ret;
}


void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
 // printf("name:%s  addr:%x  len:%d  data:%x\n",map->name,addr,len,data);
  
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  
  host_write(map->space + offset, len, data);//将数据写入该设备在本机的IO空间
  invoke_callback(map->callback, offset, len, true);//触发的回调函数 当设备被写入数据时触发回调函数对写入的数据进行处理（不同设备会有不同的处理行为） 
}
