`timescale 1ns / 1ps
`include "config.v"


module control(
    input  wire[6:0]   opcode,
    output reg         regwr,
    output reg[3:0]    aluop,
    output reg[1:0]    wr_mux,
    output reg[1:0]    alusrc1,
    output reg         alusrc2,
    output reg         branch,
    output reg         wen,
    output reg         ren,
    output reg         dnpc_mux
);

    always@(*) begin
        case(opcode) 
            7'b0110011: begin//R类型指令
                aluop=4'b0000;
                regwr=1;
                wr_mux=2'b00;
                alusrc1=2'b00;
                alusrc2=0;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
            7'b0110111: begin//lui指令
                aluop=4'b0001;
                regwr=1;
                wr_mux=2'b01;
                alusrc1=2'b00;
                alusrc2=0;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
            7'b0010111: begin//auipc指令
                aluop=4'b0010;
                regwr=1;
                wr_mux=2'b00;
                alusrc1=2'b10;
                alusrc2=1;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
            7'b1101111: begin//jal指令
                aluop=4'b0011;
                regwr=1;
                wr_mux=2'b10;
                alusrc1=2'b00;
                alusrc2=0;
                branch=1;
                wen=0;
                ren=0;
                dnpc_mux=1;
            end
            7'b1100111: begin//jalr指令
                aluop=4'b0100;
                regwr=1;
                wr_mux=2'b10;
                alusrc1=2'b00;
                alusrc2=1;
                branch=1;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
            7'b1100011: begin//B类型指令
                aluop=4'b0101;
                regwr=0;
                wr_mux=2'b00;
                alusrc1=2'b00;
                alusrc2=0;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=1;
            end
            7'b0000011: begin//I类型的访存指令
                aluop=4'b0110;
                regwr=1;
                wr_mux=2'b11;
                alusrc1=2'b00;
                alusrc2=1;
                branch=0;
                wen=0;
                ren=1;
                dnpc_mux=0;
            end
            7'b0100011: begin //S类型指令
                aluop=4'b0111;
                regwr=0;
                wr_mux=2'b00;
                alusrc1=2'b00;
                alusrc2=1;
                branch=0;
                wen=1;
                ren=0;
                dnpc_mux=0;
            end
            7'b0010011: begin //I类型的立即数指令
                aluop=4'b1000;
                regwr=1;
                wr_mux=2'b00;
                alusrc1=2'b00;
                alusrc2=1;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
            default: begin
                aluop=4'b0000;
                regwr=0;
                wr_mux=2'b00;
                alusrc1=2'b00;
                alusrc2=0;
                branch=0;
                wen=0;
                ren=0;
                dnpc_mux=0;
            end
        endcase
    
    end
endmodule
