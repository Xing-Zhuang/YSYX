`include "define.v"
module ifu_idu_reg(
    input wire clk,
    input wire rst,

    //from exu
    input wire flush_i,
    input wire stall_i,

    //from ifu
    input  wire[`REG_WIDTH-1:0] instr_i,
    input  wire[`REG_WIDTH-1:0] pc_i,

    //to idu
    output wire[`REG_WIDTH-1:0] instr_o,
    output wire[`REG_WIDTH-1:0] pc_o
);
    reg[`REG_WIDTH-1:0] instr_reg;
    reg[`REG_WIDTH-1:0] pc;

    always @(posedge clk) begin
        if(rst) begin
            instr_reg<=0;
            pc<=0;
        end
        else if(stall_i) begin
            instr_reg<=instr_reg;
            pc<=pc;
        end
        else if(flush_i) begin
            instr_reg<=0;
            pc<=0;
        end
        else begin
            instr_reg<=instr_i;
            pc<=pc_i;
        end
    end

    assign instr_o=instr_reg;
    assign pc_o=pc;


endmodule