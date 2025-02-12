`timescale 1ns / 1ps
`include "config.v"

module imm_gen(
    input wire[`INST_WIDTH - 1:0] inst,
    
    output reg[`REG_WIDTH - 1:0] imm
);
   // reg[`IMM_TYPES_WIDTH - 1:0] imm_ctl=
    
    always@(*) begin
        if(inst[6:0]==7'b0110111||inst[6:0]==7'b0010111) begin//U型  lui  auipc
            imm={{(`REG_WIDTH - 20){inst[31]}},inst[31:12]}<<12;  
        end 
        else if(inst[6:0]==7'b1101111) begin//J型  jal
            imm= {{(`REG_WIDTH - 21){inst[31]}},{inst[31],inst[19:12],inst[20],inst[30:21],1'b0}};
        end 
        else if(inst[6:0]==7'b1100111||inst[6:0]==7'b0000011||inst[6:0]==7'b0010011) begin//I型   
             if({inst[31:25],inst[14:12]}==10'b0000000_001||{inst[31:25],inst[14:12]}==10'b0000000_101||{inst[31:25],inst[14:12]}==10'b0100000_101) begin// slli srli  srai
                imm={ {(`REG_WIDTH - 6){inst[25]}} ,inst[25:20]};
             end    
             else begin//jalr lb lh lw lbu lhu addi slti sltiu xori ori andi
                imm={ {(`REG_WIDTH - 12){inst[31]}} ,inst[31:20]};
             end
        end
        else if(inst[6:0]==7'b1100011) begin //B型
             imm= {{(`REG_WIDTH - 13){inst[31]}},{inst[31],inst[7],inst[30:25],inst[11:8],1'b0}};
        end   
        else if(inst[6:0]==7'b0100011) begin //S型
             imm= {{(`REG_WIDTH - 12){inst[31]}},{inst[31:25],inst[11:7]}};
        end  
        else begin
             imm=0;
        end
    end
endmodule
