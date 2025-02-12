//soc top
`timescale 1ns / 1ps
`include "define.v"
module top(
       input   wire clk,
       input   wire rst,

       output reg[31:0] debug_regs[31:0],
       output wire[`REG_WIDTH-1:0] debug_pc,
       output wire[`REG_WIDTH-1:0] debug_instr
);

    //ifu   接xbar的master1
    wire                       ifu_aw_ready;
    wire[`REG_WIDTH-1:0]       ifu_aw_addr;
    wire                       ifu_aw_valid;

    wire                       ifu_w_ready;
    wire[`REG_WIDTH-1:0]       ifu_w_data;
    wire[`REG_WIDTH/8-1:0]     ifu_w_strb;
    wire                       ifu_w_valid;
  
    wire[`AXI_RESP_WIDTH-1:0]  ifu_b_resp;
    wire                       ifu_b_valid;
    wire                       ifu_b_ready;
  
    wire                       ifu_ar_ready;
    wire[`REG_WIDTH-1:0]       ifu_ar_addr_pc; //PC地址
    wire                       ifu_ar_valid;

    wire                       ifu_r_valid;
    wire[`REG_WIDTH-1:0]       ifu_r_data_inst;//读取的指令
    wire[`AXI_RESP_WIDTH-1:0]  ifu_r_resp;
    wire                       ifu_r_ready;
    
    wire                       ifu_req;

    //lsu  接xbar的master2
    wire                       lsu_aw_ready;
    wire[`REG_WIDTH-1:0]       lsu_aw_addr;
    wire                       lsu_aw_valid;

    wire                       lsu_w_ready;
    wire[`REG_WIDTH-1:0]       lsu_w_data;
    wire[`REG_WIDTH/8-1:0]     lsu_w_strb;
    wire                       lsu_w_valid;
  
    wire[`AXI_RESP_WIDTH-1:0]  lsu_b_resp;
    wire                       lsu_b_valid;
    wire                       lsu_b_ready;
  
    wire                       lsu_ar_ready;
    wire[`REG_WIDTH-1:0]       lsu_ar_addr;  
    wire                       lsu_ar_valid;

    wire                       lsu_r_valid;
    wire[`REG_WIDTH-1:0]       lsu_r_data; 
    wire[`AXI_RESP_WIDTH-1:0]  lsu_r_resp;
    wire                       lsu_r_ready;
    
    wire                       lsu_req;


    //sram 接xbar的subordinate1
    wire[`REG_WIDTH-1:0]       sram_aw_addr;
    wire                       sram_aw_valid;
    wire                       sram_aw_ready;
    
    wire[`REG_WIDTH-1:0]       sram_w_data;
    wire[`REG_WIDTH/8-1:0]     sram_w_strb;
    wire                       sram_w_valid;
    wire                       sram_w_ready;
   
    wire[`AXI_RESP_WIDTH-1:0]  sram_b_resp;
    wire                       sram_b_valid;
    wire                       sram_b_ready;

    wire[`REG_WIDTH-1:0]       sram_ar_addr;
    wire                       sram_ar_valid;
    wire                       sram_ar_ready;
     
    wire                       sram_r_ready;
    wire[`REG_WIDTH-1:0]       sram_r_data;
    wire                       sram_r_valid;
    wire[`AXI_RESP_WIDTH-1:0]  sram_r_resp;

    //uart 接xbar的subordinate2
    wire[`REG_WIDTH-1:0]       uart_aw_addr;
    wire                       uart_aw_valid;
    wire                       uart_aw_ready;
    
    wire[`REG_WIDTH-1:0]       uart_w_data;
    wire[`REG_WIDTH/8-1:0]     uart_w_strb;
    wire                       uart_w_valid;
    wire                       uart_w_ready;
   
    wire[`AXI_RESP_WIDTH-1:0]  uart_b_resp;
    wire                       uart_b_valid;
    wire                       uart_b_ready;

    wire[`REG_WIDTH-1:0]       uart_ar_addr;
    wire                       uart_ar_valid;
    wire                       uart_ar_ready;
     
    wire                       uart_r_ready;
    wire[`REG_WIDTH-1:0]       uart_r_data;
    wire                       uart_r_valid;
    wire[`AXI_RESP_WIDTH-1:0]  uart_r_resp;
  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   assign debug_pc=ifu_ar_addr_pc;
   assign debug_instr=ifu_r_data_inst;
   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



     
    Xriscv Xriscv_i(
        .debug_regs(debug_regs),

        .clk(clk),
        .rst(rst),

        //ifu axi通道
        .ifu_aw_ready_i(ifu_aw_ready),
        .ifu_aw_addr_o(ifu_aw_addr),
        .ifu_aw_valid_o(ifu_aw_valid),
    
        .ifu_w_ready_i(ifu_w_ready),
        .ifu_w_data_o(ifu_w_data),
        .ifu_w_strb_o(ifu_w_strb),
        .ifu_w_valid_o(ifu_w_valid),
    
        .ifu_b_resp_i(ifu_b_resp),
        .ifu_b_valid_i(ifu_b_valid),
        .ifu_b_ready_o(ifu_b_ready),

        .ifu_ar_ready_i(ifu_ar_ready),
        .ifu_ar_addr_pc_o(ifu_ar_addr_pc), //PC地址
        .ifu_ar_valid_o(ifu_ar_valid),
        
        .ifu_r_valid_i(ifu_r_valid),
        .ifu_r_data_inst_i(ifu_r_data_inst),//读取的指令
        .ifu_r_resp_i(ifu_r_resp),
        .ifu_r_ready_o(ifu_r_ready),
    
        .ifu_req_o(ifu_req),

        //lsu AXI信号
        .lsu_aw_ready_i(lsu_aw_ready),
        .lsu_aw_addr_o(lsu_aw_addr),
        .lsu_aw_valid_o(lsu_aw_valid),
    
        .lsu_w_ready_i(lsu_w_ready),
        .lsu_w_data_o(lsu_w_data),
        .lsu_w_strb_o(lsu_w_strb),
        .lsu_w_valid_o(lsu_w_valid),
    
        .lsu_b_resp_i(lsu_b_resp),
        .lsu_b_valid_i(lsu_b_valid),
        .lsu_b_ready_o(lsu_b_ready),

        .lsu_ar_ready_i(lsu_ar_ready),
        .lsu_ar_addr_o(lsu_ar_addr),  
        .lsu_ar_valid_o(lsu_ar_valid),
        
        .lsu_r_valid_i(lsu_r_valid),
        .lsu_r_data_i(lsu_r_data), 
        .lsu_r_resp_i(lsu_r_resp),
        .lsu_r_ready_o(lsu_r_ready),
    
        .lsu_req_o(lsu_req)
    );

    xbar xbar_i(
           
        //master 1   接IFU
            .req1_i(ifu_req),
            //写地址通道
            .aw_addr_i_1(ifu_aw_addr),
            .aw_valid_i_1(ifu_aw_valid),
            .aw_ready_o_1(ifu_aw_ready),
            
            //写数据通道
            .w_data_i_1(ifu_w_data),
            .w_strb_i_1(ifu_w_strb),
            .w_valid_i_1(ifu_w_valid),
            .w_ready_o_1(ifu_w_ready),

            //写回应通道
            .b_ready_i_1(ifu_b_ready),
            .b_resp_o_1(ifu_b_resp),
            .b_valid_o_1(ifu_b_valid),
            
            
            //读地址通道
            .ar_addr_i_1(ifu_ar_addr_pc),  
            .ar_valid_i_1(ifu_ar_valid),
            .ar_ready_o_1(ifu_ar_ready),

            //读数据通道
            .r_ready_i_1(ifu_r_ready),
            .r_data_o_1(ifu_r_data_inst),
            .r_valid_o_1(ifu_r_valid),
            .r_resp_o_1(ifu_r_resp), 

        //master 2   接lsu
            .req2_i(lsu_req),
            //写地址通道
            .aw_addr_i_2(lsu_aw_addr),
            .aw_valid_i_2(lsu_aw_valid),
            .aw_ready_o_2(lsu_aw_ready),
            
            //写数据通道
            .w_data_i_2(lsu_w_data),
            .w_strb_i_2(lsu_w_strb),
            .w_valid_i_2(lsu_w_valid),
            .w_ready_o_2(lsu_w_ready),

            //写回应通道
            .b_ready_i_2(lsu_b_ready),
            .b_resp_o_2(lsu_b_resp),
            .b_valid_o_2(lsu_b_valid),
            
            
            //读地址通道
            .ar_addr_i_2(lsu_ar_addr),  
            .ar_valid_i_2(lsu_ar_valid),
            .ar_ready_o_2(lsu_ar_ready),

            //读数据通道
            .r_ready_i_2(lsu_r_ready),
            .r_data_o_2(lsu_r_data),
            .r_valid_o_2(lsu_r_valid),
            .r_resp_o_2(lsu_r_resp), 
             
                
        //subordinate1  接SRAM
            //写地址通道
            .aw_ready_i_1(sram_aw_ready),
            .aw_addr_o_1(sram_aw_addr),
            .aw_valid_o_1(sram_aw_valid),
            
            
            //写数据通道
            .w_ready_i_1(sram_w_ready),
            .w_data_o_1(sram_w_data),
            .w_strb_o_1(sram_w_strb),
            .w_valid_o_1(sram_w_valid),
            

            //写回应通道
            .b_resp_i_1(sram_b_resp),
            .b_valid_i_1(sram_b_valid),
            .b_ready_o_1(sram_b_ready),

            //读地址通道
            .ar_ready_i_1(sram_ar_ready),
            .ar_addr_o_1(sram_ar_addr),  
            .ar_valid_o_1(sram_ar_valid),
            

            //读数据通道
            .r_data_i_1(sram_r_data),
            .r_valid_i_1(sram_r_valid),
            .r_resp_i_1(sram_r_resp),
            .r_ready_o_1(sram_r_ready),
    
        //subordinate2
            //写地址通道
            .aw_ready_i_2(uart_aw_ready),
            .aw_addr_o_2(uart_aw_addr),
            .aw_valid_o_2(uart_aw_valid),
            
            
            //写数据通道
            .w_ready_i_2(uart_w_ready),
            .w_data_o_2(uart_w_data),
            .w_strb_o_2(uart_w_strb),
            .w_valid_o_2(uart_w_valid),
            

            //写回应通道
            .b_resp_i_2(uart_b_resp),
            .b_valid_i_2(uart_b_valid),
            .b_ready_o_2(uart_b_ready),

            //读地址通道
            .ar_ready_i_2(uart_ar_ready),
            .ar_addr_o_2(uart_ar_addr),  
            .ar_valid_o_2(uart_ar_valid),
            

            //读数据通道
            .r_data_i_2(uart_r_data),
            .r_valid_i_2(uart_r_valid),
            .r_resp_i_2(uart_r_resp),
            .r_ready_o_2(uart_r_ready)
    );
   
    sram sram_i(
        .clk(clk),
        .rst(rst),
        //写地址通道
        .aw_addr_i(sram_aw_addr),
        .aw_valid_i(sram_aw_valid),
        .aw_ready_o(sram_aw_ready),
        
        //写数据通道
        .w_data_i(sram_w_data),
        .w_strb_i(sram_w_strb),
        .w_valid_i(sram_w_valid),
        .w_ready_o(sram_w_ready),

        //写回应通道
        .b_resp_o(sram_b_resp),
        .b_valid_o(sram_b_valid),
        .b_ready_i(sram_b_ready),

        //读地址通道
        .ar_addr_i(sram_ar_addr),  
        .ar_valid_i(sram_ar_valid),
        .ar_ready_o(sram_ar_ready),

        //读数据通道
        .r_ready_i(sram_r_ready),
        .r_data_o(sram_r_data),
        .r_valid_o(sram_r_valid),
        .r_resp_o(sram_r_resp)
    );



endmodule