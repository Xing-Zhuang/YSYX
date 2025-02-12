`include "define.v"
module lsu(
    input wire clk,
    input wire rst,

    //写地址通道
    input   wire                       aw_ready_i,
    output  reg[`REG_WIDTH-1:0]        aw_addr_o,
    output  reg                        aw_valid_o,
    
    //写数据通道
    input   wire                       w_ready_i,
    output  wire[`REG_WIDTH-1:0]       w_data_o,
    output  wire[`REG_WIDTH/8-1:0]     w_strb_o,
    output  wire                       w_valid_o,
    

    //写回应通道
    input   wire[`AXI_RESP_WIDTH-1:0]  b_resp_i,
    input   wire                       b_valid_i,
    output  wire                       b_ready_o,  

    //读地址通道
    input   wire                       ar_ready_i,
    output  reg[`REG_WIDTH-1:0]        ar_addr_o,  
    output  reg                        ar_valid_o,


    //读数据通道
    input   wire                       r_valid_i,     
    input   wire[`REG_WIDTH-1:0]       r_data_i, 
    input   wire[`AXI_RESP_WIDTH-1:0]  r_resp_i,
    output  reg                        r_ready_o,
    

    //仲裁请求信号
    output  reg                        req_o,



    //from exu
    input wire[1:0]                    flag_i,//00无请求 01读请求 10写请求
    input wire[`REG_WIDTH-1:0]         addr_i,//读或写地址
    input wire[`REG_WIDTH/8-1:0]       wr_mem_mask_i,//写掩码（若为写，标记写哪个字节的数据）
    input wire[`REG_WIDTH-1:0]         wr_mem_data_i,//写数据（若为写）

    //to exu
    output wire                        success_o,//lsu完成读或写信号
    output wire[`REG_WIDTH-1:0]        mem_rdata_o//lsu读取的数据（若为读）
);

//仲裁请求信号
    always@(posedge clk) begin
        if(rst) begin
            req_o<=0;
        end
        else if(flag_i==2'b01)begin
            req_o<=1;
        end
        else if(flag_i==2'b10)begin
            req_o<=1;
        end
        else begin
            req_o<=0;
        end
    end

//读地址通道
    //ar_valid_o
    always@(posedge clk) begin
        if(rst) begin
            ar_valid_o<=0;
        end
        else if(flag_i==2'b01)begin
            ar_valid_o<=1;
        end
        else if(flag_i==2'b10)begin
            ar_valid_o<=0;
        end
        else begin
            ar_valid_o<=0;
        end
    end

    //ar_addr_o
    always@(posedge clk) begin
        if(rst) begin
            ar_addr_o<=0;
        end
        else if(flag_i==2'b01)begin
            ar_addr_o<=addr_i;
        end
        else if(flag_i==2'b10)begin
            ar_addr_o<=0;
        end
        else begin
            ar_addr_o<=0;
        end
    end

//读数据通道
    //r_ready_o
    assign r_ready_o=1;


//写地址通道 
    //aw_valid_o
    always@(posedge clk) begin
        if(rst) begin
            aw_valid_o<=0;
        end
        else if(flag_i==2'b01)begin
            aw_valid_o<=0;
        end
        else if(flag_i==2'b10)begin
            aw_valid_o<=1;
        end
        else begin
            aw_valid_o<=0;
        end
    end

    //aw_addr_o
    always@(posedge clk) begin
        if(rst) begin
            aw_addr_o<=0;
        end
        else if(flag_i==2'b01)begin
            aw_addr_o<=0;
        end
        else if(flag_i==2'b10)begin
            aw_addr_o<=addr_i;
        end
        else begin
            aw_addr_o<=0;
        end
    end

//写数据通道
    //w_valid_o
    always@(posedge clk) begin
        if(rst) begin
            w_valid_o<=0;
        end
        else if(flag_i==2'b01)begin
            w_valid_o<=0;
        end
        else if(flag_i==2'b10)begin
            w_valid_o<=1;
        end
        else begin
            w_valid_o<=0;
        end
    end

    //w_data_o
    always@(posedge clk) begin
        if(rst) begin
            w_data_o<=0;
        end
        else if(flag_i==2'b01)begin
            w_data_o<=0;
        end
        else if(flag_i==2'b10)begin
            w_data_o<=wr_mem_data_i;
        end
        else begin
            w_data_o<=0;
        end
    end

    //w_strb_o
    always@(posedge clk) begin
        if(rst) begin
            w_strb_o<=0;
        end
        else if(flag_i==2'b01)begin
            w_strb_o<=0;
        end
        else if(flag_i==2'b10)begin
            w_strb_o<=wr_mem_mask_i;
        end
        else begin
            w_strb_o<=0;
        end
    end

//写回应通道
    //b_ready_o
    assign b_ready_o=1;


//mem_rdata_o
    always@(posedge clk) begin
        if(rst) begin
            mem_rdata_o<=0;
        end
        else if(flag_i==2'b01)begin
            if(r_valid_i&&r_ready_o)  
                mem_rdata_o<=r_data_i;
            else 
                mem_rdata_o<=0;        
        end
        else if(flag_i==2'b10)begin
            mem_rdata_o<=0;
        end
        else begin
            mem_rdata_o<=0;
        end
    end


//success_o
    always@(posedge clk) begin
        if(rst) begin
            success_o<=0;
        end
        else if(flag_i==2'b01)begin
            if(r_valid_i&&r_ready_o)
                success_o<=1;
            else 
                success_o<=0;        
        end
        else if(flag_i==2'b10)begin
            if(b_valid_i&&b_ready_o)  
                success_o<=1;
            else 
                success_o<=0; 
        end
        else begin
            success_o<=0;
        end
    end


 


endmodule