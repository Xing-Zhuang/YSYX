 module regfile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input rst,
  input [ADDR_WIDTH-1:0] A1,
  input [ADDR_WIDTH-1:0] A2,
  input [DATA_WIDTH-1:0] WD2,
  input wen,

  output wire [DATA_WIDTH-1:0] RD1
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0]; 
 

  always @(posedge clk) begin
    if(rst) begin
       rf[6]<=8;
    end
    else if(wen) rf[A2] <= WD2;
  end
  assign RD1=rf[A1];

endmodule