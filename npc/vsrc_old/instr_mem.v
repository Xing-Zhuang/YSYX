`include "config.v"
module instr_mem(
    input wire[`REG_WIDTH-1:0] raddr,
    
    output reg[`REG_WIDTH-1:0] instr
);  

    import "DPI-C" function int pmem_read(int raddr);


    always@(*) begin
        instr=pmem_read(raddr);
    end

endmodule