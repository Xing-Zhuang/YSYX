`include "define.v"
module Xriscv(
    output  reg[31:0] debug_regs[31:0],

    input   wire clk,
    input   wire rst,

//ifu AXI信号
    //写地址通道
    input   wire                       ifu_aw_ready_i,
    output  wire[`REG_WIDTH-1:0]       ifu_aw_addr_o,
    output  wire                       ifu_aw_valid_o,
    
    //写数据通道
    input   wire                       ifu_w_ready_i,
    output  wire[`REG_WIDTH-1:0]       ifu_w_data_o,
    output  wire[`REG_WIDTH/8-1:0]     ifu_w_strb_o,
    output  wire                       ifu_w_valid_o,
    

    //写回应通道
    input   wire[`AXI_RESP_WIDTH-1:0]  ifu_b_resp_i,
    input   wire                       ifu_b_valid_i,
    output  wire                       ifu_b_ready_o,

    //读地址通道
    input   wire                       ifu_ar_ready_i,
    output  wire[`REG_WIDTH-1:0]       ifu_ar_addr_pc_o, //PC地址
    output  wire                       ifu_ar_valid_o,


    //读数据通道
    input   wire                       ifu_r_valid_i,
    input   wire[`REG_WIDTH-1:0]       ifu_r_data_inst_i,//读取的指令
    input   wire[`AXI_RESP_WIDTH-1:0]  ifu_r_resp_i,
    output  wire                       ifu_r_ready_o,
    

    //申请总线请求信号
    output  wire                       ifu_req_o,

