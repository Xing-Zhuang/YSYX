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

#include "sdb.h"
//#define DEBUG_WP
#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  
  /* TODO: Add more members if necessary */
  char watch_exp[100];//监视表达式
  word_t value;//表达式当前值

} WP;

static WP wp_pool[NR_WP] = {};
static WP *used_head = NULL,*used_tail=NULL, *free_head = NULL, *free_tail=NULL;  
//维护2条队列：used节点链表和free节点链表
//新增wp：从free链表表头获取空闲节点来使用，并将该节点链接到used队列队尾
//删除wp：将要删除的节点链接到free链表表尾
//注：1.used链表和free链表表尾的next都为NULL 2.当used_head==used_tail==NULL时used表示没有被使用的节点即所有节点都空闲，free链表同理

void show(){
  if(used_head!=NULL)
      printf("used_head->NO:%d\n",used_head->NO);
  if(used_tail!=NULL)
      printf("used_tail->NO:%d\n",used_tail->NO);
  if(used_tail!=NULL)
    printf("free_head->NO:%d\n",free_head->NO);
  if(free_tail!=NULL)
    printf("free_tail->NO:%d\n",free_tail->NO);

}


void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    memset(wp_pool[i].watch_exp,0,sizeof(wp_pool[i].watch_exp));
    wp_pool[i].value=0;
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  used_head=used_tail= NULL;
  free_head = wp_pool;
  free_tail = wp_pool+NR_WP-1;
  
#ifdef DEBUG_WP
        show();
#endif
}

void new_wp(char *exp){
    if(free_head==NULL)
      return;
    bool success;
    word_t value=expr(exp,&success);
    //printf("value %d ",value);
    if(success){
      strcpy(free_head->watch_exp,exp);
      free_head->value=value;
     
      WP* tmp=free_head;
      if(free_head==free_tail){
        free_head=free_tail=NULL;
      }
      else{
        free_head=free_head->next;
      }
      

      if(used_head==NULL){
        used_head=used_tail=tmp; 
        used_head->next=NULL;
        used_tail->next=NULL;
      } 
      else{
        used_tail->next=tmp;
        used_tail=used_tail->next;
        tmp->next=NULL;
      }
      
      printf("watchpoint %d: %s\n",tmp->NO,exp);      
    }
    else{
      printf("watchpoint添加失败\n");
    }

#ifdef DEBUG_WP
        show();
#endif
}

void free_wp(int NO){
    if(used_head==NULL){
      printf("No breakpoint number %d.\n",NO);
      return;
    } 
    WP* curWp=used_head;
    WP* preWp=NULL;
    while(curWp!=NULL){
      if(curWp->NO==NO){
        if(preWp==NULL){
           used_head=used_head->next;
           if(used_head==NULL)
             used_tail=NULL;
        }
        else{
            preWp->next=curWp->next;
        }
           
        free_tail->next=curWp;
        free_tail=free_tail->next;
        curWp->next=NULL;
#ifdef DEBUG_WP
        show();
#endif
        return;
      }
      preWp=curWp;
      curWp=curWp->next;
    }

    printf("No breakpoint number %d.\n",NO); 
    
}

void list_wp(){
    if(used_head==NULL)
        return;
     
    printf("Num%*sWhat\n",8," ");
    WP* curWp=used_head;
    while(curWp!=NULL){
      printf("%-10d %s\n",curWp->NO,curWp->watch_exp);
      curWp=curWp->next;
    }
}
 
//遍历used链表 观测表达式值是否变化
bool difftest(){
  if(used_head==NULL)
        return false;

  bool flag=false;
  WP* curWp=used_head;
  while(curWp!=NULL){
    bool success;
    word_t newValue=expr(curWp->watch_exp,&success);
    if(newValue!=curWp->value){
      printf("Watchpoint %d %s\n",curWp->NO,curWp->watch_exp);
      if(curWp->watch_exp[0]=='$'){
#ifdef CONFIG_ISA64
      printf("Old value = 0x%lx\n",curWp->value);
      printf("New value = 0x%lx\n\n",newValue);
#else
      printf("Old value = 0x%x\n",curWp->value);
      printf("New value = 0x%x\n\n",newValue);
#endif
      }
      else{
#ifdef CONFIG_ISA64
      printf("Old value = %ld\n",curWp->value);
      printf("New value = %ld\n\n",newValue);
#else
      printf("Old value = %d\n",curWp->value);
      printf("New value = %d\n\n",newValue);
#endif
      }
      
      curWp->value=newValue;
      flag=true;//表示过触发watchpoint
    }
    curWp=curWp->next;
  }
  
  return flag;
}
