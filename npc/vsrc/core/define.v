`define REG_WIDTH 32
`define PC_RST_VALUE 32'h80000000
`define NOP 0
`define GPR_ADDR_WIDTH 5
//resp信号
`define AXI_RESP_WIDTH 2
`define AXI_RESP_OKAY 2'b00
`define AXI_RESP_ERROR 2'b11

//地址范围
`define ADDR_SLAVE1_LEFT  32'h0000_0000
`define ADDR_SLAVE1_RIGHT 32'h80ff_ffff
`define ADDR_SLAVE2_LEFT  32'h1000_0000
`define ADDR_SLAVE2_RIGHT 32'h1000_0fff

 


//RV32I 若只有OPCODE表示单个OPCODE就能定位某个指令 
//lui  
`define OPCODE_U1  7'b0110111
//auipc
`define OPCODE_U2  7'b0010111
//jal
`define OPCODE_J1  7'b1101111
//jalr
`define OPCODE_I1  7'b1100111
//BEQ BNE BLT BGE BLTU BGEU
`define OPCODE_B1  7'b1100011
`define FUNC3_BEQ  3'b000
`define FUNC3_BNE  3'b001
`define FUNC3_BLT  3'b100
`define FUNC3_BGE  3'b101
`define FUNC3_BLTU 3'b110
`define FUNC3_BGEU 3'b111
//LB LH LW LBU LHU
`define OPCODE_I2  7'b0000011
`define FUNC3_LB   3'b000
`define FUNC3_LH   3'b001
`define FUNC3_LW   3'b010
`define FUNC3_LBU  3'b100
`define FUNC3_LHU  3'b101
//SB SH SW
`define OPCODE_S1  7'b0100011
`define FUNC3_SB   3'b000
`define FUNC3_SH   3'b001
`define FUNC3_SW   3'b010
//ADDI SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI
`define OPCODE_I3    7'b0010011
`define FUNC3_ADDI   3'b000
`define FUNC3_SLTI   3'b010
`define FUNC3_SLTIU  3'b011
`define FUNC3_XORI   3'b100
`define FUNC3_ORI    3'b110
`define FUNC3_ANDI   3'b111
`define FUNC3_SLLI   3'b001
`define FUNC3_SRI    3'b101
//ADD SUB SLL SLT SLTU XOR SRL SRA OR AND 
`define OPCODE_R1     7'b0110011
`define FUNC3_ADD     3'b000
`define FUNC7_ADD     7'b0000000
`define FUNC3_SUB     3'b000
`define FUNC7_SUB     7'b0100000
`define FUNC3_SLL     3'b001
`define FUNC7_SLL     7'b0000000
`define FUNC3_SLT     3'b010
`define FUNC7_SLT     7'b0000000
`define FUNC3_SLTU    3'b011
`define FUNC7_SLTU    7'b0000000
`define FUNC3_XOR     3'b100
`define FUNC7_XOR     7'b0000000
`define FUNC3_SRL     3'b101
`define FUNC7_SRL     7'b0000000
`define FUNC3_SRA     3'b101
`define FUNC7_SRA     7'b0100000
`define FUNC3_OR      3'b110
`define FUNC7_OR      7'b0000000
`define FUNC3_AND     3'b111
`define FUNC7_AND     7'b0000000
//FENCE FENCE.I
`define OPCODE_I4     7'b0001111
`define FUNC3_FENCE   3'b000
`define FUNC3_FENCE_I 3'b001
//ECALL EBREAK CSRRW CSRRS CSRRC CSRRWI CSRRSI CSRRCI
`define OPCODE_I5     7'b1110011
`define FUNC3_CSRRW   3'b001
`define FUNC3_CSRRS   3'b010
`define FUNC3_CSRRC   3'b011
`define FUNC3_CSRRWI  3'b101
`define FUNC3_CSRRSI  3'b110
`define FUNC3_CSRRCI  3'b111
`define ECALL         32'h73
`define EBREAK        32'h00100073