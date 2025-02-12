//查找表lut项数  key宽度  value宽度
module MuxKeyWithDefault #(parameter NR_KEY = 2, parameter KEY_LEN = 1, parameter DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,//输出值
  input [KEY_LEN-1:0] key,//键
  input [DATA_LEN-1:0] default_out, //默认值输出
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut  //查找表
);
  MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 1) i0 (out, key, default_out, lut);
endmodule