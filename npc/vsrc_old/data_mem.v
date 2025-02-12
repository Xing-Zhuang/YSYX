`include "config.v"
module data_mem(
    input wire ren,
    input wire clk,
    input wire[`REG_WIDTH-1:0] addr,
    input wire[2:0] rw_type,
    input wire wen,
    input wire[`REG_WIDTH-1:0] wdata,

    output reg[`REG_WIDTH-1:0] data
);

    import "DPI-C" function int pmem_read(int raddr);
    import "DPI-C" function void pmem_write(int waddr,int wdata,byte wmask);
    
    reg[`REG_WIDTH-1:0] data_reg;
     

    always@(posedge clk) begin
        if(wen) begin//写
            case(rw_type)  
                3'b000: begin //sb
                    pmem_write(addr,wdata,1);
                end
                3'b001: begin //sh
                    pmem_write(addr,wdata,2);
                end
                3'b010: begin //sw
                    pmem_write(addr,wdata,4);
                end
                default begin
                    pmem_write(addr,wdata,4);
                end
            endcase
        end
    end

    always@(*) begin
        if(ren) begin//读  
             data_reg=pmem_read(addr);
             case(rw_type)
                3'b000: begin //lb
                    data={{(`REG_WIDTH-8){data_reg[7]}},data_reg[7:0]};
                end
                3'b001: begin //lh
                    data={{(`REG_WIDTH-16){data_reg[15]}},data_reg[15:0]};
                end
                3'b010: begin //lw
                    data={{(`REG_WIDTH-32){data_reg[31]}},data_reg[31:0]};
                end
                3'b100: begin //lbu
                    data={{(`REG_WIDTH-8){1'b0}},data_reg[7:0]};
                end
                3'b101: begin //lhu
                    data={{(`REG_WIDTH-16){1'b0}},data_reg[15:0]};
                end
                default begin
                    data={{(`REG_WIDTH-32){data_reg[31]}},data_reg[31:0]};
                end
            endcase
        end
        else begin
            data_reg=0;
            data=0;
        end
    end

endmodule