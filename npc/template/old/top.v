
module top(
    input reg clk,
    input reg rst,

    input reg[31:0] inst,
    output reg[31:0] debug_pc
); 
    
    reg[31:0] snpc;      
    reg[31:0] pc;
    reg[2:0] ALUCon;
    reg RegWr;
    reg[31:0] y;
    reg[31:0] res; //ALU计算结果
    reg[31:0] x;

    assign debug_pc=pc;

    regfile #(5,32) ysyx_23060160_regfile(
        .clk(clk),
        .rst(rst),
        .A1(inst[19:15]),
        .A2(inst[11:7]),
        .WD2(res),
        .wen(RegWr),

        .RD1(y)
    );

    ALU ysyx_23060160_ALU(
       .x(x),
       .y(y),
    
       .res(res)
    );

    sext ysyx_23060160_sext(
        .in(inst[31:20]),

        .out(x)
    );

    PC ysyx_23060160_pc(
      .clk(clk),
      .rst(rst),
      .nextpc(snpc),

      .pc(pc)
    );

    npc ysyx_23060160_npc(
      .clk(clk),
      .rst(rst),
      .pc(pc),

      .snpc(snpc)
    );

    decoder ysyx_23060160_decoder(
      .inst(inst),
      .ALUCon(ALUCon),
      .RegWr(RegWr)
    );

  
   
 

endmodule

