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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
// this should be enough
static int  bufSize;
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
  
//生成[0,n-1]的随机数
uint32_t choose(uint32_t n){
  return rand() % n; 
}
 
void gen_num(){
  if(strlen(buf)>65500)
    return;
  char num_str[20];
  sprintf(num_str, "%u", choose((uint32_t)INT_MAX+1));  //表达式中的数字都是非负整数且大小不超过int的最大值 所以为了验证表达式求值功能，此处生成的随机数范围要是[0,INT_MAX]
  strcat(buf, num_str);  
}
void gen(char* ch){
  if(strlen(buf)>65500)
    return;
  strcat(buf,ch);
}
void gen_rand_op(){
  if(strlen(buf)>65500)
    return;
  switch (choose(4))
  {
    case 0:strcat(buf,"+"); break;
    case 1:strcat(buf,"-"); break;
    case 2:strcat(buf,"*"); break;
    case 3:strcat(buf,"/"); break;
  }
}
static void gen_rand_expr() {
  if(strlen(buf)>65500)
    return;

  switch (choose(3)) {
    case 0: gen_num();  break;
    case 1: gen("(");  gen_rand_expr(); gen(")"); break; 
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  
  for (i = 0; i < loop; i ++) {
    bufSize=0;
    memset(buf,0,sizeof(buf));
    gen_rand_expr();//随机生成表达式结果存放在buf中

    sprintf(code_buf, code_format, buf);//将字符串code_format写入缓冲区code_buf，并用buf替换code_format中的参数%s

    //将code_buf写入文件/tmp/.code.c
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    //编译/tmp/.code.c
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    //popen函数通过创建一个管道（pipe）与子进程的stdin或stdout连接，从而能够读取或写入子进程的输出或输入
    //运行/tmp/.expr文件，获取该文件运行时的printf输出结果
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    //将运行结果写入result
    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    //输出
    printf("%u %s\n", result, buf);
  }
  return 0;
}
