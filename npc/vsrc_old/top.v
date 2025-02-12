`include "config.v"
//`include "MuxKey.v"
//`include "alu.v"
//`include "control.v"
//`include "imm_gen.v"
//`include "MuxKeyInternal.v"
//`include "alu_control.v"
//`include "data_mem.v"
//`include "instr_mem.v"
//`include "MuxKeyWithDefault.v"
//`include "ifu.v"
//`include "registers.v"
 

module top(
    input wire clk,
    input wire rst,

    output reg[31:0] debug_rf[2**5-1:0],
    output wire[`REG_WIDTH-1:0] debug_pc,
    output wire[`REG_WIDTH-1:0] debug_instr
);
   wire[`REG_WIDTH-1:0] pc;
   wire         regwr;
   wire[3:0]    aluop;
   wire[1:0]    wr_mux;
   wire[1:0]    alusrc1;
   wire         alusrc2;
   wire         branch;
   wire[`REG_WIDTH-1:0] wr_data;
   wire[`REG_WIDTH-1:0] data1;
   wire[`REG_WIDTH-1:0] data2;
   wire[`REG_WIDTH - 1:0] imm;
   wire[`ALU_TYPES_WIDTH-1:0] alu_ctl;
   wire[`REG_WIDTH - 1:0] src1;
   wire[`REG_WIDTH - 1:0] src2;
   wire[`REG_WIDTH-1:0] result;
   wire conditbran;
   wire[`REG_WIDTH - 1:0] snpc;
   wire[`REG_WIDTH-1:0] instr;
   wire  wen;
   wire  ren;
   wire  dnpc_mux;
   wire[`REG_WIDTH-1:0] data;
   wire[`REG_WIDTH-1:0]  debug_npc;
   wire[`REG_WIDTH-1:0]  dnpc;
   assign debug_pc=pc;
   assign debug_instr=instr;

   import "DPI-C" context function void STOP(); 
   import "DPI-C" context function void ftrace(int ftype,int fpc,int dnpc,int inst);

   //处理一些特殊情况 
   always @(negedge clk) begin
      //ebreak
      if(instr==32'b00000000_00010000_00000000_01110011) begin  
          STOP();
      end
      //jar
      if(instr[6:0]==7'b1101111) begin  
          ftrace(1,pc,debug_npc,instr);
      //jalr
      end
      if(instr[6:0]==7'b1100111&&instr[14:12]==3'b000) begin  
          ftrace(2,pc,debug_npc,instr);
      end
   end


  data_mem data_mem_i(
    .clk(clk),
    .ren(ren),
    .addr(result),
    .rw_type(instr[14:12]),//若wen有效则为写类型  若wen无效则为读类型
    .wen(wen),
    .wdata(data2),

    .data(data)
  );


   instr_mem instr_mem_i(
    .raddr(pc),
    .instr(instr)
   );

   control control_i(
    .opcode(instr[6:0]),
    .regwr(regwr),
    .aluop(aluop),
    .wr_mux(wr_mux),
    .alusrc1(alusrc1),
    .alusrc2(alusrc2),
    .branch(branch),
    .wen(wen),
    .ren(ren),
    .dnpc_mux(dnpc_mux)
   );

   registers #(`REG_NUM_WIDTH, `REG_WIDTH) registers_i(
      .clk(clk),
      .rst(rst),
      .rd1(instr[19:15]),
      .rd2(instr[24:20]),
      .wr(instr[11:7]),
      .wr_data(wr_data),
      .wen(regwr),
     
      .data1(data1),
      .data2(data2),
      .debug_rf(debug_rf)
    );
   
   imm_gen imm_gen_i(
     .inst(instr),

     .imm(imm)
   );
    

   alu_control alu_control_i(
    .aluop(aluop),
    .funct({instr[31:25],instr[14:12]}),   

    .alu_ctl(alu_ctl)
   );

                    //表项数  key位数  value位数
   MuxKeyWithDefault #(3, 2, `REG_WIDTH) mux1(
     src1,//选择的value
     alusrc1,//key  
     0, //默认值输出
     { //kv对应关系
        2'b00,data1,
        2'b01,imm,
        2'b10,pc
     }
  );

  MuxKey #(2, 1, `REG_WIDTH) mux2 (
    src2,  //值
    alusrc2,    //键
    {
        1'b0,data2,
        1'b1,imm
    }
  );
  
  alu alu_i(
    .x(src1),
    .y(src2),
    .alu_ctl(alu_ctl),
    
    .result(result),
    .conditbran(conditbran)
  );
    
  
   MuxKeyWithDefault #(4, 2, `REG_WIDTH) mux3(
     wr_data,
     wr_mux,
     0, //默认值输出
     {
        2'b00,result,
        2'b01,imm,
        2'b10,snpc,
        2'b11,data
     }
   );

   MuxKeyWithDefault #(2, 1, `REG_WIDTH) mux4(
     dnpc,
     dnpc_mux,
     0, //默认值输出
     {
        1'b0,result&(~1),
        1'b1,pc+imm
     }
   );


   ifu ifu_i(
    .clk(clk),
    .rst(rst),
    .dnpc(dnpc),
    .ifu_branch(branch|conditbran),
    
    .pc(pc),
    .snpc(snpc),
    .debug_npc(debug_npc)
   );

endmodule