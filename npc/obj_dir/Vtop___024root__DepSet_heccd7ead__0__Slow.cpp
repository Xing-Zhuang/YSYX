// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_addr__0 
        = vlSelf->top__DOT__xbar_i__DOT__aw_addr;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_valid__0 
        = vlSelf->top__DOT__xbar_i__DOT__aw_valid;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_addr__0 
        = vlSelf->top__DOT__xbar_i__DOT__ar_addr;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_valid__0 
        = vlSelf->top__DOT__xbar_i__DOT__ar_valid;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg__0 
        = vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr__0 
        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__ifu_req__0 
        = vlSelf->top__DOT__ifu_req;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__lsu_req__0 
        = vlSelf->top__DOT__lsu_req;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__sram_ar_addr__0 
        = vlSelf->top__DOT__sram_ar_addr;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__sram_w_valid__0 
        = vlSelf->top__DOT__sram_w_valid;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[1U] = 0x100000000ULL;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[1U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[1U] = 0x100000000ULL;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[1U] = 0x10U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[1U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[0U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[1U] = 0U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[0U] = 5U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[1U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list[0U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list[0U] = 5U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[1U] = 3U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[1U] = 3U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[1U] = 3U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[1U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/xz/ysyx-workbench/npc/vsrc/top.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([changed] top.xbar_i.aw_addr or [changed] top.xbar_i.aw_valid)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] top.xbar_i.ar_addr or [changed] top.xbar_i.ar_valid)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([changed] top.Xriscv_i.ifu_idu_reg_i.instr_reg)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([changed] top.Xriscv_i.idu_exu_reg_i.instr)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([changed] top.ifu_req or [changed] top.lsu_req)\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([changed] top.sram_ar_addr)\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([changed] top.sram_w_valid)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([changed] top.xbar_i.aw_addr or [changed] top.xbar_i.aw_valid)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] top.xbar_i.ar_addr or [changed] top.xbar_i.ar_valid)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([changed] top.Xriscv_i.ifu_idu_reg_i.instr_reg)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([changed] top.Xriscv_i.idu_exu_reg_i.instr)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([changed] top.ifu_req or [changed] top.lsu_req)\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([changed] top.sram_ar_addr)\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([changed] top.sram_w_valid)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->debug_regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->debug_pc = VL_RAND_RESET_I(32);
    vlSelf->debug_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu_ar_addr_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu_ar_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu_r_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu_r_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu_req = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lsu_aw_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lsu_aw_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lsu_w_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lsu_w_strb = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__lsu_w_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lsu_ar_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lsu_ar_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lsu_r_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lsu_req = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sram_w_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sram_b_resp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__sram_b_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sram_ar_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__sram_r_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sram_r_resp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__uart_aw_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uart_w_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uart_b_resp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__uart_b_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uart_ar_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uart_r_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__uart_r_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uart_r_resp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__Xriscv_i__DOT__jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__jump_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Xriscv_i__DOT__wr_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__lsu_success = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__ifu_i__DOT__instr_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__ifu_i__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__xbar_i__DOT__grant = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__xbar_i__DOT__sel_w = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__xbar_i__DOT__sel_r = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__xbar_i__DOT__aw_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__aw_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__aw_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__w_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__w_strb = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__xbar_i__DOT__w_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__w_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__b_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__b_resp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__xbar_i__DOT__b_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__ar_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__ar_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__ar_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__r_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__r_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__r_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__r_resp = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sram_i__DOT__w_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__sram_i__DOT__r_data = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_addr__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__aw_valid__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_addr__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__xbar_i__DOT__ar_valid__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__ifu_req__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__lsu_req__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__sram_ar_addr__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__sram_w_valid__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
