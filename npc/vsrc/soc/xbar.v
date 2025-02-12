`include "define.v"
module xbar(
       
//master 1   接IFU
        input   wire                      req1_i,
        //写地址通道
        input   wire[`REG_WIDTH-1:0]      aw_addr_i_1,  
        input   wire                      aw_valid_i_1,
        output  wire                      aw_ready_o_1,  
        
        //写数据通道
        input   wire[`REG_WIDTH-1:0]      w_data_i_1,
        input   wire[`REG_WIDTH/8-1:0]    w_strb_i_1,
        input   wire                      w_valid_i_1,  
        output  wire                      w_ready_o_1,

        //写回应通道
        input  wire                       b_ready_i_1,
        output wire[`AXI_RESP_WIDTH-1:0]  b_resp_o_1,
        output wire                       b_valid_o_1,
        
        
        //读地址通道
        input   wire[`REG_WIDTH-1:0]      ar_addr_i_1,    
        input   wire                      ar_valid_i_1,
        output  wire                      ar_ready_o_1,  

        //读数据通道
        input   wire                      r_ready_i_1,
        output  wire[`REG_WIDTH-1:0]      r_data_o_1,
        output  wire                      r_valid_o_1,
        output  wire[`AXI_RESP_WIDTH-1:0] r_resp_o_1, 

//master 2   接lsu
        input   wire                       req2_i,
        //写地址通道
        input   wire[`REG_WIDTH-1:0]       aw_addr_i_2,
        input   wire                       aw_valid_i_2, 
        output  wire                       aw_ready_o_2,
        
        //写数据通道
        input   wire[`REG_WIDTH-1:0]       w_data_i_2,
        input   wire[`REG_WIDTH/8-1:0]     w_strb_i_2,
        input   wire                       w_valid_i_2,
        output  wire                       w_ready_o_2,

        //写回应通道
        input  wire                        b_ready_i_2,
        output wire[`AXI_RESP_WIDTH-1:0]   b_resp_o_2,
        output wire                        b_valid_o_2,
        
        
        //读地址通道
        input   wire[`REG_WIDTH-1:0]       ar_addr_i_2,    
        input   wire                       ar_valid_i_2,
        output  wire                       ar_ready_o_2,

        //读数据通道
        input   wire                       r_ready_i_2,
        output  wire[`REG_WIDTH-1:0]       r_data_o_2,
        output  wire                       r_valid_o_2,
        output  wire[`AXI_RESP_WIDTH-1:0]  r_resp_o_2,

//subordinate1
        //写地址通道
        input  wire                        aw_ready_i_1,
        output wire[`REG_WIDTH-1:0]        aw_addr_o_1,
        output wire                        aw_valid_o_1,
        
        
        //写数据通道
        input  wire                         w_ready_i_1,
        output wire[`REG_WIDTH-1:0]         w_data_o_1,
        output wire[`REG_WIDTH/8-1:0]       w_strb_o_1,
        output wire                         w_valid_o_1,
        

        //写回应通道
        input   wire[`AXI_RESP_WIDTH-1:0]   b_resp_i_1,
        input   wire                        b_valid_i_1,
        output  wire                        b_ready_o_1,

        //读地址通道
        input  wire                         ar_ready_i_1,
        output wire[`REG_WIDTH-1:0]         ar_addr_o_1,  
        output wire                         ar_valid_o_1,
        

        //读数据通道
        input   wire[`REG_WIDTH-1:0]        r_data_i_1,
        input   wire                        r_valid_i_1,
        input   wire[`AXI_RESP_WIDTH-1:0]   r_resp_i_1,
        output  wire                        r_ready_o_1,

