module sext(
    input   wire[11:0] in,
    output  wire[31:0] out 
);
    //12位符号扩展为32位

    assign out=in[11]==0?({20'b0,in}):({20'b11111111111111111111,in});

endmodule;
