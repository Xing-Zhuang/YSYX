`timescale 1ns / 1ps
 `include "config.v"


module alu_control(
    input wire[3:0] aluop,
    input wire[9:0] funct,   
    output reg[`ALU_TYPES_WIDTH-1:0] alu_ctl 
);

    always@(*) begin
        case(aluop)
            4'b0000: begin
                case(funct)
                    10'b0000000_000: alu_ctl=`ALU_TYPES_WIDTH'b00000;
                    10'b0100000_000: alu_ctl=`ALU_TYPES_WIDTH'b00001;
                    10'b0000000_001: alu_ctl=`ALU_TYPES_WIDTH'b00010;
                    10'b0000000_010: alu_ctl=`ALU_TYPES_WIDTH'b00011;
                    10'b0000000_011: alu_ctl=`ALU_TYPES_WIDTH'b00100;
                    10'b0000000_100: alu_ctl=`ALU_TYPES_WIDTH'b00101;
                    10'b0000000_101: alu_ctl=`ALU_TYPES_WIDTH'b00110;
                    10'b0100000_101: alu_ctl=`ALU_TYPES_WIDTH'b00111;
                    10'b0000000_110: alu_ctl=`ALU_TYPES_WIDTH'b01000;
                    10'b0000000_111: alu_ctl=`ALU_TYPES_WIDTH'b01001;
                    default: alu_ctl=`ALU_TYPES_WIDTH'b00000;
                endcase
            end
            4'b0001: begin
                alu_ctl=`ALU_TYPES_WIDTH'b11111;
            end
            4'b0010: begin
                alu_ctl=`ALU_TYPES_WIDTH'b00000;
            end
            4'b0011: begin
                alu_ctl=`ALU_TYPES_WIDTH'b11111;
            end
            4'b0100: begin
                alu_ctl=`ALU_TYPES_WIDTH'b00000;
            end
            4'b0101: begin
                casez(funct)
                    10'b???????_000: alu_ctl=`ALU_TYPES_WIDTH'b01010;
                    10'b???????_001: alu_ctl=`ALU_TYPES_WIDTH'b01011;
                    10'b???????_100: alu_ctl=`ALU_TYPES_WIDTH'b01100;
                    10'b???????_101: alu_ctl=`ALU_TYPES_WIDTH'b01101;
                    10'b???????_110: alu_ctl=`ALU_TYPES_WIDTH'b01110;
                    10'b???????_111: alu_ctl=`ALU_TYPES_WIDTH'b01111;
                    default: alu_ctl=`ALU_TYPES_WIDTH'b00000;
                endcase
            end
            4'b0110: begin
                alu_ctl=`ALU_TYPES_WIDTH'b00000;
            end
            4'b0111: begin
                alu_ctl=`ALU_TYPES_WIDTH'b00000;
            end
            4'b1000: begin
                casez(funct)
                   10'b???????_000: alu_ctl=`ALU_TYPES_WIDTH'b00000;
                   10'b???????_010: alu_ctl=`ALU_TYPES_WIDTH'b00011;
                   10'b???????_011: alu_ctl=`ALU_TYPES_WIDTH'b00100;
                   10'b???????_100: alu_ctl=`ALU_TYPES_WIDTH'b00101;
                   10'b???????_110: alu_ctl=`ALU_TYPES_WIDTH'b01000;
                   10'b???????_111: alu_ctl=`ALU_TYPES_WIDTH'b01001;
                   10'b0000000_001: alu_ctl=`ALU_TYPES_WIDTH'b00010;      
                   10'b0000000_101: alu_ctl=`ALU_TYPES_WIDTH'b00110;
                   10'b0100000_101: alu_ctl=`ALU_TYPES_WIDTH'b00111;
                   default: alu_ctl=`ALU_TYPES_WIDTH'b00000;
                endcase
            end
            default: begin
                alu_ctl=`ALU_TYPES_WIDTH'b00000;
            end
        endcase
    
    end
endmodule
