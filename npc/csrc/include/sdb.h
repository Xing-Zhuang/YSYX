#ifndef SDB_H
#define SDB_H

#include <readline/readline.h>
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define NR_CMD ARRLEN(cmd_table)

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  

  return line_read;
}

int cmd_help(char *args);
int cmd_c(char *args);
int cmd_si(char *args);
int cmd_q(char *args);
int cmd_info(char *args);
int cmd_examine(char *args);


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);//函数指针
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "si","execute n instruction", cmd_si },
  { "q", "Exit NEMU", cmd_q },
  { "info","print the status", cmd_info },
  { "x","examine the memory", cmd_examine },
  /* TODO: Add more commands */
};
 
  
void sdb_mainloop() {
  
   
  cmd_c(nullptr);
  return;
   
  
  

  //循环在命令行接收输入
  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }
 

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }
     
    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }

  
}

#endif