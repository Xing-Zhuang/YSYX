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
/*
    #define EI_NIDENT 16

    typedef struct {
        unsigned char e_ident[EI_NIDENT];   //16
        uint16_t      e_type;      //2
        uint16_t      e_machine;   //2
        uint32_t      e_version;   //4
        ElfN_Addr     e_entry;     //4
        ElfN_Off      e_phoff;     //4   
        ElfN_Off      e_shoff;     //4
        uint32_t      e_flags;     //4   
        uint16_t      e_ehsize;    //2
        uint16_t      e_phentsize; //2 
        uint16_t      e_phnum;     //2
        uint16_t      e_shentsize; //2   48
        uint16_t      e_shnum;     //2
        uint16_t      e_shstrndx;  //2
    } ElfN_Ehdr;


    typedef struct {
        uint32_t   sh_name;
        uint32_t   sh_type;
        uint32_t   sh_flags;
        Elf32_Addr sh_addr;
        Elf32_Off  sh_offset;
        uint32_t   sh_size;
        uint32_t   sh_link;
        uint32_t   sh_info;
        uint32_t   sh_addralign;
        uint32_t   sh_entsize;
    } Elf32_Shdr;

    typedef struct {
        uint32_t      st_name;
        Elf32_Addr    st_value;
        uint32_t      st_size;
        unsigned char st_info;
        unsigned char st_other;
        uint16_t      st_shndx;
    } Elf32_Sym;
*/
#include <isa.h>
#include <memory/paddr.h>
#include <elf.h>
#define ElfN_Ehdr Elf32_Ehdr
static char *elf_file = NULL;
typedef struct FunInfo{
  char name[100];//函数名
  uint32_t value;//函数地址 
  uint32_t size;//函数所占字节数
  struct FunInfo* next;
}FunInfo;
FunInfo* funInfoHead;

void init_ELF(){
  //printf("%s\n",elf_file);
  //1.解析ELF Header ：获取section headers的偏移
  FILE* fp=fopen(elf_file,"r");
  if (fp == NULL)
  {
      printf("打开文件失败！\n");
      exit(0);
  }
  ElfN_Ehdr* elf_h=malloc(sizeof(ElfN_Ehdr)); 
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
  Elf32_Shdr* sh=malloc(shnum*sizeof(Elf32_Shdr));
  p=(char*)sh;
  for(int i=0;i<shnum*sizeof(Elf32_Shdr);i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
  uint32_t shstrtab_off=(uint32_t)sh[shstrndx].sh_offset;//获取.shstrtab的偏移
  uint32_t shstrtab_size=(uint32_t)sh[shstrndx].sh_size;//获取.shstrtab的大小
  //printf("shstrtab_off: %x  shstrtab_size:%x\n",shstrtab_off,shstrtab_size);  
  fseek(fp,shstrtab_off,0);
  char* shstrtab=malloc(shstrtab_size);
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
  char* strtab=malloc(strtab_size);
  for(int i=0;i<strtab_size;i++) {
      strtab[i]=fgetc(fp);
  }
 

  fseek(fp,symtab_off,0);
  Elf32_Sym* symtab=malloc(symtab_size);
  p=(char*)symtab;
  for(int i=0;i<symtab_size;i++) {
      char ch=fgetc(fp);
      p[i]=ch;
  }
 

  funInfoHead=malloc(sizeof(FunInfo));
  funInfoHead->next=NULL;
  FunInfo* curNode=funInfoHead;
  for(int i=0;i<symtab_size/(uint32_t)sizeof(Elf32_Sym);i++){//遍历symtab的条目
         uint32_t      st_name=symtab[i].st_name;
         Elf32_Addr    st_value=symtab[i].st_value;
         uint32_t      st_size=symtab[i].st_size;
         unsigned char st_info=symtab[i].st_info;
         if(ELF32_ST_TYPE(st_info)==2){//函数类型的符号
              FunInfo* newNode=malloc(sizeof(FunInfo));
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

void ftrace(int type,uint32_t pc,uint32_t dnpc,uint32_t inst){
#ifdef CONFIG_FTRACE
   if(type==1){//jal
      char name[200];
      findFun(dnpc,name);
      printf("0x%08x: call[%s@0x%08x]\n",pc,name,dnpc);
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
#else
   return;
#endif
}


void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  //Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();
 

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg;  break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg;  break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e                      .elf path for ftrace\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */
  
  /* Parse arguments. */
  parse_args(argc, argv);

#ifdef CONFIG_FTRACE
  /* Parse ELF. */
  init_ELF();
#endif

  /* Set random seed. */
  init_rand();  

  /* Open the log file. */
  init_log(log_file);  

  /* Initialize memory. */   //用随机数初始整个内存
  init_mem();    

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device()); //如果autoconf.h中定义了宏CONFIG_DEVICE 1，则为init_device() 否则为空行

  /* Perform ISA dependent initialization. */
  init_isa();


  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();//4096
   

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);// diff_so_file=/home/xz/ysyx-workbench/nemu/tools/spike-diff/build/riscv32-spike-so

  /* Initialize the simple debugger. */
  init_sdb();

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE, init_disasm(
    MUXDEF(CONFIG_ISA_x86,     "i686",
    MUXDEF(CONFIG_ISA_mips32,  "mipsel",
    MUXDEF(CONFIG_ISA_riscv,
      MUXDEF(CONFIG_RV64,      "riscv64",
                               "riscv32"),
                               "bad"))) "-pc-linux-gnu"
  ));
#endif

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
