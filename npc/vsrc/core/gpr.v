`include "define.v"
 module gpr (
  input wire clk,
  input wire rst,

  input wire [`GPR_ADDR_WIDTH-1:0] rd_addr1_i,
  input wire [`GPR_ADDR_WIDTH-1:0] rd_addr2_i,
  input wire [`GPR_ADDR_WIDTH-1:0] wr_addr_i,
  input wire [`REG_WIDTH-1:0]      wr_data_i,
  input wire wen_i,

  output reg [`REG_WIDTH-1:0] data1_o,
  output reg [`REG_WIDTH-1:0] data2_o,

  output reg[31:0] debug_regs[31:0]
);
  reg [`REG_WIDTH-1:0] regs [2**`GPR_ADDR_WIDTH-1:0]; 

  assign debug_regs=regs;

   

  //写
  always @(posedge clk) begin
    if(rst) begin
      for (integer i = 0; i < 2**`GPR_ADDR_WIDTH; i = i + 1) begin  
            regs[i] <= 0;  
      end  
    end
    else if(wen_i && wr_addr_i!=0) begin
      regs[wr_addr_i] <= wr_data_i;
      //
    end
  end


  //读端口1
  always@(*) begin
     if(wen_i && wr_addr_i==rd_addr1_i) begin
         data1_o = wr_data_i;
     end
     else begin
        data1_o = regs[rd_addr1_i];
     end
  end

  
  //读端口2
  always@(*) begin
     if(wen_i && wr_addr_i==rd_addr2_i) begin
         data2_o = wr_data_i;
     end
     else begin
        data2_o = regs[rd_addr2_i];
     end
  end

  

endmodule