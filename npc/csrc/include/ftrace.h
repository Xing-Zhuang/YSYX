#ifndef FTRACE_H
#define FTRACE_H

#include <elf.h>
#define ElfN_Ehdr Elf32_Ehdr

typedef struct FunInfo{
  char name[100];//函数名
  uint32_t value;//函数地址 
  uint32_t size;//函数所占字节数
  struct FunInfo* next;
}FunInfo;
FunInfo* funInfoHead;

void init_ELF(char *elf_file){
  if(elf_file==NULL)
    return;
  //printf("%s\n",elf_file);
  //1.解析ELF Header ：获取section headers的偏移
  FILE* fp=fopen(elf_file,"r");
  if (fp == NULL)
  {
      printf("打开文件失败！\n");
      exit(0);
  }
  ElfN_Ehdr* elf_h=(ElfN_Ehdr*)malloc(sizeof(ElfN_Ehdr)); 
  char* p=(char*)elf_h;
  for(int i=0;i<sizeof(ElfN_Ehdr);i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
  uint32_t shoff=elf_h->e_shoff;//section head off
  uint16_t shnum=shnum=elf_h->e_shnum;//section head entries num
  uint16_t shstrndx=shstrndx=elf_h->e_shstrndx;//section head string index   
  //printf("%u\n",shoff);
  //printf("%u\n",shnum);
  //printf("%u\n",shstrndx);  
  
   
  //2.解析section headers ：获取.shstrtab的偏移->在section head中找到.symtab条目,获取.symtab的偏移
  fseek(fp,shoff,0);
  Elf32_Shdr* sh=(Elf32_Shdr*)malloc(shnum*sizeof(Elf32_Shdr));
  p=(char*)sh;
  for(int i=0;i<shnum*sizeof(Elf32_Shdr);i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
  uint32_t shstrtab_off=(uint32_t)sh[shstrndx].sh_offset;//获取.shstrtab的偏移
  uint32_t shstrtab_size=(uint32_t)sh[shstrndx].sh_size;//获取.shstrtab的大小
  //printf("shstrtab_off: %x  shstrtab_size:%x\n",shstrtab_off,shstrtab_size);  
  fseek(fp,shstrtab_off,0);
  char* shstrtab=(char*)malloc(shstrtab_size);
  p=(char*)shstrtab;
  for(int i=0;i<shstrtab_size;i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
    
  //在section head中找到.symtab条目,获取.symtab的偏移
  uint32_t symtab_off=0,symtab_size=0;
  uint32_t strtab_off=0,strtab_size=0;
  for(int i=0;i<shnum;i++){
      if(!strcmp(shstrtab+sh[i].sh_name,".symtab")){
          symtab_off=sh[i].sh_offset;
          symtab_size=sh[i].sh_size;
      }
      if(!strcmp(shstrtab+sh[i].sh_name,".strtab")){
          strtab_off=sh[i].sh_offset;
          strtab_size=sh[i].sh_size;
      }
  }
  //printf("symtab_off:%x  symtab_size:%x\n",symtab_off,symtab_size);
  //printf("strtab_off:%x  strtab_size:%x\n",strtab_off,strtab_size);
    
  //3.解析.symtab 将Type=FUNC的符号 记录下来
  fseek(fp,strtab_off,0);
  char* strtab=(char*)malloc(strtab_size);
  for(int i=0;i<strtab_size;i++) {
      strtab[i]=fgetc(fp);
  }
 

  fseek(fp,symtab_off,0);
  Elf32_Sym* symtab=(Elf32_Sym*)malloc(symtab_size);
  p=(char*)symtab;
  for(int i=0;i<symtab_size;i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
 

  funInfoHead=(FunInfo*)malloc(sizeof(FunInfo));
  funInfoHead->next=NULL;
  FunInfo* curNode=funInfoHead;
  for(int i=0;i<symtab_size/(uint32_t)sizeof(Elf32_Sym);i++){//遍历symtab的条目
         uint32_t      st_name=symtab[i].st_name;
         Elf32_Addr    st_value=symtab[i].st_value;
         uint32_t      st_size=symtab[i].st_size;
         unsigned char st_info=symtab[i].st_info;
         if(ELF32_ST_TYPE(st_info)==2){//函数类型的符号
              FunInfo* newNode=(FunInfo*)malloc(sizeof(FunInfo));
              strcpy(newNode->name,strtab+st_name);
              newNode->value=st_value;
              newNode->size=st_size;
              newNode->next=NULL;
              curNode->next=newNode;
              curNode=newNode;
         }
  }


  fclose(fp);
 

}

//在funInfoHead链表中根据pc寻找函数名
void findFun(uint32_t pc,char* funName){
    FunInfo* cur=funInfoHead;
    while(cur!=NULL){ 
       
      if(pc>=cur->value&&pc<cur->value+cur->size){
         strcpy(funName,cur->name);
         return;
      }
      cur=cur->next;
    }
    
    return;
}

extern "C"  void ftrace(int ftype,int  pc,int dnpc,int inst){
#ifdef FTRACE
   if(ftype==1){//jal
      char name[200];
      findFun(dnpc,name);
      printf("0x%08x: call[%s@0x%08x]\n", pc,name,dnpc);
   }
   else{//jalr  注意区分ret     
     
      if(inst==0X00008067){//jalr x0 0(x1)  0000 0000 00000000 1000 0000 0110 0111
        char name[200];
        findFun(dnpc,name);
        printf("ret [%s]\n",name);
      }
      else{
        char name[200];
        findFun(dnpc,name);
        printf("0x%08x: call[%s@0x%08x]\n",pc,name,dnpc);
      }
     
   } 
#endif

}

#endif