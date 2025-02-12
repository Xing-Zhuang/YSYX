 module registers #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input rst,
  input [ADDR_WIDTH-1:0] rd1,
  input [ADDR_WIDTH-1:0] rd2,
  input [ADDR_WIDTH-1:0] wr,
  input [DATA_WIDTH-1:0] wr_data,
  input wen,

  output wire [DATA_WIDTH-1:0] data1,
  output wire [DATA_WIDTH-1:0] data2,
  output reg[31:0] debug_rf[2**5-1:0]
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0]; 
  
  
  assign debug_rf=rf;

  always @(posedge clk) begin
    if(rst) begin
      for (int i = 0; i < 2**ADDR_WIDTH; i = i + 1) begin  
            rf[i] <= 0;  
      end  
    end
    else if(wen&&wr!=0) begin
      rf[wr] <= wr_data;
    end
  end
  assign data1=rf[rd1];
  assign data2=rf[rd2];

endmodule