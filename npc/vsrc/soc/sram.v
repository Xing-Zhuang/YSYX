`include "define.v"
module sram(
    input wire clk,
    input wire rst,

    //写地址通道
    input   wire[`REG_WIDTH-1:0]     aw_addr_i,
    input   wire                     aw_valid_i,
    output  reg                      aw_ready_o,
    
    //写数据通道
    input   wire[`REG_WIDTH-1:0]     w_data_i,
    input   wire[`REG_WIDTH/8-1:0]   w_strb_i,
    input   wire                     w_valid_i,
    output  reg                      w_ready_o,

    //写回应通道
    output reg[`AXI_RESP_WIDTH-1:0]  b_resp_o,
    output reg                       b_valid_o,
    input  wire                      b_ready_i,

    //读地址通道
    input   wire[`REG_WIDTH-1:0]     ar_addr_i,  
    input   wire                     ar_valid_i,
    output  reg                      ar_ready_o,

    //读数据通道
    input   wire                      r_ready_i,
    output  reg[`REG_WIDTH-1:0]       r_data_o,
    output  reg                       r_valid_o,
    output  reg[`AXI_RESP_WIDTH-1:0]  r_resp_o//忽略此信号

);
     
    wire rst_n=!rst;//AXI协议使用低电平复位
   // reg[`REG_WIDTH-1:0]     r_addr;//接收读地址
    reg[`REG_WIDTH-1:0]     w_addr;//接收写地址.
    reg[`REG_WIDTH-1:0]     r_data;//读取到的数据
   // reg[`REG_WIDTH-1:0]  _ram[0:4095];

    import "DPI-C" function int pmem_read(int raddr);
    import "DPI-C" function void pmem_write(int waddr,int wdata,int wmask);
    always@(ar_addr_i) begin
        r_data=pmem_read({ar_addr_i[31:2],2'b0});
    end

    
    always@(w_valid_i) begin
        if(w_valid_i) 
            pmem_write({aw_addr_i[31:2],2'b0},w_data_i,{28'b0,w_strb_i});
    end

//写地址通道 TODO
    assign aw_ready_o=1;



//写数据通道 TODO
    assign w_ready_o=1;


//写回应通道 TODO
    //b_valid_o
    always@(posedge clk) begin
        if(!rst_n) begin
            b_valid_o<=0;
        end
        else if(w_valid_i&&w_ready_o) begin //目前能保证在写数据有效的当前周期内就完成写数据
            b_valid_o<=1;
        end
        else 
            b_valid_o<=0;
    end



//读地址通道
    //ar_ready_o
    assign ar_ready_o=1;
    

    //ar_addr_i
    /*
    always @(posedge clk) begin
        if(!rst_n)
            r_addr<=0;
        else if(ar_valid_i&&ar_ready_o)
            r_addr<=ar_addr_i;
        else 
            r_addr<=r_addr;
    end*/
    
//读数据通道
    //r_data_o
    assign r_data_o=r_data;
    /*
    always @(posedge clk) begin
        if(!rst_n)
            r_data_o<=r_data;
        else 
            r_data_o<=r_data;
    end
    */
    
    //r_valid_o
    always @(posedge clk) begin
        if(!rst_n)
            r_valid_o<=0;
        else if(ar_valid_i&&ar_ready_o)
            r_valid_o<=1;
        else 
            r_valid_o<=0;
    end
     
     
  
    
     
  

endmodule