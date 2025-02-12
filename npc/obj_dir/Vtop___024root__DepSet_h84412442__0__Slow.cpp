// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ stop_type, IData/*31:0*/ instr);
void Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ finish_pc, IData/*31:0*/ is_store, IData/*31:0*/ store_addr);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->debug_pc = vlSelf->top__DOT__ifu_ar_addr_pc;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[0U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_aw_addr)));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__lsu_aw_valid));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[0U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_w_data)));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[0U] 
        = (0x20U | (IData)(vlSelf->top__DOT__lsu_w_strb));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__lsu_w_valid));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list[1U] 
        = (2U | (IData)(vlSelf->top__DOT__ifu_r_ready));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__uart_aw_ready));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__uart_w_ready));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__uart_ar_ready));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[0U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_ar_addr)));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__ifu_ar_addr_pc)));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__lsu_ar_valid));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[1U] 
        = (2U | (IData)(vlSelf->top__DOT__ifu_ar_valid));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[0U] 
        = (8U | (IData)(vlSelf->top__DOT__uart_b_resp));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[1U] 
        = (4U | (IData)(vlSelf->top__DOT__sram_b_resp));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__uart_b_valid));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[1U] 
        = (2U | (IData)(vlSelf->top__DOT__sram_b_valid));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[0U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__uart_r_data)));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__sram_i__DOT__r_data)));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[0U] 
        = (4U | (IData)(vlSelf->top__DOT__uart_r_valid));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[1U] 
        = (2U | (IData)(vlSelf->top__DOT__sram_r_valid));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[0U] 
        = (8U | (IData)(vlSelf->top__DOT__uart_r_resp));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[1U] 
        = (4U | (IData)(vlSelf->top__DOT__sram_r_resp));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
            == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
               == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__b_ready = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_aw_addr;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_aw_valid;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_w_data;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_w_strb;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__ifu_r_ready;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_aw_ready;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_w_ready;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_ar_ready;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_ar_valid;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__ifu_ar_valid;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_b_resp;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_b_resp;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_b_valid;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_b_valid;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_r_resp;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_r_resp;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_w_valid;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__lsu_ar_addr;
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__ifu_ar_addr_pc;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_r_data;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_i__DOT__r_data;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__uart_r_valid;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_r_valid;
    vlSelf->debug_regs[0x1fU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1fU];
    vlSelf->debug_regs[0x1eU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1eU];
    vlSelf->debug_regs[0x1dU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1dU];
    vlSelf->debug_regs[0x1cU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1cU];
    vlSelf->debug_regs[0x1bU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1bU];
    vlSelf->debug_regs[0x1aU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x1aU];
    vlSelf->debug_regs[0x19U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x19U];
    vlSelf->debug_regs[0x18U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x18U];
    vlSelf->debug_regs[0x17U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x17U];
    vlSelf->debug_regs[0x16U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x16U];
    vlSelf->debug_regs[0x15U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x15U];
    vlSelf->debug_regs[0x14U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x14U];
    vlSelf->debug_regs[0x13U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x13U];
    vlSelf->debug_regs[0x12U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x12U];
    vlSelf->debug_regs[0x11U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x11U];
    vlSelf->debug_regs[0x10U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0x10U];
    vlSelf->debug_regs[0xfU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xfU];
    vlSelf->debug_regs[0xeU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xeU];
    vlSelf->debug_regs[0xdU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xdU];
    vlSelf->debug_regs[0xcU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xcU];
    vlSelf->debug_regs[0xbU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xbU];
    vlSelf->debug_regs[0xaU] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0xaU];
    vlSelf->debug_regs[9U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [9U];
    vlSelf->debug_regs[8U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [8U];
    vlSelf->debug_regs[7U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [7U];
    vlSelf->debug_regs[6U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [6U];
    vlSelf->debug_regs[5U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [5U];
    vlSelf->debug_regs[4U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [4U];
    vlSelf->debug_regs[3U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [3U];
    vlSelf->debug_regs[2U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [2U];
    vlSelf->debug_regs[1U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [1U];
    vlSelf->debug_regs[0U] = vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
        [0U];
    vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex 
        = (3U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                 + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
    vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex 
        = (3U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                 + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                       == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                          == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__aw_addr = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit)
                                               ? vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out
                                               : 0U);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
            == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
               == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__aw_valid = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit) 
                                               && (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                       == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                          == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__w_data = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit)
                                              ? vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out
                                              : 0U);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                       == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                          == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__w_strb = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit)
                                              ? (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out)
                                              : 0U);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
            == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
               == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__r_ready = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
            == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
               == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__aw_ready = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit) 
                                               && (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
            == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
               == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__w_ready = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
            == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
               == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__ar_ready = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit) 
                                               && (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
            == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
               == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__ar_valid = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit) 
                                               && (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
                       == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
                          == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__b_resp = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit)
                                              ? (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out)
                                              : 0U);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
            == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
               == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__b_valid = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
                       == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
                          == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__r_resp = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit)
                                              ? (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out)
                                              : 0U);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
            == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
               == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__w_valid = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                       == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
           == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
                          == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__grant) 
              == vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__ar_addr = ((IData)(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit)
                                               ? vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out
                                               : 0U);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
                       == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
                          == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__r_data = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit)
                                              ? vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out
                                              : 0U);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out 
        = (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
            == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
            [0U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
           == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out) 
           | (((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
               == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
               [1U]) & vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r) 
              == vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__xbar_i__DOT__r_valid = ((IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit) 
                                              && (IData)(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out));
    if ((0x40U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 4U)))) {
                if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                                    = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 7U));
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 = 0U;
                            }
                        }
                    }
                } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 7U));
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0xfU));
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 
                            = (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0x1fU))) 
                                << 0xdU) | ((0x1000U 
                                             & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x13U)) 
                                            | ((0x800U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                        >> 7U))))));
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 
                            = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x14U));
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                            = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0xfU));
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 3U)))) {
                if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 7U));
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 = 0U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if (((((((((((0U == ((0x3f8U 
                                              & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU)))) 
                                     || (0x100U == 
                                         ((0x3f8U & 
                                           (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0x16U)) 
                                          | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU))))) 
                                    || (1U == ((0x3f8U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                     >> 0xcU))))) 
                                   || (2U == ((0x3f8U 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0xcU))))) 
                                  || (3U == ((0x3f8U 
                                              & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU))))) 
                                 || (4U == ((0x3f8U 
                                             & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x16U)) 
                                            | (7U & 
                                               (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0xcU))))) 
                                || (5U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                               >> 0xcU))))) 
                               || (0x105U == ((0x3f8U 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0xcU))))) 
                              || (6U == ((0x3f8U & 
                                          (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                           >> 0x16U)) 
                                         | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0xcU))))) 
                             || (7U == ((0x3f8U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0x16U)) 
                                        | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0xcU)))))) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 7U));
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0x14U));
                            vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                                = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0xfU));
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 2U)))) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 
                            = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x14U));
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                            = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0xfU));
                    }
                }
            }
        }
    } else if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                      >> 3U)))) {
            if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                            = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 7U));
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 = 0U;
                    }
                }
            } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                        = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                    >> 7U));
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                        = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                    >> 0xfU));
                }
            }
        }
    } else if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                         >> 3U)))) {
        if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                      >> 2U)))) {
            if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr 
                        = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                    >> 7U));
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en = 1U;
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1 
                        = (0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                    >> 0xfU));
                }
            }
        }
    }
    if ((0U != vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
        if ((0x100073U == vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x4fU, 1U, 0U);
        } else if ((0x40U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x311U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        } else {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                    = ((IData)(4U) 
                                       + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1);
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                       + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x81U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                            } else {
                                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                            }
                        } else {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x91U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = ((IData)(4U) + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1);
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                = (0xfffffffeU & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                                  + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                        } else {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x94U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                        if ((0x4000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                                if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                                    vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                    vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                           >= vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                           + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                           >= vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                } else {
                                    vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                    vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                           < vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                           + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush 
                                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                           < vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                }
                            } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                if (VL_GTES_III(32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)) {
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                                } else {
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                                }
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                       + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                if (VL_LTS_III(32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)) {
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                                } else {
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                                }
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                       + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                            }
                        } else if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0xf1U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            if ((vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                 == vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                            }
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            if ((vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                 == vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 1U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 1U;
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                            }
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            }
        } else if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x61U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x2dcU, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        if (((((((((0U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU)))) 
                                   | (0x100U == ((0x3f8U 
                                                  & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                       >> 0xcU))))) 
                                  | (1U == ((0x3f8U 
                                             & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                >> 0x16U)) 
                                            | (7U & 
                                               (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                >> 0xcU))))) 
                                 | (2U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU))))) 
                                | (3U == ((0x3f8U & 
                                           (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                            >> 0x16U)) 
                                          | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                   >> 0xcU))))) 
                               | (4U == ((0x3f8U & 
                                          (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                           >> 0x16U)) 
                                         | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                  >> 0xcU))))) 
                              | (5U == ((0x3f8U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                   >> 0x16U)) 
                                        | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                 >> 0xcU))))) 
                             | (0x105U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU)))))) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = ((0U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU))))
                                    ? (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                       + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                    : ((0x100U == (
                                                   (0x3f8U 
                                                    & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                         >> 0xcU))))
                                        ? (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                           - vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                        : ((1U == (
                                                   (0x3f8U 
                                                    & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                         >> 0xcU))))
                                            ? VL_SHIFTL_III(32,32,32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                            : ((2U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                       >> 0xcU))))
                                                ? (
                                                   VL_LTS_III(32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   (3U 
                                                    == 
                                                    ((0x3f8U 
                                                      & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                           >> 0xcU))))
                                                    ? 
                                                   ((vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                     < vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     == 
                                                     ((0x3f8U 
                                                       & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                            >> 0xcU))))
                                                     ? 
                                                    (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                     ^ vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                                     : 
                                                    ((5U 
                                                      == 
                                                      ((0x3f8U 
                                                        & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                           >> 0x16U)) 
                                                       | (7U 
                                                          & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                                             >> 0xcU))))
                                                      ? 
                                                     VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                                      : 
                                                     VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2))))))));
                        } else if ((6U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU))))) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   | vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        } else if ((7U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                               >> 0xcU))))) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        } else {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x309U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((0U == (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                      >> 0xcU)))) {
                        if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x1d3U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3));
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 2U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3);
                            if ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex))) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (0xffU & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 1U;
                            } else if ((1U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex))) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (0xff00U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2 
                                                  << 8U));
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 2U;
                            } else if ((2U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex))) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (0xff0000U & 
                                       (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2 
                                        << 0x10U));
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 4U;
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2 
                                       << 0x18U);
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 8U;
                            }
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else if ((1U == (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                             >> 0xcU)))) {
                        if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x208U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 2U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3));
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 2U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3);
                            if ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex))) {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (0xffffU & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 3U;
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2 
                                       << 0x10U);
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0xcU;
                            }
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else if ((2U == (7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                             >> 0xcU)))) {
                        if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x232U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 3U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3));
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 2U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3);
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0xfU;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x252U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            }
        } else if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x71U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                               + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x258U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 0U, 0U);
                    if ((0x4000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                       & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                            } else {
                                vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                    = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                       | vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                                vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                            }
                        } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = ((0x400U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                    ? VL_SHIFTRS_III(32,32,6, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, 
                                                     (0x3fU 
                                                      & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2))
                                    : VL_SHIFTR_III(32,32,6, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, 
                                                    (0x3fU 
                                                     & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)));
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   ^ vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = ((vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                    < vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                    ? 1U : 0U);
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = (VL_LTS_III(32, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2)
                                    ? 1U : 0U);
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = VL_SHIFTL_III(32,32,6, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1, 
                                            (0x3fU 
                                             & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    } else {
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                               + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            }
        } else if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x30eU, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    } else {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    }
                } else {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                }
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            }
        } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
        } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
            if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                if ((0x4000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x1c9U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x1a3U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                            vlSelf->top__DOT__Xriscv_i__DOT__wen 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                                = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                                = ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                    ? (0xffffU & vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata)
                                    : (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                       >> 0x10U));
                        } else {
                            vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                                = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                   + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        }
                    } else if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x173U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                ? (0xffU & vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata)
                                : ((1U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                    ? (0xffU & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                >> 8U))
                                    : ((2U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                        ? (0xffU & 
                                           (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                            >> 0x10U))
                                        : (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                           >> 0x18U))));
                    } else {
                        vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                            = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                               + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    }
                } else if ((0x2000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x1c9U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
                    } else if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x14fU, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata;
                    } else {
                        vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                            = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                               + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    }
                } else if ((0x1000U & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)) {
                    if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                        Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x129U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                        vlSelf->top__DOT__Xriscv_i__DOT__wen 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                            = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                            = ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                ? (((- (IData)((1U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (0xffffU 
                                                 & vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata))
                                : (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                >> 0x1fU))) 
                                    << 0x10U) | (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                 >> 0x10U)));
                    } else {
                        vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                            = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                               + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    }
                } else if (vlSelf->top__DOT__Xriscv_i__DOT__lsu_success) {
                    Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__finish_one_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0xfaU, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc, 1U, 
                                                                                (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                                                                                + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2));
                    vlSelf->top__DOT__Xriscv_i__DOT__wen 
                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en;
                    vlSelf->top__DOT__Xriscv_i__DOT__wr_addr 
                        = vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_addr = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__wr_data 
                        = ((0U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                            ? (((- (IData)((1U & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata))
                            : ((1U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                ? (((- (IData)((1U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                   >> 0xfU)))) 
                                    << 8U) | (0xffU 
                                              & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                 >> 8U)))
                                : ((2U == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex))
                                    ? (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                       >> 0x17U)))) 
                                        << 8U) | (0xffU 
                                                  & (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                     >> 0x10U)))
                                    : (((- (IData)(
                                                   (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                    >> 0x1fU))) 
                                        << 8U) | (vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata 
                                                  >> 0x18U)))));
                } else {
                    vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flag = 1U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_addr 
                        = (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1 
                           + vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2);
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_stall = 1U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
                }
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
            }
        } else {
            Vtop___024root____Vdpiimwrap_top__DOT__Xriscv_i__DOT__exu_i__DOT__STOP_TOP(
                                                                                (&(vlSymsp->__Vscope_top__Xriscv_i__exu_i)), 
                                                                                "/home/xz/ysyx-workbench/npc/vsrc/core/exu.v", 0x314U, 2U, vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr);
        }
    } else {
        vlSelf->top__DOT__Xriscv_i__DOT__wen = 0U;
        vlSelf->top__DOT__Xriscv_i__DOT__wr_data = 0U;
        vlSelf->top__DOT__Xriscv_i__DOT__wr_addr = 0U;
        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp = 0U;
        vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc = 0U;
        vlSelf->top__DOT__Xriscv_i__DOT__exu_flush = 0U;
    }
    vlSelf->top__DOT__sram_w_valid = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                                      & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_valid));
    vlSelf->top__DOT__sram_ar_addr = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r))
                                       ? vlSelf->top__DOT__xbar_i__DOT__ar_addr
                                       : 0U);
    if ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))) {
        vlSelf->debug_instr = vlSelf->top__DOT__xbar_i__DOT__r_data;
        vlSelf->top__DOT__ifu_r_valid = vlSelf->top__DOT__xbar_i__DOT__r_valid;
    } else {
        vlSelf->debug_instr = 0U;
        vlSelf->top__DOT__ifu_r_valid = 0U;
    }
    vlSelf->top__DOT__lsu_r_valid = ((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                                     & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_valid));
    vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2 = (((IData)(vlSelf->top__DOT__Xriscv_i__DOT__wen) 
                                                   & ((IData)(vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2) 
                                                      == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__wr_addr)))
                                                   ? vlSelf->top__DOT__Xriscv_i__DOT__wr_data
                                                   : 
                                                  vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
                                                  [vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2]);
    vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1 = (((IData)(vlSelf->top__DOT__Xriscv_i__DOT__wen) 
                                                   & ((IData)(vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1) 
                                                      == (IData)(vlSelf->top__DOT__Xriscv_i__DOT__wr_addr)))
                                                   ? vlSelf->top__DOT__Xriscv_i__DOT__wr_data
                                                   : 
                                                  vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs
                                                  [vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1]);
    if ((0x40U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 4U)))) {
                if ((8U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                                    = (((- (IData)(
                                                   (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0x1fU))) 
                                        << 0x15U) | 
                                       ((0x100000U 
                                         & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0xbU)) 
                                        | ((0xff000U 
                                            & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg) 
                                           | ((0x800U 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 9U)) 
                                              | (0x7feU 
                                                 & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0x14U))))));
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                                vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                                    = vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc;
                            }
                        }
                    }
                } else if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                                = (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x14U));
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 
                                = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                                = vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                            = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 
                            = vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                            = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 3U)))) {
                if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                                = (0xfffff000U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg);
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        if (((((((((((0U == ((0x3f8U 
                                              & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU)))) 
                                     || (0x100U == 
                                         ((0x3f8U & 
                                           (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0x16U)) 
                                          | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU))))) 
                                    || (1U == ((0x3f8U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                     >> 0xcU))))) 
                                   || (2U == ((0x3f8U 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0xcU))))) 
                                  || (3U == ((0x3f8U 
                                              & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0xcU))))) 
                                 || (4U == ((0x3f8U 
                                             & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x16U)) 
                                            | (7U & 
                                               (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0xcU))))) 
                                || (5U == ((0x3f8U 
                                            & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                               >> 0xcU))))) 
                               || (0x105U == ((0x3f8U 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                    >> 0xcU))))) 
                              || (6U == ((0x3f8U & 
                                          (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                           >> 0x16U)) 
                                         | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 0xcU))))) 
                             || (7U == ((0x3f8U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                   >> 0x16U)) 
                                        | (7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                 >> 0xcU)))))) {
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                                = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                            vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                                = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                          >> 2U)))) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                            = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 
                            = (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                                  >> 7U))));
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                            = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                    }
                }
            }
        }
    } else if ((0x10U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
        if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                      >> 3U)))) {
            if ((4U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                            = (0xfffff000U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg);
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                        vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                            = vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc;
                    }
                }
            } else if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                        = (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x1fU))) 
                            << 0xcU) | (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x14U));
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                        = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                }
            }
        }
    } else if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                         >> 3U)))) {
        if ((1U & (~ (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                      >> 2U)))) {
            if ((2U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                if ((1U & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)) {
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2 
                        = (((- (IData)((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x1fU))) 
                            << 0xcU) | (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0x14U));
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3 = 0U;
                    vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1 
                        = vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1;
                }
            }
        }
    }
}
