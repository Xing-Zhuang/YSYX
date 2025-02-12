`timescale 1ns / 1ps
 `include "config.v"
 
module ifu(
    input wire clk,
    input wire rst,
    input wire[`REG_WIDTH-1:0] dnpc,
    input wire ifu_branch,
    
    
    output wire[`REG_WIDTH-1:0] pc,
    output wire[`REG_WIDTH-1:0] snpc,
    output wire[`REG_WIDTH-1:0] debug_npc
);

    reg[`REG_WIDTH-1:0] pc_reg;
     
    wire[`REG_WIDTH-1:0] npc;
    
    assign pc=pc_reg;
    assign snpc=pc_reg+4;
    assign debug_npc=npc;
    
    MuxKey #(2,1,`REG_WIDTH) mux2_1(
        npc,
        ifu_branch,
        { 
          1'b0,snpc,
          1'b1,dnpc
         }
    );
    
    always@(posedge clk) begin
        if(rst) begin
            pc_reg<=`REG_WIDTH'h80000000;
        end
        else begin
            pc_reg<=npc;
        end
    end
endmodule
