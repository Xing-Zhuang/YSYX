// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        CData/*0:0*/ top__DOT__ifu_req;
        CData/*0:0*/ top__DOT__lsu_req;
        CData/*0:0*/ top__DOT__sram_w_valid;
        CData/*0:0*/ top__DOT__xbar_i__DOT__aw_valid;
        CData/*0:0*/ top__DOT__xbar_i__DOT__ar_valid;
        VL_IN8(rst,0,0);
        CData/*0:0*/ top__DOT__ifu_ar_valid;
        CData/*0:0*/ top__DOT__ifu_r_valid;
        CData/*0:0*/ top__DOT__ifu_r_ready;
        CData/*0:0*/ top__DOT__lsu_aw_valid;
        CData/*3:0*/ top__DOT__lsu_w_strb;
        CData/*0:0*/ top__DOT__lsu_w_valid;
        CData/*0:0*/ top__DOT__lsu_ar_valid;
        CData/*0:0*/ top__DOT__lsu_r_valid;
        CData/*1:0*/ top__DOT__sram_b_resp;
        CData/*0:0*/ top__DOT__sram_b_valid;
        CData/*0:0*/ top__DOT__sram_r_valid;
        CData/*1:0*/ top__DOT__sram_r_resp;
        CData/*0:0*/ top__DOT__uart_aw_ready;
        CData/*0:0*/ top__DOT__uart_w_ready;
        CData/*1:0*/ top__DOT__uart_b_resp;
        CData/*0:0*/ top__DOT__uart_b_valid;
        CData/*0:0*/ top__DOT__uart_ar_ready;
        CData/*0:0*/ top__DOT__uart_r_valid;
        CData/*1:0*/ top__DOT__uart_r_resp;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__jump;
        CData/*4:0*/ top__DOT__Xriscv_i__DOT__rd_addr1;
        CData/*4:0*/ top__DOT__Xriscv_i__DOT__rd_addr2;
        CData/*4:0*/ top__DOT__Xriscv_i__DOT__wr_addr;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__wen;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__idu_wr_en;
        CData/*4:0*/ top__DOT__Xriscv_i__DOT__idu_wr_addr;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__exu_jmp;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__exu_flush;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__exu_stall;
        CData/*1:0*/ top__DOT__Xriscv_i__DOT__exu_flag;
        CData/*3:0*/ top__DOT__Xriscv_i__DOT__exu_mem_mask;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__lsu_success;
        CData/*0:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
        CData/*4:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
        CData/*1:0*/ top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex;
        CData/*1:0*/ top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex;
        CData/*3:0*/ top__DOT__xbar_i__DOT__grant;
        CData/*3:0*/ top__DOT__xbar_i__DOT__sel_w;
        CData/*3:0*/ top__DOT__xbar_i__DOT__sel_r;
        CData/*0:0*/ top__DOT__xbar_i__DOT__aw_ready;
        CData/*3:0*/ top__DOT__xbar_i__DOT__w_strb;
        CData/*0:0*/ top__DOT__xbar_i__DOT__w_valid;
        CData/*0:0*/ top__DOT__xbar_i__DOT__w_ready;
        CData/*0:0*/ top__DOT__xbar_i__DOT__b_ready;
        CData/*1:0*/ top__DOT__xbar_i__DOT__b_resp;
        CData/*0:0*/ top__DOT__xbar_i__DOT__b_valid;
        CData/*0:0*/ top__DOT__xbar_i__DOT__ar_ready;
        CData/*0:0*/ top__DOT__xbar_i__DOT__r_ready;
        CData/*0:0*/ top__DOT__xbar_i__DOT__r_valid;
        CData/*1:0*/ top__DOT__xbar_i__DOT__r_resp;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit;
        CData/*3:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out;
    };
    struct {
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit;
        CData/*1:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit;
        CData/*1:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_valid__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_valid__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__ifu_req__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__lsu_req__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__sram_w_valid__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        VL_OUT(debug_pc,31,0);
        VL_OUT(debug_instr,31,0);
        IData/*31:0*/ top__DOT__ifu_ar_addr_pc;
        IData/*31:0*/ top__DOT__lsu_aw_addr;
        IData/*31:0*/ top__DOT__lsu_w_data;
        IData/*31:0*/ top__DOT__lsu_ar_addr;
        IData/*31:0*/ top__DOT__sram_ar_addr;
        IData/*31:0*/ top__DOT__uart_r_data;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__jump_pc;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__wr_data;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__gpr_data1;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__gpr_data2;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_op_data1;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_op_data2;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_op_data3;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_op_data4;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__exu_jmp_pc;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__exu_addr;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__exu_mem_data;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__lsu_mem_rdata;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__gpr_i__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__ifu_i__DOT__instr_reg;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__ifu_i__DOT__pc_reg;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4;
        IData/*31:0*/ top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc;
        IData/*31:0*/ top__DOT__xbar_i__DOT__aw_addr;
    };
    struct {
        IData/*31:0*/ top__DOT__xbar_i__DOT__w_data;
        IData/*31:0*/ top__DOT__xbar_i__DOT__ar_addr;
        IData/*31:0*/ top__DOT__xbar_i__DOT__r_data;
        IData/*31:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__sram_i__DOT__w_addr;
        IData/*31:0*/ top__DOT__sram_i__DOT__r_data;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_addr__0;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_addr__0;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg__0;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr__0;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__sram_ar_addr__0;
        IData/*31:0*/ __VactIterCount;
        VL_OUT(debug_regs[32],31,0);
        VlUnpacked<IData/*31:0*/, 32> top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*7:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*5:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*1:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*4:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list;
    };
    struct {
        VlUnpacked<CData/*0:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*5:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*1:0*/, 2> top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<8> __VactTriggered;
    VlTriggerVec<8> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
