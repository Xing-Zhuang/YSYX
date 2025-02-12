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

#include <common.h>

//#define DEBUG_CAL

word_t expr(char *e, bool *success);
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
  
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

//验证表达式计算功能   
#ifdef DEBUG_CAL 
  printf("\n\n");
  FILE *fp;
  char str1[30],str2[65536];
  fp=fopen("/home/xz/ysyx-workbench/nemu/tools/gen-expr/input","r");
  assert(fp!=NULL);
  
  while (fscanf(fp, "%s %s", str1, str2) == 2) {  
      bool res;
      int expr_ans=expr(str2,&res);//expr函数的计算结果
      if(res){
        int input_ans; //input文件中的计算结果
        sscanf(str1,"%d",&input_ans);
        if(input_ans!=expr_ans){
          printf("结果不匹配：input文件中的计算结果:%d   expr函数的计算结果:%d\n",input_ans,expr_ans);
          printf("计算表达式：%s\n\n\n",str2);
        } 
      }else{
          //res为false的情况 ：
          //1.input产生的表达式存在问题（buf缓冲区写满了但表达式写了一半没写完）
          //2.input产生的表达式存在除以0的情况
          printf("存在问题的表达式：%s\n\n\n",str2);
      }
  }  
  fclose(fp);

  return 0;
#else
  printf("===");
  /* Start engine. */
  engine_start();
  
  return is_exit_status_bad();
#endif

 
}
