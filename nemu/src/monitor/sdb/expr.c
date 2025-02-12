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
//#define DEBUG_EXPR
#define STACK_SIZE 65536  
word_t paddr_read(paddr_t addr, int len);


typedef struct {  
    char data[STACK_SIZE];  
    int top;  
} Stack;  
  
void init(Stack *s) {  
    s->top = -1;  
}  
  
int is_empty(Stack *s) {  
    return s->top == -1;  
}  
  
int is_full(Stack *s) {  
    return s->top == STACK_SIZE - 1;  
}  
  
void push(Stack *s, char c) {  
    if (is_full(s)) {  
        printf("Error: Stack is full\n");  
        exit(1);  
    }  
    s->data[++s->top] = c;  
}  
  
char pop(Stack *s) {  
    if (is_empty(s)) {  
        printf("Error: Stack is empty\n");  
        exit(1);  
    }  
    return s->data[s->top--];  
}  
  
void print_stack(Stack *s) {  
    printf("Stack contents: ");  
    for (int i = 0; i <= s->top; i++) {  
        printf("%c ", s->data[i]);  
    }  
    printf("\n");  
}  

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, 
  TK_EQ,
  TK_NUM,
  TK_HEX,
  TK_REG,
  TK_NEQ,
  TK_AND,
  TK_DEREF,
  /* TODO: Add more token types */
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},           // sub
  {"\\*", '*'},         // mul
  {"/", '/'},           // div
  {"0x[0-9a-fA-f]+", TK_HEX},   //十六进制数
  {"[0-9]+", TK_NUM},   //十进制整数   
  {"\\(", '('},         //左括号
  {"\\)", ')'},         //右括号
  {"\\$(\\$0|pc|ra|sp|gp|tp|t[0-2]|s[01]|a[0-7]|s[2-9]|s10|s11|t[3-6])", TK_REG},   //寄存器
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},       //not equal
  {"&&", TK_AND},       //and
};  


static struct priorOp {
  int op;
  int prior;
} priorTable[] = {
  {TK_AND,0},
  {TK_NEQ,1},
  {TK_EQ,1},
  {'+',2},  
  {'-',2},  
  {'*',3},  
  {'/',3},
  {TK_DEREF,4}
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
static int flag;//表达式是否错误

//正则匹配表达式，结果存放到tokens中
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;
  
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        //%.*s：这是一个特殊的格式化符号，用于输出指定长度的字符串。第一个%后面的.*表示要接收一个额外的参数来指定字符串的长度

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
          case TK_HEX:  
             tokens[nr_token].type=TK_HEX;
          break;
          case TK_REG:  
             tokens[nr_token].type=TK_REG;
          break;
          case TK_NEQ:  
             tokens[nr_token].type=TK_NEQ;
          break;
          case TK_AND:  
             tokens[nr_token].type=TK_AND;
          break;
          case TK_EQ:  
             tokens[nr_token].type=TK_EQ;
          break;
          case TK_NUM: 
             tokens[nr_token].type=TK_NUM;         
          break;
          case '+':  
             tokens[nr_token].type='+';            
          break;
          case '-':
              //1.如果 - 前面是 ( 则 - 是负号    
              //2.如果 - 出现在第一个位置 则 - 是负号    
              if(nr_token==0|| (nr_token>0&& (tokens[nr_token-1].type=='(')) ){
                  tokens[nr_token].type=TK_NUM;     
                  strncpy(tokens[nr_token].str,"0",2);
                  tokens[nr_token].str[1]=0;
                  nr_token++; 
              } 
              tokens[nr_token].type='-';             
          break;
          case '*':  
             tokens[nr_token].type='*';             
          break;
          case '/':  
             tokens[nr_token].type='/';           
          break;
          case '(':  
             tokens[nr_token].type='(';           
          break;
          case ')':  
             tokens[nr_token].type=')';         
          break;
          default:

          break;
        }
        if(rules[i].token_type!=TK_NOTYPE){
            strncpy(tokens[nr_token].str,substr_start,substr_len);
            tokens[nr_token].str[substr_len]=0;
            nr_token++;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  //处理 乘号和指针解引用
  for (i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type =='+'||tokens[i - 1].type =='-'||tokens[i - 1].type =='*'||tokens[i - 1].type =='('||tokens[i - 1].type ==TK_EQ||tokens[i - 1].type ==TK_NEQ||tokens[i - 1].type ==TK_AND ) ) ) {
      tokens[i].type = TK_DEREF;
    }
  }

#ifdef DEBUG_EXPR
  for(int i=0;i<nr_token;i++){
    printf("%d : %s\n",tokens[i].type,tokens[i].str);
  }
#endif

  return true;
}

//若op1的优先级<=op2的优先级则返回true 否则返回false
bool checkPrior(int op1,int op2){
    int prior1,prior2;
    for(int i=0;i<8;i++){
      if(priorTable[i].op==op1)
        prior1=priorTable[i].prior;
      if(priorTable[i].op==op2)
        prior2=priorTable[i].prior;
    }
    return prior1<=prior2;
}

