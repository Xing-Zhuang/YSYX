`include "define.v"

module ifu(

    input   wire clk,
    input   wire rst,
    
    input   wire                       stall_i,

    //from exu
    input   wire                       jmp_i,
    input   wire[`REG_WIDTH-1:0]       jmp_pc_i,

    //to idu
    output  wire[`REG_WIDTH-1:0]       instr_o,
    output  wire[`REG_WIDTH-1:0]       pc_o,

    //写地址通道
    input   wire                       aw_ready_i,
    output  wire[`REG_WIDTH-1:0]       aw_addr_o,
    output  wire                       aw_valid_o,
    
    //写数据通道
    input   wire                       w_ready_i,
    output  wire[`REG_WIDTH-1:0]       w_data_o,
    output  wire[`REG_WIDTH/8-1:0]     w_strb_o,
    output  wire                       w_valid_o,
    

    //写回应通道
    input   wire[`AXI_RESP_WIDTH-1:0]  b_resp_i,
    input   wire                       b_valid_i,
    output  wire                       b_ready_o,

    //读地址通道
    input   wire                       ar_ready_i,
    output  reg[`REG_WIDTH-1:0]        ar_addr_pc_o, //PC地址
    output  reg                        ar_valid_o,


    //读数据通道
    input   wire                       r_valid_i,
    input   wire[`REG_WIDTH-1:0]       r_data_inst_i,//读取的指令
    input   wire[`AXI_RESP_WIDTH-1:0]  r_resp_i,
    output  reg                        r_ready_o,
    

    //仲裁请求信号
    output  reg                        req_o
    
);
    import "DPI-C" context function void disassemble_ifu(int pc, int instr);

    wire rst_n=!rst;//AXI协议使用低电平复位
    reg[`REG_WIDTH-1:0]  instr_reg;//读取到的指令
    reg[`REG_WIDTH-1:0]  pc_reg;//读取到的指令对应的pc
    assign instr_o=instr_reg;
    assign pc_o=pc_reg;

    //写地址通道 
    assign aw_addr_o=0;
    assign aw_valid_o=0;

    //写数据通道 
    assign w_data_o=0;
    assign w_strb_o=0;
    assign w_valid_o=0;

    //写回应通道 
    assign b_ready_o=0;
    

//读地址通道 
    //ar_valid_o
    always @(posedge clk) begin
        if(!rst_n)
            ar_valid_o<=0;
        else 
            ar_valid_o<=1;
    end
    /*
        always @(posedge clk) begin
            if(!rst_n)
                ar_valid_o<=1;
            else if(ar_valid_o&&ar_ready_i) begin//When asserted, ARVALID must remain asserted until the rising clock edge after the Subordinate asserts the ARREADY signal.（//此时可以拉低不代表一定拉低）
                if(stall)
                    ar_valid_o<=0;
                else
                    ar_valid_o<=ar_valid_o;
            end
            else
                ar_valid_o<=ar_valid_o;
            end
    */
    
    //ar_addr_pc_o
    always @(posedge clk) begin
        if(!rst_n) 
            ar_addr_pc_o<=`PC_RST_VALUE;
        else if(stall_i)  
            ar_addr_pc_o<=ar_addr_pc_o;
        else if(jmp_i) 
            ar_addr_pc_o<=jmp_pc_i;
        else if(r_valid_i&&r_ready_o)  //AXI手册未规定读地址如何变化，根据模块功能自行判断，ifu模块中：当地址成功被从模块读取后，pc+4
            ar_addr_pc_o<=ar_addr_pc_o+4;
        else 
            ar_addr_pc_o<=ar_addr_pc_o;
    end

    

//读数据通道
    //r_ready_o
    always @(posedge clk) begin
        if(!rst_n)
            r_ready_o<=0;
        else 
            r_ready_o<=1;
    end
    /*
        always @(posedge clk) begin
            if(!rst_n)
                r_ready_o<=1;//The default state of RREADY can be HIGH, but only if the Manager is able to accept read data immediately when it starts a read transaction.
            else if(stall)
                r_ready_o<=0;
            else
                r_ready_o<=1;
        end
    */

    
//instr_reg 接收读取的指令
    always @(posedge clk) begin
        if(!rst_n)
            instr_reg<=`NOP;
        else if(stall_i)
            instr_reg<=instr_reg;
        else if(jmp_i) 
            instr_reg<=`NOP;
        else if(r_valid_i&&r_ready_o) begin
            instr_reg<=r_data_inst_i;
            disassemble_ifu(ar_addr_pc_o,r_data_inst_i);
        end
        else
            instr_reg<=`NOP; //oldversion : instr_reg<=instr_reg
    end

//pc_reg
    always @(posedge clk) begin 
        if(!rst_n)
            pc_reg<=0;
        else if(stall_i)
            pc_reg<=pc_reg;
        else if(jmp_i) 
            pc_reg<=0;
        else if(r_valid_i&&r_ready_o)
            pc_reg<=ar_addr_pc_o;
        else
            pc_reg<=0;
    end

//req信号
    always @(posedge clk) begin
        if(!rst_n)
            req_o<=0;
        else if(stall_i)
            req_o<=0;
        else 
            req_o<=1; 
    end


endmodule