//subordinate2
        //写地址通道
        input  wire                        aw_ready_i_2,
        output wire[`REG_WIDTH-1:0]        aw_addr_o_2,
        output wire                        aw_valid_o_2,
        
        
        //写数据通道
        input  wire                         w_ready_i_2,
        output wire[`REG_WIDTH-1:0]         w_data_o_2,
        output wire[`REG_WIDTH/8-1:0]       w_strb_o_2,
        output wire                         w_valid_o_2,
        

        //写回应通道
        input   wire[`AXI_RESP_WIDTH-1:0]   b_resp_i_2,
        input   wire                        b_valid_i_2,
        output  wire                        b_ready_o_2,

        //读地址通道
        input  wire                         ar_ready_i_2,
        output wire[`REG_WIDTH-1:0]         ar_addr_o_2,  
        output wire                         ar_valid_o_2,
        

        //读数据通道
        input   wire[`REG_WIDTH-1:0]        r_data_i_2,
        input   wire                        r_valid_i_2,
        input   wire[`AXI_RESP_WIDTH-1:0]   r_resp_i_2,
        output  wire                        r_ready_o_2
);


    reg[3:0] grant;//当前授权的master      用于m_arbiter中选择信号流向
    reg[3:0] sel_w;//subordinate写选择信号 用于s_arbiter中选择写信号流向(写地址 写数据 写响应)
    reg[3:0] sel_r;//subordinate读选择信号 用于s_arbiter中选择读信号流向(读地址 读数据)
    wire[`REG_WIDTH-1:0]       aw_addr;
    wire                       aw_valid;  
    wire                       aw_ready;  
     
    wire[`REG_WIDTH-1:0]       w_data;
    wire[`REG_WIDTH/8-1:0]     w_strb;
    wire                       w_valid;
    wire                       w_ready;
 
    wire                       b_ready;
    wire[`AXI_RESP_WIDTH-1:0]  b_resp;   
    wire                       b_valid;  
         
    wire[`REG_WIDTH-1:0]       ar_addr;   
    wire                       ar_valid;
    wire                       ar_ready;

    wire                       r_ready;
    wire[`REG_WIDTH-1:0]       r_data;
    wire                       r_valid;
    wire[`AXI_RESP_WIDTH-1:0]  r_resp;




    m_arbiter m_arbiter_i(
      .grant(grant), 
      //master1
      .aw_addr_i_1(aw_addr_i_1),  
      .aw_valid_i_1(aw_valid_i_1),
      .aw_ready_o_1(aw_ready_o_1),  
    
      .w_data_i_1(w_data_i_1),
      .w_strb_i_1(w_strb_i_1),
      .w_valid_i_1(w_valid_i_1),
      .w_ready_o_1(w_ready_o_1),

      .b_ready_i_1(b_ready_i_1),
      .b_resp_o_1(b_resp_o_1),
      .b_valid_o_1(b_valid_o_1),
    
      .ar_addr_i_1(ar_addr_i_1),    
      .ar_valid_i_1(ar_valid_i_1),
      .ar_ready_o_1(ar_ready_o_1),  

      .r_ready_i_1(r_ready_i_1),
      .r_data_o_1(r_data_o_1),
      .r_valid_o_1(r_valid_o_1),
      .r_resp_o_1(r_resp_o_1), 
    
      //master2
      .aw_addr_i_2(aw_addr_i_2),
      .aw_valid_i_2(aw_valid_i_2), 
      .aw_ready_o_2(aw_ready_o_2),
    
      .w_data_i_2(w_data_i_2),
      .w_strb_i_2(w_strb_i_2),
      .w_valid_i_2(w_valid_i_2),
      .w_ready_o_2(w_ready_o_2),

      .b_ready_i_2(b_ready_i_2),
      .b_resp_o_2(b_resp_o_2),
      .b_valid_o_2(b_valid_o_2),
    
    
      .ar_addr_i_2(ar_addr_i_2),    
      .ar_valid_i_2(ar_valid_i_2),
      .ar_ready_o_2(ar_ready_o_2),

      .r_ready_i_2(r_ready_i_2),
      .r_data_o_2(r_data_o_2),
      .r_valid_o_2(r_valid_o_2),
      .r_resp_o_2(r_resp_o_2),

      //仲裁输出/输入
      .aw_ready_i(aw_ready),
      .aw_addr_o(aw_addr),
      .aw_valid_o(aw_valid),
        
      .w_ready_i(w_ready),
      .w_data_o(w_data),
      .w_strb_o(w_strb),
      .w_valid_o(w_valid),
    
      .b_resp_i(b_resp),
      .b_valid_i(b_valid),
      .b_ready_o(b_ready),

      .ar_ready_i(ar_ready),
      .ar_addr_o(ar_addr),  
      .ar_valid_o(ar_valid),
    
      .r_data_i(r_data),
      .r_valid_i(r_valid),
      .r_resp_i(r_resp),
      .r_ready_o(r_ready)
    );

    s_arbiter s_arbiter_i(
      .sel_w(sel_w),
      .sel_r(sel_r),

      //subordinate1
      .aw_ready_i_1(aw_ready_i_1),
      .aw_addr_o_1(aw_addr_o_1),
      .aw_valid_o_1(aw_valid_o_1),
    
    
      .w_ready_i_1(w_ready_i_1),
      .w_data_o_1(w_data_o_1),
      .w_strb_o_1(w_strb_o_1),
      .w_valid_o_1(w_valid_o_1),
       
      .b_resp_i_1(b_resp_i_1),
      .b_valid_i_1(b_valid_i_1),
      .b_ready_o_1(b_ready_o_1),
   
      .ar_ready_i_1(ar_ready_i_1),
      .ar_addr_o_1(ar_addr_o_1),  
      .ar_valid_o_1(ar_valid_o_1),
      
      .r_data_i_1(r_data_i_1),
      .r_valid_i_1(r_valid_i_1),
      .r_resp_i_1(r_resp_i_1),
      .r_ready_o_1(r_ready_o_1),
  
      //subordinate2 
      .aw_ready_i_2(aw_ready_i_2),
      .aw_addr_o_2(aw_addr_o_2),
      .aw_valid_o_2(aw_valid_o_2),  
      
      .w_ready_i_2(w_ready_i_2),
      .w_data_o_2(w_data_o_2),
      .w_strb_o_2(w_strb_o_2),
      .w_valid_o_2(w_valid_o_2),
      
      .b_resp_i_2(b_resp_i_2),
      .b_valid_i_2(b_valid_i_2),
      .b_ready_o_2(b_ready_o_2),
  
      .ar_ready_i_2(ar_ready_i_2),
      .ar_addr_o_2(ar_addr_o_2),  
      .ar_valid_o_2(ar_valid_o_2),
      
      .r_data_i_2(r_data_i_2),
      .r_valid_i_2(r_valid_i_2),
      .r_resp_i_2(r_resp_i_2),
      .r_ready_o_2(r_ready_o_2),
  
  
      //仲裁输入/输出 
      .aw_addr_i(aw_addr),  
      .aw_valid_i(aw_valid),
      .aw_ready_o(aw_ready),  
       
       
      .w_data_i(w_data),
      .w_strb_i(w_strb),
      .w_valid_i(w_valid),
      .w_ready_o(w_ready),
  
       
      .b_ready_i(b_ready),
      .b_resp_o(b_resp),
      .b_valid_o(b_valid),
       
       
       
      .ar_addr_i(ar_addr),    
      .ar_valid_i(ar_valid),
      .ar_ready_o(ar_ready),  
  
       
      .r_ready_i(r_ready),
      .r_data_o(r_data),
      .r_valid_o(r_valid),
      .r_resp_o(r_resp)
    );

    //grant
    always @(req1_i or req2_i) begin
        if(req2_i) //一定要先判断req2_i
          grant<=4'b0010;
        else if(req1_i)
          grant<=4'b0001;
        else 
          grant<=4'b0000;
    end

    /* verilator lint_off UNSIGNED */
    //sel_w
    always @(aw_valid or aw_addr) begin
        if(aw_valid) begin
            if(aw_addr>=`ADDR_SLAVE1_LEFT&&aw_addr<`ADDR_SLAVE1_RIGHT)
                sel_w=4'b0001;
            else if(aw_addr>=`ADDR_SLAVE2_LEFT&& aw_addr<`ADDR_SLAVE2_RIGHT)
                sel_w=4'b0010;
            else 
                sel_w=4'b0000;
        end
        else  
            sel_w=sel_w;
    end
     
    
    //sel_r
    always @(ar_valid or ar_addr) begin
        if(ar_valid) begin
            if(ar_addr>=`ADDR_SLAVE1_LEFT&&ar_addr<`ADDR_SLAVE1_RIGHT)
                sel_r=4'b0001;
            else if(ar_addr>=`ADDR_SLAVE2_LEFT&&ar_addr<`ADDR_SLAVE2_RIGHT)
                sel_r=4'b0010;
            else
                sel_r=4'b0000;            
        end
        else  begin
            sel_r=sel_r;
        end
    end
    /* verilator lint_off UNSIGNED */


  
    

endmodule