//tokens[p]~tokens[q]组成的表达式   
//1.若有多余的括号未成功匹配，则返回1
//2.若所有括号都成功匹配了，且整个表达式被一对括号包着，则返回2
//3.若所有括号都成功匹配了，但整个表达式未被一对括号包着，则返回3
int check_parentheses(int p,int q){
   int res;
   Stack s;
   init(&s);
  
    
   if(tokens[p].type=='('&&tokens[q].type==')'){
     
      int pos=-1;//记录表达式最左边的左括号与哪个右括号匹配
      while(p<=q){
        if(tokens[p].type=='('){
          push(&s, '(');  
        }
        else if(tokens[p].type==')'){
          if(!is_empty(&s)){
            pop(&s);
            //printf("pos:%d\n",pos);
            if(is_empty(&s)&&pos==-1){
              pos=p;
            }
          }
          else{
             
            return 1;
          }
        }
        p++;
      }
      if(!is_empty(&s))
        return 1;
      else if(pos==q)
        return 2;
      else 
        return 3;
   }
   else{
       
      while(p<=q){
        if(tokens[p].type=='('){
          push(&s, '(');  
        }
        else if(tokens[p].type==')'){
          if(!is_empty(&s)){
            pop(&s);
          }
          else{
            return 1;
          }
        }
        p++;
      }
      if(!is_empty(&s))
        return 1;
      else
        return 3;
   }
      
   return res;
}

//返回tokens[p]~tokens[q]组成的表达式中主运算符的位置
int findMainOp(int p,int q){
    char mainOp;
    int  pos=-1;

    while(p<=q){
      //跳过括号
      if(tokens[p].type=='('){
        Stack s;
        push(&s,'(');
        p++;
        while(!is_empty(&s)){
          if(tokens[p].type==')')
             pop(&s);
          else if(tokens[p].type=='(')
             push(&s,'(');
          p++;
        }      
      }
      if(p>q)
        break;

      //若为运算符则进行判断
      if(tokens[p].type==TK_DEREF||tokens[p].type=='+'||tokens[p].type=='-'||tokens[p].type=='*'||tokens[p].type=='/'||tokens[p].type==TK_EQ||tokens[p].type==TK_NEQ||tokens[p].type==TK_AND){
          if(pos==-1){
            mainOp=tokens[p].type;
            pos=p;
          }
          else{
            //如果新遇到的运算符优先级<=之前找到的运算符 则替换
            if(checkPrior(tokens[p].type,mainOp)){
              mainOp=tokens[p].type;
              pos=p;
            }
          }
      }

      p++;
    }

    return pos;
}

//计算tokens[p]~tokens[q]组成的表达式的值
int eval(int p, int q) {
  if (p > q) {
    assert(p<=q);
    return -1;
  }
  else if (p == q) {
     if(tokens[q].type==TK_HEX){//十六进制
       char *endptr;
       int ans=strtol(tokens[q].str, &endptr, 16);  
       if (*endptr != '\0') {
        flag=true;
        return 0;
       }  
       return ans;
     }
     else if(tokens[q].type==TK_NUM){//十进制
        return atoi(tokens[q].str);
     }
     else{//取寄存器
        bool success;
        char regName[5];
        strcpy(regName,tokens[q].str+1);
        //printf("regName %s\n",regName);
        word_t ans=isa_reg_str2val(regName,&success);
        if(!success){
          flag=true;
          return 0;
        }
        return ans;
     }
     
  }
  else {
    int type=check_parentheses(p, q);
    //printf("type:%d  p:%d  q:%d\n",type,p,q);
    if(type==1){
      flag=true;
      printf("表达式错误，请重新输入\n");
      return 0;
    }
    else if(type==2){
      return eval(p + 1, q - 1);
    }
    else{
      int op = findMainOp(p,q);//主运算符位置
      if(tokens[op].type==TK_DEREF){
          MUXDEF(PMEM64, uint64_t , uint32_t) addr;
#ifdef PMEM64 
        if(tokens[op+1].type==TK_NUM)
          sscanf(tokens[op+1].str,"%lu",&addr);
        else
          sscanf(tokens[op+1].str,"%lx",&addr);
#else 
        if(tokens[op+1].type==TK_NUM)
          sscanf(tokens[op+1].str,"%u",&addr);
        else
          sscanf(tokens[op+1].str,"%x",&addr);
#endif  
          return paddr_read(addr,4);
      }
      //printf("mainOp:%d\n",op);
      int val1 = eval(p, op - 1);
      int val2 = eval(op + 1, q);
      
      if(flag)
            return 0;
      switch (tokens[op].type) {
        case '+': return val1 + val2; break;
        case '-': return val1 - val2; break; 
        case '*': return val1 * val2; break;
        case '/': 
            if(val2==0){
              flag=true;
              printf("表达式出现除以0的情况，请重新输入\n");
              return 0;
            }
                
            return val1 / val2;
        break;
        case TK_EQ: return val1==val2; break;
        case TK_NEQ: return val1!=val2; break;
        case TK_AND: return val1&&val2; break;
        default: assert(0);
      }
    }
  }
  
   
}

word_t expr(char *e, bool *success) {
  
  nr_token=0;
  flag=false;
   
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
 
  //计算表达式
  word_t res;
  //printf("nr_token %d \n",nr_token);
  if(nr_token==1  &&  tokens[0].type!=TK_NUM&&tokens[0].type!=TK_HEX&&tokens[0].type!=TK_REG){
      printf("表达式错误，请重新输入\n");
      *success = false;
      return 0;
  }
  else {
    res=eval(0,nr_token-1); 
    if(flag){
      *success = false;
      return 0;
    }
    else{
      *success = true;
      return res;
    }
  }
  
}
