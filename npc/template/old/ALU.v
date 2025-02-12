module ALU(
    input wire[31:0] x,
    input wire[31:0] y,
   // input wire[31:0] sel//选择操作
    output wire[31:0]  res
);

    assign res=x+y;//目前只实现加法

endmodule;