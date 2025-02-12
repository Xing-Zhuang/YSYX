// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__xbar_i__DOT__sel_w = ((IData)(vlSelf->top__DOT__xbar_i__DOT__aw_valid)
                                             ? ((0x80ffffffU 
                                                 > vlSelf->top__DOT__xbar_i__DOT__aw_addr)
                                                 ? 1U
                                                 : 
                                                (((0x10000000U 
                                                   <= vlSelf->top__DOT__xbar_i__DOT__aw_addr) 
                                                  & (0x10000fffU 
                                                     > vlSelf->top__DOT__xbar_i__DOT__aw_addr))
                                                  ? 2U
                                                  : 0U))
                                             : (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w));
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
    vlSelf->top__DOT__sram_w_valid = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                                      & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_valid));
}

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__xbar_i__DOT__sel_r = ((IData)(vlSelf->top__DOT__xbar_i__DOT__ar_valid)
                                             ? ((0x80ffffffU 
                                                 > vlSelf->top__DOT__xbar_i__DOT__ar_addr)
                                                 ? 1U
                                                 : 
                                                (((0x10000000U 
                                                   <= vlSelf->top__DOT__xbar_i__DOT__ar_addr) 
                                                  & (0x10000fffU 
                                                     > vlSelf->top__DOT__xbar_i__DOT__ar_addr))
                                                  ? 2U
                                                  : 0U))
                                             : (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r));
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
    if ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))) {
        vlSelf->debug_instr = vlSelf->top__DOT__xbar_i__DOT__r_data;
        vlSelf->top__DOT__ifu_r_valid = vlSelf->top__DOT__xbar_i__DOT__r_valid;
    } else {
        vlSelf->debug_instr = 0U;
        vlSelf->top__DOT__ifu_r_valid = 0U;
    }
    vlSelf->top__DOT__lsu_r_valid = ((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                                     & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_valid));
}

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__sram_ar_addr = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r))
                                       ? vlSelf->top__DOT__xbar_i__DOT__ar_addr
                                       : 0U);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtop___024root___act_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___act_sequent__TOP__2(vlSelf);
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__sram_i__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->top__DOT__sram_w_valid) {
        Vtop___024root____Vdpiimwrap_top__DOT__sram_i__DOT__pmem_write_TOP(
                                                                           ((1U 
                                                                             == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                                                             ? 
                                                                            (0xfffffffcU 
                                                                             & vlSelf->top__DOT__xbar_i__DOT__aw_addr)
                                                                             : 0U), 
                                                                           ((1U 
                                                                             == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                                                             ? vlSelf->top__DOT__xbar_i__DOT__w_data
                                                                             : 0U), 
                                                                           ((1U 
                                                                             == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                                                             ? (IData)(vlSelf->top__DOT__xbar_i__DOT__w_strb)
                                                                             : 0U));
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__sram_i__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__sram_i__DOT__pmem_read__58__Vfuncout;
    __Vfunc_top__DOT__sram_i__DOT__pmem_read__58__Vfuncout = 0;
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__sram_i__DOT__pmem_read_TOP(
                                                                      (0xfffffffcU 
                                                                       & vlSelf->top__DOT__sram_ar_addr), __Vfunc_top__DOT__sram_i__DOT__pmem_read__58__Vfuncout);
    vlSelf->top__DOT__sram_i__DOT__r_data = __Vfunc_top__DOT__sram_i__DOT__pmem_read__58__Vfuncout;
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__sram_i__DOT__r_data)));
    vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__sram_i__DOT__r_data;
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
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSelf->top__DOT__xbar_i__DOT__grant = ((IData)(vlSelf->top__DOT__lsu_req)
                                             ? 2U : 
                                            ((IData)(vlSelf->top__DOT__ifu_req)
                                              ? 1U : 0U));
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
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->debug_instr = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                            ? vlSelf->top__DOT__xbar_i__DOT__r_data
                            : 0U);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    // Body
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
    vlSelf->top__DOT__ifu_r_valid = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                                     & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_valid));
    vlSelf->top__DOT__lsu_r_valid = ((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                                     & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_valid));
    vlSelf->top__DOT__sram_w_valid = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                                      & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_valid));
    vlSelf->top__DOT__sram_ar_addr = ((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r))
                                       ? vlSelf->top__DOT__xbar_i__DOT__ar_addr
                                       : 0U);
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((0x60ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x24ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<8> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/xz/ysyx-workbench/npc/vsrc/top.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/xz/ysyx-workbench/npc/vsrc/top.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
