// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[1]),4);
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[1]));
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+17,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+18,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+19,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+20,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+21,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+22,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+23,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgCData(oldp+24,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+25,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__key_list[1]),4);
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+27,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[1]));
        bufp->chgCData(oldp+28,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+29,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgCData(oldp+30,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+31,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__key_list[1]),4);
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+33,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[1]));
        bufp->chgCData(oldp+34,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[0]),6);
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[1]),6);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+38,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+39,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+40,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+41,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+42,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+43,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgCData(oldp+44,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+45,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__key_list[1]),4);
        bufp->chgBit(oldp+46,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+47,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[1]));
        bufp->chgCData(oldp+48,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+49,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+50,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+51,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+52,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[0]),6);
        bufp->chgCData(oldp+53,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[1]),6);
        bufp->chgCData(oldp+54,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+55,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+56,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+57,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[1]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+58,(vlSelf->top__DOT__xbar_i__DOT__sel_w),4);
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__xbar_i__DOT__aw_ready));
        bufp->chgBit(oldp+60,(vlSelf->top__DOT__xbar_i__DOT__w_ready));
        bufp->chgCData(oldp+61,(vlSelf->top__DOT__xbar_i__DOT__b_resp),2);
        bufp->chgBit(oldp+62,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+63,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m1__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+64,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+65,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m2__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+66,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+67,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m3__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+68,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__aw_ready))));
        bufp->chgBit(oldp+69,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_ready))));
        bufp->chgCData(oldp+70,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                                  ? (IData)(vlSelf->top__DOT__xbar_i__DOT__b_resp)
                                  : 0U)),2);
        bufp->chgBit(oldp+71,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__aw_ready))));
        bufp->chgBit(oldp+72,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_ready))));
        bufp->chgCData(oldp+73,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                                  ? (IData)(vlSelf->top__DOT__xbar_i__DOT__b_resp)
                                  : 0U)),2);
        bufp->chgBit(oldp+74,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__b_ready))));
        bufp->chgBit(oldp+75,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__b_ready))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgIData(oldp+76,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? vlSelf->top__DOT__xbar_i__DOT__aw_addr
                                  : 0U)),32);
        bufp->chgBit(oldp+77,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__aw_valid))));
        bufp->chgIData(oldp+78,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? vlSelf->top__DOT__xbar_i__DOT__w_data
                                  : 0U)),32);
        bufp->chgCData(oldp+79,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? (IData)(vlSelf->top__DOT__xbar_i__DOT__w_strb)
                                  : 0U)),4);
        bufp->chgBit(oldp+80,(vlSelf->top__DOT__sram_w_valid));
        bufp->chgIData(oldp+81,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? vlSelf->top__DOT__xbar_i__DOT__aw_addr
                                  : 0U)),32);
        bufp->chgBit(oldp+82,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__aw_valid))));
        bufp->chgIData(oldp+83,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? vlSelf->top__DOT__xbar_i__DOT__w_data
                                  : 0U)),32);
        bufp->chgCData(oldp+84,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w))
                                  ? (IData)(vlSelf->top__DOT__xbar_i__DOT__w_strb)
                                  : 0U)),4);
        bufp->chgBit(oldp+85,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_w)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__w_valid))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+86,(vlSelf->top__DOT__xbar_i__DOT__sel_r),4);
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__xbar_i__DOT__ar_ready));
        bufp->chgCData(oldp+88,(vlSelf->top__DOT__xbar_i__DOT__r_resp),2);
        bufp->chgBit(oldp+89,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+90,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m5__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+91,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+92,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m8__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+93,(vlSelf->top__DOT__ifu_r_valid));
        bufp->chgBit(oldp+94,(vlSelf->top__DOT__lsu_r_valid));
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__sram_ar_addr),32);
        bufp->chgBit(oldp+96,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__ar_valid))));
        bufp->chgBit(oldp+97,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_ready))));
        bufp->chgIData(oldp+98,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r))
                                  ? vlSelf->top__DOT__xbar_i__DOT__ar_addr
                                  : 0U)),32);
        bufp->chgBit(oldp+99,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r)) 
                               & (IData)(vlSelf->top__DOT__xbar_i__DOT__ar_valid))));
        bufp->chgBit(oldp+100,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__sel_r)) 
                                & (IData)(vlSelf->top__DOT__xbar_i__DOT__r_ready))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__ifu_ar_addr_pc),32);
        bufp->chgBit(oldp+102,(vlSelf->top__DOT__ifu_ar_valid));
        bufp->chgBit(oldp+103,(vlSelf->top__DOT__ifu_r_ready));
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__lsu_aw_addr),32);
        bufp->chgBit(oldp+105,(vlSelf->top__DOT__lsu_aw_valid));
        bufp->chgIData(oldp+106,(vlSelf->top__DOT__lsu_w_data),32);
        bufp->chgCData(oldp+107,(vlSelf->top__DOT__lsu_w_strb),4);
        bufp->chgBit(oldp+108,(vlSelf->top__DOT__lsu_w_valid));
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__lsu_ar_addr),32);
        bufp->chgBit(oldp+110,(vlSelf->top__DOT__lsu_ar_valid));
        bufp->chgBit(oldp+111,(vlSelf->top__DOT__sram_b_valid));
        bufp->chgBit(oldp+112,(vlSelf->top__DOT__sram_r_valid));
        bufp->chgCData(oldp+113,(vlSelf->top__DOT__Xriscv_i__DOT__rd_addr1),5);
        bufp->chgCData(oldp+114,(vlSelf->top__DOT__Xriscv_i__DOT__rd_addr2),5);
        bufp->chgIData(oldp+115,(vlSelf->top__DOT__Xriscv_i__DOT__ifu_i__DOT__instr_reg),32);
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__Xriscv_i__DOT__ifu_i__DOT__pc_reg),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__pc),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data4),32);
        bufp->chgBit(oldp+120,(vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_en));
        bufp->chgCData(oldp+121,(vlSelf->top__DOT__Xriscv_i__DOT__idu_wr_addr),5);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data1),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data2),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data3),32);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__op_data4),32);
        bufp->chgBit(oldp+127,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_en));
        bufp->chgCData(oldp+128,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__wr_addr),5);
        bufp->chgIData(oldp+129,(vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__debug_pc),32);
        bufp->chgBit(oldp+130,(vlSelf->top__DOT__Xriscv_i__DOT__lsu_success));
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__Xriscv_i__DOT__lsu_mem_rdata),32);
        bufp->chgCData(oldp+132,((0x7fU & vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr)),7);
        bufp->chgCData(oldp+133,((7U & (vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+134,((vlSelf->top__DOT__Xriscv_i__DOT__idu_exu_reg_i__DOT__instr 
                                  >> 0x19U)),7);
        bufp->chgCData(oldp+135,(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_rindex),2);
        bufp->chgCData(oldp+136,(vlSelf->top__DOT__Xriscv_i__DOT__exu_i__DOT__mem_windex),2);
        bufp->chgIData(oldp+137,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[0]),32);
        bufp->chgIData(oldp+138,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[1]),32);
        bufp->chgIData(oldp+139,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[2]),32);
        bufp->chgIData(oldp+140,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[3]),32);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[4]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[5]),32);
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[6]),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[7]),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[8]),32);
        bufp->chgIData(oldp+146,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[9]),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[10]),32);
        bufp->chgIData(oldp+148,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[11]),32);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[12]),32);
        bufp->chgIData(oldp+150,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[13]),32);
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[14]),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[15]),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[16]),32);
        bufp->chgIData(oldp+154,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[17]),32);
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[18]),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[19]),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[20]),32);
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[21]),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[22]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[23]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[24]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[25]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[26]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[27]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[28]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[29]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[30]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__regs[31]),32);
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_i__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+170,((0x7fU & vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg)),7);
        bufp->chgCData(oldp+171,((7U & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+172,((vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                  >> 0x19U)),7);
        bufp->chgCData(oldp+173,((0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                           >> 7U))),5);
        bufp->chgCData(oldp+174,((0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+175,((0x1fU & (vlSelf->top__DOT__Xriscv_i__DOT__ifu_idu_reg_i__DOT__instr_reg 
                                           >> 0x14U))),5);
        bufp->chgSData(oldp+176,((0x44U | (IData)(vlSelf->top__DOT__lsu_aw_valid))),10);
        bufp->chgCData(oldp+177,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+178,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+179,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+180,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__data_list[1]));
        __Vtemp_2[0U] = (IData)((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_aw_addr))));
        __Vtemp_2[1U] = (IData)(((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_aw_addr))) 
                                 >> 0x20U));
        __Vtemp_2[2U] = 0x10U;
        bufp->chgWData(oldp+181,(__Vtemp_2),72);
        bufp->chgQData(oldp+184,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgQData(oldp+186,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgIData(oldp+188,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+189,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__data_list[1]),32);
        __Vtemp_4[0U] = (IData)((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_w_data))));
        __Vtemp_4[1U] = (IData)(((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_w_data))) 
                                 >> 0x20U));
        __Vtemp_4[2U] = 0x10U;
        bufp->chgWData(oldp+190,(__Vtemp_4),72);
        bufp->chgQData(oldp+193,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgQData(oldp+195,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgIData(oldp+197,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+198,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgSData(oldp+199,((0x1020U | (IData)(vlSelf->top__DOT__lsu_w_strb))),16);
        bufp->chgCData(oldp+200,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[0]),8);
        bufp->chgCData(oldp+201,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[1]),8);
        bufp->chgCData(oldp+202,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[0]),4);
        bufp->chgCData(oldp+203,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[1]),4);
        bufp->chgSData(oldp+204,((0x44U | (IData)(vlSelf->top__DOT__lsu_w_valid))),10);
        bufp->chgCData(oldp+205,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+206,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+207,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+208,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__data_list[1]));
        __Vtemp_6[0U] = (IData)((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__lsu_ar_addr))));
        __Vtemp_6[1U] = ((vlSelf->top__DOT__ifu_ar_addr_pc 
                          << 4U) | (IData)(((0x200000000ULL 
                                             | (QData)((IData)(vlSelf->top__DOT__lsu_ar_addr))) 
                                            >> 0x20U)));
        __Vtemp_6[2U] = (0x10U | (vlSelf->top__DOT__ifu_ar_addr_pc 
                                  >> 0x1cU));
        bufp->chgWData(oldp+209,(__Vtemp_6),72);
        bufp->chgQData(oldp+212,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgQData(oldp+214,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgIData(oldp+216,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+217,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[1]),32);
        bufp->chgSData(oldp+218,((0x44U | (((IData)(vlSelf->top__DOT__ifu_ar_valid) 
                                            << 5U) 
                                           | (IData)(vlSelf->top__DOT__lsu_ar_valid)))),10);
        bufp->chgCData(oldp+219,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+220,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+221,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+222,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__data_list[1]));
        bufp->chgSData(oldp+223,((0x45U | ((IData)(vlSelf->top__DOT__ifu_r_ready) 
                                           << 5U))),10);
        bufp->chgCData(oldp+224,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+225,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+226,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+227,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__data_list[1]));
        bufp->chgSData(oldp+228,((0x44U | (((IData)(vlSelf->top__DOT__sram_b_valid) 
                                            << 5U) 
                                           | (IData)(vlSelf->top__DOT__uart_b_valid)))),10);
        bufp->chgCData(oldp+229,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+230,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+231,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+232,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__data_list[1]));
        bufp->chgSData(oldp+233,((0x44U | (((IData)(vlSelf->top__DOT__sram_r_valid) 
                                            << 5U) 
                                           | (IData)(vlSelf->top__DOT__uart_r_valid)))),10);
        bufp->chgCData(oldp+234,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[0]),5);
        bufp->chgCData(oldp+235,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__pair_list[1]),5);
        bufp->chgBit(oldp+236,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[0]));
        bufp->chgBit(oldp+237,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__data_list[1]));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+238,(vlSelf->top__DOT__sram_i__DOT__r_data),32);
        __Vtemp_8[0U] = (IData)((0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__uart_r_data))));
        __Vtemp_8[1U] = ((vlSelf->top__DOT__sram_i__DOT__r_data 
                          << 4U) | (IData)(((0x200000000ULL 
                                             | (QData)((IData)(vlSelf->top__DOT__uart_r_data))) 
                                            >> 0x20U)));
        __Vtemp_8[2U] = (0x10U | (vlSelf->top__DOT__sram_i__DOT__r_data 
                                  >> 0x1cU));
        bufp->chgWData(oldp+239,(__Vtemp_8),72);
        bufp->chgQData(oldp+242,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgQData(oldp+244,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgIData(oldp+246,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+247,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__data_list[1]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgCData(oldp+248,(vlSelf->top__DOT__xbar_i__DOT__grant),4);
        bufp->chgBit(oldp+249,(vlSelf->top__DOT__xbar_i__DOT__b_ready));
        bufp->chgBit(oldp+250,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+251,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m6__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgBit(oldp+252,(vlSelf->top__DOT__ifu_req));
        bufp->chgBit(oldp+253,(vlSelf->top__DOT__lsu_req));
        bufp->chgCData(oldp+254,(vlSelf->top__DOT__Xriscv_i__DOT__wr_addr),5);
        bufp->chgIData(oldp+255,(vlSelf->top__DOT__Xriscv_i__DOT__wr_data),32);
        bufp->chgBit(oldp+256,(vlSelf->top__DOT__Xriscv_i__DOT__wen));
        bufp->chgIData(oldp+257,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_data1),32);
        bufp->chgIData(oldp+258,(vlSelf->top__DOT__Xriscv_i__DOT__gpr_data2),32);
        bufp->chgIData(oldp+259,(vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data1),32);
        bufp->chgIData(oldp+260,(vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data2),32);
        bufp->chgIData(oldp+261,(vlSelf->top__DOT__Xriscv_i__DOT__idu_op_data3),32);
        bufp->chgBit(oldp+262,(vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp));
        bufp->chgIData(oldp+263,(vlSelf->top__DOT__Xriscv_i__DOT__exu_jmp_pc),32);
        bufp->chgBit(oldp+264,(vlSelf->top__DOT__Xriscv_i__DOT__exu_flush));
        bufp->chgBit(oldp+265,(vlSelf->top__DOT__Xriscv_i__DOT__exu_stall));
        bufp->chgCData(oldp+266,(vlSelf->top__DOT__Xriscv_i__DOT__exu_flag),2);
        bufp->chgIData(oldp+267,(vlSelf->top__DOT__Xriscv_i__DOT__exu_addr),32);
        bufp->chgCData(oldp+268,(vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_mask),4);
        bufp->chgIData(oldp+269,(vlSelf->top__DOT__Xriscv_i__DOT__exu_mem_data),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[7U])) {
        bufp->chgIData(oldp+270,(vlSelf->top__DOT__xbar_i__DOT__aw_addr),32);
        bufp->chgBit(oldp+271,(vlSelf->top__DOT__xbar_i__DOT__aw_valid));
        bufp->chgIData(oldp+272,(vlSelf->top__DOT__xbar_i__DOT__w_data),32);
        bufp->chgCData(oldp+273,(vlSelf->top__DOT__xbar_i__DOT__w_strb),4);
        bufp->chgBit(oldp+274,(vlSelf->top__DOT__xbar_i__DOT__w_valid));
        bufp->chgIData(oldp+275,(vlSelf->top__DOT__xbar_i__DOT__ar_addr),32);
        bufp->chgBit(oldp+276,(vlSelf->top__DOT__xbar_i__DOT__ar_valid));
        bufp->chgBit(oldp+277,(vlSelf->top__DOT__xbar_i__DOT__r_ready));
        bufp->chgBit(oldp+278,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+279,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m1__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+280,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+281,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m2__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+282,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+283,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m3__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+284,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out),4);
        bufp->chgBit(oldp+285,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m4__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+286,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+287,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m5__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+288,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+289,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m7__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+290,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+291,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m8__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+292,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__lut_out));
        bufp->chgBit(oldp+293,(vlSelf->top__DOT__xbar_i__DOT__m_arbiter_i__DOT__m9__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+294,(vlSelf->clk));
    bufp->chgBit(oldp+295,(vlSelf->rst));
    bufp->chgIData(oldp+296,(vlSelf->debug_regs[0]),32);
    bufp->chgIData(oldp+297,(vlSelf->debug_regs[1]),32);
    bufp->chgIData(oldp+298,(vlSelf->debug_regs[2]),32);
    bufp->chgIData(oldp+299,(vlSelf->debug_regs[3]),32);
    bufp->chgIData(oldp+300,(vlSelf->debug_regs[4]),32);
    bufp->chgIData(oldp+301,(vlSelf->debug_regs[5]),32);
    bufp->chgIData(oldp+302,(vlSelf->debug_regs[6]),32);
    bufp->chgIData(oldp+303,(vlSelf->debug_regs[7]),32);
    bufp->chgIData(oldp+304,(vlSelf->debug_regs[8]),32);
    bufp->chgIData(oldp+305,(vlSelf->debug_regs[9]),32);
    bufp->chgIData(oldp+306,(vlSelf->debug_regs[10]),32);
    bufp->chgIData(oldp+307,(vlSelf->debug_regs[11]),32);
    bufp->chgIData(oldp+308,(vlSelf->debug_regs[12]),32);
    bufp->chgIData(oldp+309,(vlSelf->debug_regs[13]),32);
    bufp->chgIData(oldp+310,(vlSelf->debug_regs[14]),32);
    bufp->chgIData(oldp+311,(vlSelf->debug_regs[15]),32);
    bufp->chgIData(oldp+312,(vlSelf->debug_regs[16]),32);
    bufp->chgIData(oldp+313,(vlSelf->debug_regs[17]),32);
    bufp->chgIData(oldp+314,(vlSelf->debug_regs[18]),32);
    bufp->chgIData(oldp+315,(vlSelf->debug_regs[19]),32);
    bufp->chgIData(oldp+316,(vlSelf->debug_regs[20]),32);
    bufp->chgIData(oldp+317,(vlSelf->debug_regs[21]),32);
    bufp->chgIData(oldp+318,(vlSelf->debug_regs[22]),32);
    bufp->chgIData(oldp+319,(vlSelf->debug_regs[23]),32);
    bufp->chgIData(oldp+320,(vlSelf->debug_regs[24]),32);
    bufp->chgIData(oldp+321,(vlSelf->debug_regs[25]),32);
    bufp->chgIData(oldp+322,(vlSelf->debug_regs[26]),32);
    bufp->chgIData(oldp+323,(vlSelf->debug_regs[27]),32);
    bufp->chgIData(oldp+324,(vlSelf->debug_regs[28]),32);
    bufp->chgIData(oldp+325,(vlSelf->debug_regs[29]),32);
    bufp->chgIData(oldp+326,(vlSelf->debug_regs[30]),32);
    bufp->chgIData(oldp+327,(vlSelf->debug_regs[31]),32);
    bufp->chgIData(oldp+328,(vlSelf->debug_pc),32);
    bufp->chgIData(oldp+329,(vlSelf->debug_instr),32);
    bufp->chgBit(oldp+330,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                            & (IData)(vlSelf->top__DOT__xbar_i__DOT__b_valid))));
    bufp->chgBit(oldp+331,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                            & (IData)(vlSelf->top__DOT__xbar_i__DOT__ar_ready))));
    bufp->chgCData(oldp+332,(((1U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                               ? (IData)(vlSelf->top__DOT__xbar_i__DOT__r_resp)
                               : 0U)),2);
    bufp->chgBit(oldp+333,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                            & (IData)(vlSelf->top__DOT__xbar_i__DOT__b_valid))));
    bufp->chgBit(oldp+334,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant)) 
                            & (IData)(vlSelf->top__DOT__xbar_i__DOT__ar_ready))));
    bufp->chgIData(oldp+335,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                               ? vlSelf->top__DOT__xbar_i__DOT__r_data
                               : 0U)),32);
    bufp->chgCData(oldp+336,(((2U == (IData)(vlSelf->top__DOT__xbar_i__DOT__grant))
                               ? (IData)(vlSelf->top__DOT__xbar_i__DOT__r_resp)
                               : 0U)),2);
    bufp->chgBit(oldp+337,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->chgBit(oldp+338,(vlSelf->top__DOT__xbar_i__DOT__b_valid));
    bufp->chgIData(oldp+339,(vlSelf->top__DOT__xbar_i__DOT__r_data),32);
    bufp->chgBit(oldp+340,(vlSelf->top__DOT__xbar_i__DOT__r_valid));
    bufp->chgBit(oldp+341,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__lut_out));
    bufp->chgBit(oldp+342,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m4__DOT__i0__DOT__hit));
    bufp->chgIData(oldp+343,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__lut_out),32);
    bufp->chgBit(oldp+344,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m6__DOT__i0__DOT__hit));
    bufp->chgBit(oldp+345,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__lut_out));
    bufp->chgBit(oldp+346,(vlSelf->top__DOT__xbar_i__DOT__s_arbiter_i__DOT__m7__DOT__i0__DOT__hit));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
