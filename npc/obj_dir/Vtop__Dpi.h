// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/exu.v:42:41
    extern void STOP(int stop_type, int instr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/exu.v:44:41
    extern void disassemble_exu(int pc, int instr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/idu.v:30:42
    extern void disassemble_idu(int pc, int instr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/ifu.v:52:42
    extern void disassemble_ifu(int pc, int instr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/exu.v:45:41
    extern void finish_one(int finish_pc, int is_store, int store_addr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/core/exu.v:43:41
    extern void ftrace(int ftype, int fpc, int dnpc, int inst);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/soc/sram.v:41:33
    extern int pmem_read(int raddr);
    // DPI import at /home/xz/ysyx-workbench/npc/vsrc/soc/sram.v:42:34
    extern void pmem_write(int waddr, int wdata, int wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
