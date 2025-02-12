`timescale 1ns / 1ps
 `include "config.v"

//verilog默认将操作数当成无符号数 加上$signed后可使其视为有符号数
//verilog>>和<<是逻辑移位  >>>和<<<是算术移位（使用算术移位时注意先用$signed将操作数变为有符号数)

module alu(
    input wire[`REG_WIDTH-1:0] x,
    input wire[`REG_WIDTH-1:0] y,
    input wire[`ALU_TYPES_WIDTH-1:0] alu_ctl,
    
    output reg[`REG_WIDTH-1:0] result,
    output reg conditbran
);
    
    always@(*) begin
        case(alu_ctl)
            `ALU_TYPES_WIDTH'b00000: begin//add
                result=x+y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00001: begin//sub
                result=x-y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00010: begin//sll
                result=x<<y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00011: begin//slt
                result = ($signed(x) < $signed(y)) ? 1 : 0;                
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00100: begin//sltu
                result = (x < y) ? 1 : 0;                
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00101: begin//xor
                result = x^y;    
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00110: begin//srl
                result=x>>y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b00111: begin//sra
                result=($signed(x))>>> y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b01000: begin//or
                result=x|y;
                conditbran=0;
            end
            `ALU_TYPES_WIDTH'b01001: begin//and
                result=x&y;
                conditbran=0;
            end
            
            `ALU_TYPES_WIDTH'b01010: begin//beq
                result=0;
                conditbran=(x==y)?1:0;
            end
            `ALU_TYPES_WIDTH'b01011: begin//bne
                result=0;
                conditbran=(x!=y)?1:0;
            end
            `ALU_TYPES_WIDTH'b01100: begin//blt
                result=0;
                conditbran=($signed(x)<$signed(y))?1:0;
            end
            `ALU_TYPES_WIDTH'b01101: begin//bge
                result=0;
                conditbran=($signed(x)>=$signed(y))?1:0;
            end
            `ALU_TYPES_WIDTH'b01110: begin//bltu
                result=0;
                conditbran=x<y?1:0;
            end
            `ALU_TYPES_WIDTH'b01111: begin//bgeu
                result=0;
                conditbran=(x>=y)?1:0;
            end
            
       
            default:begin 
                result=0;
                conditbran=0;
            end
        endcase
    end
    
 

endmodule
