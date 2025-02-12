module npc(
    input wire clk,
    input wire rst,
    input wire[31:0] pc,
    output reg[31:0] snpc
);
    assign snpc=pc+4;
   
    

endmodule