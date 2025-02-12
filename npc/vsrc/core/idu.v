`include "define.v"
module idu(
    
    //from ifu_idu_reg
    input  wire[`REG_WIDTH-1:0]      instr_i,
    input  wire[`REG_WIDTH-1:0]      pc_i,
    
    //from gpr
    input  wire[`REG_WIDTH-1:0]       reg_data1_i,
    input  wire[`REG_WIDTH-1:0]       reg_data2_i,
    

    //to exu
    output wire[`REG_WIDTH-1:0]      instr_o,
    output reg[`REG_WIDTH-1:0]       op_data1_o,  //操作数1
    output reg[`REG_WIDTH-1:0]       op_data2_o,  //操作数2
    output reg[`REG_WIDTH-1:0]       op_data3_o,  //操作数3   
    output reg[`REG_WIDTH-1:0]       op_data4_o,  //操作数4  有些指令的操作性比较多，比如jalr就需要3个操作数  beq需要4个操作数
    output reg                       wr_en_o,     //写gpr使能信号
    output reg[`GPR_ADDR_WIDTH-1:0]  wr_addr_o,   //写gpr地址
     

    //to gpr
    output reg[`GPR_ADDR_WIDTH-1:0]  rd_addr1_o, //gpr读地址1
    output reg[`GPR_ADDR_WIDTH-1:0]  rd_addr2_o,  //gpr读地址2

    output reg[`REG_WIDTH-1:0]       debug_pc_o
    
);
    import "DPI-C" context function void disassemble_idu(int pc, int instr);
  

    wire[6:0] opcode = instr_i[6:0];
    wire[2:0] func3  = instr_i[14:12];
    wire[6:0] func7  = instr_i[31:25];
    wire[4:0] rd     = instr_i[11:7];
    wire[4:0] rs1    = instr_i[19:15];
    wire[4:0] rs2    = instr_i[24:20];
    
    assign instr_o=instr_i;
    assign debug_pc_o=pc_i;
    
    always@(instr_i) begin
      disassemble_idu(pc_i,instr_i);
    end

    
    //译码 组合逻辑
    always@(*) begin
        case(opcode)
            `OPCODE_U1: begin //lui 
                rd_addr1_o=0;  //gpr读地址1
                rd_addr2_o=0;  //gpr读地址2
                op_data1_o = {instr_i[31:12], 12'b0};//操作数1
                op_data2_o = 0;//操作数2
                op_data3_o = 0;//操作数3
                op_data4_o = 0;//操作数4
                wr_en_o = 1; //写gpr使能信号
                wr_addr_o = rd; //写gpr地址             
            end
            `OPCODE_U2: begin //auipc
                rd_addr1_o=0;   
                rd_addr2_o=0;   
                op_data1_o = pc_i; 
                op_data2_o = {instr_i[31:12], 12'b0};
                op_data3_o = 0;
                op_data4_o = 0;
                wr_en_o = 1; 
                wr_addr_o = rd;   
            end
            `OPCODE_J1:begin//jal
                rd_addr1_o=0;   
                rd_addr2_o=0;
                op_data1_o = pc_i;
                op_data2_o = {{(`REG_WIDTH - 21){instr_i[31]}},{instr_i[31],instr_i[19:12],instr_i[20],instr_i[30:21],1'b0}};
                op_data3_o = 0;
                op_data4_o = 0;
                wr_en_o = 1; 
                wr_addr_o = rd;   
            end
            `OPCODE_I1:begin//jalr
                rd_addr1_o = rs1;  
                rd_addr2_o = 0;
                op_data1_o = pc_i;
                op_data2_o = { {(`REG_WIDTH - 12){instr_i[31]}} ,instr_i[31:20]};
                op_data3_o = reg_data1_i;
                op_data4_o = 0;
                wr_en_o = 1; 
                wr_addr_o = rd;
            end
            `OPCODE_B1:begin//BEQ BNE BLT BGE BLTU BGEU
                rd_addr1_o = rs1;
                rd_addr2_o = rs2;
                op_data1_o = reg_data1_i;
                op_data2_o = reg_data2_i;
                op_data3_o = pc_i;
                op_data4_o = {{(`REG_WIDTH - 13){instr_i[31]}},{instr_i[31],instr_i[7],instr_i[30:25],instr_i[11:8],1'b0}};
                wr_en_o = 0;
                wr_addr_o = 0;                  
            end
            `OPCODE_I2:begin//LB LH LW LBU LHU
                rd_addr1_o = rs1;
                rd_addr2_o = 0;
                op_data1_o = reg_data1_i;
                op_data2_o = { {(`REG_WIDTH - 12){instr_i[31]}} ,instr_i[31:20]};
                op_data3_o = 0;
                op_data4_o = 0;
                wr_en_o = 1;
                wr_addr_o = rd;                 
            end
            `OPCODE_S1:begin//SB SH SW
                rd_addr1_o = rs1;
                rd_addr2_o = rs2;
                op_data1_o = reg_data1_i;
                op_data2_o = reg_data2_i;
                op_data3_o ={{(`REG_WIDTH - 12){instr_i[31]}},{instr_i[31:25],instr_i[11:7]}};
                op_data4_o = 0;  
                wr_en_o = 0;
                wr_addr_o = 0;    
            end 
            `OPCODE_I3:begin//ADDI SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI
                rd_addr1_o = rs1;
                rd_addr2_o = 0;
                op_data1_o = reg_data1_i;
                op_data2_o = { {(`REG_WIDTH - 12){instr_i[31]}} ,instr_i[31:20]};
                op_data3_o = 0;
                op_data4_o = 0;
                wr_en_o = 1;
                wr_addr_o = rd;        
            end 
            `OPCODE_R1:begin  //ADD SUB SLL SLT SLTU XOR SRL SRA OR AND
               case({func7,func3}) 
                   {`FUNC7_ADD,`FUNC3_ADD},{`FUNC7_SUB,`FUNC3_SUB},{`FUNC7_SLL,`FUNC3_SLL},{`FUNC7_SLT,`FUNC3_SLT},{`FUNC7_SLTU,`FUNC3_SLTU},{`FUNC7_XOR,`FUNC3_XOR},{`FUNC7_SRL,`FUNC3_SRL},{`FUNC7_SRA,`FUNC3_SRA},{`FUNC7_OR,`FUNC3_OR},{`FUNC7_AND,`FUNC3_AND}:begin
                        rd_addr1_o = rs1;  
                        rd_addr2_o = rs2;  
                        op_data1_o = reg_data1_i;
                        op_data2_o = reg_data2_i;
                        op_data3_o = 0;
                        op_data4_o = 0;
                        wr_en_o = 1;
                        wr_addr_o = rd;
                   end
               default:begin
                
               end
               endcase
            end
            `OPCODE_I4:begin

            end
            `OPCODE_I5:begin

            end
            default:begin
                
            end
        endcase

        
    end

endmodule