//lsu AXI信号
    //写地址通道
    input   wire                       lsu_aw_ready_i,
    output  wire[`REG_WIDTH-1:0]       lsu_aw_addr_o,
    output  wire                       lsu_aw_valid_o,
    
    //写数据通道
    input   wire                       lsu_w_ready_i,
    output  wire[`REG_WIDTH-1:0]       lsu_w_data_o,
    output  wire[`REG_WIDTH/8-1:0]     lsu_w_strb_o,
    output  wire                       lsu_w_valid_o,
    

    //写回应通道
    input   wire[`AXI_RESP_WIDTH-1:0]  lsu_b_resp_i,
    input   wire                       lsu_b_valid_i,
    output  wire                       lsu_b_ready_o,

    //读地址通道
    input   wire                       lsu_ar_ready_i,
    output  wire[`REG_WIDTH-1:0]       lsu_ar_addr_o,  
    output  wire                       lsu_ar_valid_o,


    //读数据通道
    input   wire                       lsu_r_valid_i,
    input   wire[`REG_WIDTH-1:0]       lsu_r_data_i, 
    input   wire[`AXI_RESP_WIDTH-1:0]  lsu_r_resp_i,
    output  wire                       lsu_r_ready_o,
    

    //申请总线请求信号
    output  wire                       lsu_req_o

);
    
    
    wire jump;
    wire[`REG_WIDTH-1:0] jump_pc;

    //gpr.v => idu.v
    wire[`GPR_ADDR_WIDTH-1:0] rd_addr1; 
    wire[`GPR_ADDR_WIDTH-1:0] rd_addr2;
    wire[`GPR_ADDR_WIDTH-1:0] wr_addr;
    wire[`REG_WIDTH-1:0] wr_data;
    wire                 wen;
    wire[`REG_WIDTH-1:0] gpr_data1; 
    wire[`REG_WIDTH-1:0] gpr_data2;


    //ifu.v => ifu_idu_reg.v
    wire[`REG_WIDTH-1:0] ifu_instr;//从ifu输出的instr
    wire[`REG_WIDTH-1:0] ifu_pc;//从ifu输出的pc

    //ifu_idu_reg.v => idu.v
    wire[`REG_WIDTH-1:0] ifu_idu_reg_instr;//从ifu_idu_reg输出的instr
    wire[`REG_WIDTH-1:0] ifu_idu_reg_pc; //从ifu_idu_reg输出的pc

    //idu.v => idu_exu_reg.v
    wire[`REG_WIDTH-1:0]       idu_instr;
    wire[`REG_WIDTH-1:0]       idu_op_data1;
    wire[`REG_WIDTH-1:0]       idu_op_data2; 
    wire[`REG_WIDTH-1:0]       idu_op_data3;
    wire[`REG_WIDTH-1:0]       idu_op_data4; 
    wire                       idu_wr_en;    
    wire[`GPR_ADDR_WIDTH-1:0]  idu_wr_addr;
    wire[`REG_WIDTH-1:0]       idu_debug_pc;   
    

    //idu_exu_reg.v => exu.v
    wire[`REG_WIDTH-1:0]       idu_exu_reg_instr;
    wire[`REG_WIDTH-1:0]       idu_exu_reg_op_data1;
    wire[`REG_WIDTH-1:0]       idu_exu_reg_op_data2; 
    wire[`REG_WIDTH-1:0]       idu_exu_reg_op_data3;
    wire[`REG_WIDTH-1:0]       idu_exu_reg_op_data4; 
    wire                       idu_exu_reg_wr_en;    
    wire[`GPR_ADDR_WIDTH-1:0]  idu_exu_reg_wr_addr;  
    wire[`REG_WIDTH-1:0]       idu_exu_reg_debug_pc; 
    

    //exu.v => ifu.v  
    wire exu_jmp;
    wire[`REG_WIDTH-1:0] exu_jmp_pc;
    //exu.v => ifu_idu_reg.v   idu_exu_reg.v  
    wire exu_flush;
    wire exu_stall;
    //exu.v => lsu.v
    wire[1:0] exu_flag;
    wire[`REG_WIDTH-1:0]  exu_addr;
    wire[`REG_WIDTH/8-1:0] exu_mem_mask;
    wire[`REG_WIDTH-1:0] exu_mem_data;

    //lsu.v to exu.v
    wire lsu_success;
    wire[`REG_WIDTH-1:0] lsu_mem_rdata;
     
     

    gpr gpr_i(
        .clk(clk),
        .rst(rst),

        .rd_addr1_i(rd_addr1),
        .rd_addr2_i(rd_addr2),
        .wr_addr_i(wr_addr),
        .wr_data_i(wr_data),
        .wen_i(wen),

        .data1_o(gpr_data1),
        .data2_o(gpr_data2),
        .debug_regs(debug_regs)
    );

    ifu ifu_i(

        .clk(clk),
        .rst(rst),
        
        .stall_i(exu_stall),

        //from exu
        .jmp_i(exu_jmp),
        .jmp_pc_i(exu_jmp_pc),

        //to idu
        .instr_o(ifu_instr),
        .pc_o(ifu_pc),

        //写地址通道
        .aw_ready_i(ifu_aw_ready_i),
        .aw_addr_o(ifu_aw_addr_o),
        .aw_valid_o(ifu_aw_valid_o),
        
        //写数据通道
        .w_ready_i(ifu_w_ready_i),
        .w_data_o(ifu_w_data_o),
        .w_strb_o(ifu_w_strb_o),
        .w_valid_o(ifu_w_valid_o),
        

        //写回应通道
        .b_resp_i(ifu_b_resp_i),
        .b_valid_i(ifu_b_valid_i),
        .b_ready_o(ifu_b_ready_o),

        //读地址通道
        .ar_ready_i(ifu_ar_ready_i),
        .ar_addr_pc_o(ifu_ar_addr_pc_o), //PC地址
        .ar_valid_o(ifu_ar_valid_o),


        //读数据通道
        .r_valid_i(ifu_r_valid_i),
        .r_data_inst_i(ifu_r_data_inst_i),//读取的指令
        .r_resp_i(ifu_r_resp_i),
        .r_ready_o(ifu_r_ready_o),
        

        //仲裁请求信号
        .req_o(ifu_req_o)
    );

    ifu_idu_reg ifu_idu_reg_i(
        .clk(clk),
        .rst(rst),
        
        //from exu
        .flush_i(exu_flush),
        .stall_i(exu_stall),

        //from ifu
        .instr_i(ifu_instr),
        .pc_i(ifu_pc),

        //to idu
        .instr_o(ifu_idu_reg_instr),
        .pc_o(ifu_idu_reg_pc)
    );

    idu idu_i(
        //from ifu_idu_reg
        .instr_i(ifu_idu_reg_instr),
        .pc_i(ifu_idu_reg_pc),
    
        //from gpr
        .reg_data1_i(gpr_data1),
        .reg_data2_i(gpr_data2),
        

        //to exu
        .instr_o(idu_instr),
        .op_data1_o(idu_op_data1),  //操作数1
        .op_data2_o(idu_op_data2),  //操作数2
        .op_data3_o(idu_op_data3),  //操作数3
        .op_data4_o(idu_op_data4),  //操作数4
        .wr_en_o(idu_wr_en),        //写gpr使能信号
        .wr_addr_o(idu_wr_addr),    //写gpr地址
        

        //to gpr
        .rd_addr1_o(rd_addr1),  //gpr读地址1
        .rd_addr2_o(rd_addr2),  //gpr读地址2

        .debug_pc_o(idu_debug_pc)
    );

    idu_exu_reg idu_exu_reg_i(
        .clk(clk),
        .rst(rst),
        
        .debug_pc_i(idu_debug_pc),

        //from exu
        .flush_i(exu_flush),
        .stall_i(exu_stall),
        
        //from idu
        .instr_i(idu_instr),
        .op_data1_i(idu_op_data1),   
        .op_data2_i(idu_op_data2),  
        .op_data3_i(idu_op_data3),   
        .op_data4_i(idu_op_data4), 
        .wr_en_i(idu_wr_en),         
        .wr_addr_i(idu_wr_addr),    


        //to exu
        .instr_o(idu_exu_reg_instr),
        .op_data1_o(idu_exu_reg_op_data1),   
        .op_data2_o(idu_exu_reg_op_data2),  
        .op_data3_o(idu_exu_reg_op_data3),   
        .op_data4_o(idu_exu_reg_op_data4),  
        .wr_en_o(idu_exu_reg_wr_en),     
        .wr_addr_o(idu_exu_reg_wr_addr),

        .debug_pc_o(idu_exu_reg_debug_pc)
    );

    exu exu_i(
        .debug_pc_i(idu_exu_reg_debug_pc),

        //from idu_exu
        .instr_i(idu_exu_reg_instr),
        .op_data1_i(idu_exu_reg_op_data1),   
        .op_data2_i(idu_exu_reg_op_data2), 
        .op_data3_i(idu_exu_reg_op_data3),   
        .op_data4_i(idu_exu_reg_op_data4), 
        .wr_en_i(idu_exu_reg_wr_en),         
        .wr_addr_i(idu_exu_reg_wr_addr),     
        
        //to gpr
        .wr_reg_en_o(wen),
        .wr_reg_data_o(wr_data),
        .wr_reg_addr_o(wr_addr),

        //to ifu
        .jmp_o(exu_jmp),
        .jmp_pc_o(exu_jmp_pc),

        //to ifu_idu_reg & idu_exu_reg
        .flush_o(exu_flush),
        .stall_o(exu_stall),


        //to lsu
        .flag_o(exu_flag),                  
        .addr_o(exu_addr),                  
        .wr_mem_mask_o(exu_mem_mask),       
        .wr_mem_data_o(exu_mem_data),       

        //from lsu
        .success_i(lsu_success),
        .mem_rdata_i(lsu_mem_rdata)
    );


    lsu lsu_i(
        .clk(clk),
        .rst(rst),

        //写地址通道
        .aw_ready_i(lsu_aw_ready_i),
        .aw_addr_o(lsu_aw_addr_o),
        .aw_valid_o(lsu_aw_valid_o),
        
        //写数据通道
        .w_ready_i(lsu_w_ready_i),
        .w_data_o(lsu_w_data_o),
        .w_strb_o(lsu_w_strb_o),
        .w_valid_o(lsu_w_valid_o),
        

        //写回应通道
        .b_resp_i(lsu_b_resp_i),
        .b_valid_i(lsu_b_valid_i),
        .b_ready_o(lsu_b_ready_o),

        //读地址通道
        .ar_ready_i(lsu_ar_ready_i),
        .ar_addr_o(lsu_ar_addr_o),  
        .ar_valid_o(lsu_ar_valid_o),


        //读数据通道
        .r_valid_i(lsu_r_valid_i),
        .r_data_i(lsu_r_data_i), 
        .r_resp_i(lsu_r_resp_i),
        .r_ready_o(lsu_r_ready_o),
        

        //仲裁请求信号
        .req_o(lsu_req_o),
 
        //from exu
        .flag_i(exu_flag), 
        .addr_i(exu_addr), 
        .wr_mem_mask_i(exu_mem_mask), 
        .wr_mem_data_i(exu_mem_data), 

        //to exu
        .success_o(lsu_success),     
        .mem_rdata_o(lsu_mem_rdata)  
    );

    

endmodule