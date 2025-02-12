module idu_exu_reg(
    input wire clk,
    input wire rst,

     
    //from exu
    input wire flush_i,
    input wire stall_i,

    //from idu
    input  wire[`REG_WIDTH-1:0]        debug_pc_i,
    input wire[`REG_WIDTH-1:0]         instr_i,     //指令
    input wire[`REG_WIDTH-1:0]         op_data1_i,  //操作数1
    input wire[`REG_WIDTH-1:0]         op_data2_i,  //操作数2
    input wire[`REG_WIDTH-1:0]         op_data3_i,  //操作数3
    input wire[`REG_WIDTH-1:0]         op_data4_i,  //操作数4
    input wire                         wr_en_i,     //写gpr使能信号
    input wire[`GPR_ADDR_WIDTH-1:0]    wr_addr_i,   //写gpr地址

    //to exu
    output wire[`REG_WIDTH-1:0]       instr_o,
    output wire[`REG_WIDTH-1:0]       op_data1_o,  
    output wire[`REG_WIDTH-1:0]       op_data2_o, 
    output wire[`REG_WIDTH-1:0]       op_data3_o,  
    output wire[`REG_WIDTH-1:0]       op_data4_o,  
    output wire                       wr_en_o,     
    output wire[`GPR_ADDR_WIDTH-1:0]  wr_addr_o,
    output wire[`REG_WIDTH-1:0]       debug_pc_o
);
     
    reg[`REG_WIDTH-1:0]       instr;
    reg[`REG_WIDTH-1:0]       op_data1;
    reg[`REG_WIDTH-1:0]       op_data2; 
    reg[`REG_WIDTH-1:0]       op_data3;
    reg[`REG_WIDTH-1:0]       op_data4;   
    reg                       wr_en;      
    reg[`GPR_ADDR_WIDTH-1:0]  wr_addr;
    reg[`REG_WIDTH-1:0]       debug_pc;

    assign  instr_o=instr;
    assign  op_data1_o=op_data1;
    assign  op_data2_o=op_data2;
    assign  op_data3_o=op_data3;
    assign  op_data4_o=op_data4;
    assign  wr_en_o=wr_en;
    assign  wr_addr_o=wr_addr;
    assign  debug_pc_o=debug_pc;

    always@(posedge clk) begin
        if(rst) begin
            instr<=0;
            op_data1<=0;
            op_data2<=0;
            op_data3<=0;
            op_data4<=0;
            wr_en<=0;
            wr_addr<=0;
            debug_pc<=0;
        end
        else if(stall_i) begin
            instr<=instr;
            op_data1<=op_data1;
            op_data2<=op_data2;
            op_data3<=op_data3;
            op_data4<=op_data4;
            wr_en<=wr_en;
            wr_addr<=wr_addr;
            debug_pc<=debug_pc;
        end
        else if(flush_i) begin
            instr<=0;
            op_data1<=0;
            op_data2<=0;
            op_data3<=0;
            op_data4<=0;
            wr_en<=0;
            wr_addr<=0;
            debug_pc<=0;
        end
        else begin
            instr<=instr_i;
            op_data1<=op_data1_i;
            op_data2<=op_data2_i;
            op_data3<=op_data3_i;
            op_data4<=op_data4_i;
            wr_en<=wr_en_i;
            wr_addr<=wr_addr_i;
            debug_pc<=debug_pc_i;
        end
    end



endmodule