`include "define.v"
module s_arbiter(
    input   wire[3:0]                  sel_w,//0000谁都不选 0001选master1 0010选master2
    input   wire[3:0]                  sel_r,
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
    output  wire                        r_ready_o_2,


//仲裁输入/输出
    //写地址通道
    input   wire[`REG_WIDTH-1:0]      aw_addr_i,  
    input   wire                      aw_valid_i,
    output  wire                      aw_ready_o,  
    
    //写数据通道
    input   wire[`REG_WIDTH-1:0]      w_data_i,
    input   wire[`REG_WIDTH/8-1:0]    w_strb_i,
    input   wire                      w_valid_i,
    output  wire                      w_ready_o,

    //写回应通道
    input  wire                       b_ready_i,
    output wire[`AXI_RESP_WIDTH-1:0]  b_resp_o,
    output wire                       b_valid_o,
    
    
    //读地址通道
    input   wire[`REG_WIDTH-1:0]      ar_addr_i,    
    input   wire                      ar_valid_i,
    output  wire                      ar_ready_o,  

    //读数据通道
    input   wire                      r_ready_i,
    output  wire[`REG_WIDTH-1:0]      r_data_o,
    output  wire                      r_valid_o,
    output  wire[`AXI_RESP_WIDTH-1:0] r_resp_o
);

//写地址通道
    assign aw_addr_o_1= (sel_w==4'b0001)?aw_addr_i:0;
    assign aw_addr_o_2= (sel_w==4'b0010)?aw_addr_i:0;

    assign aw_valid_o_1= (sel_w==4'b0001)?aw_valid_i:0;
    assign aw_valid_o_2= (sel_w==4'b0010)?aw_valid_i:0;


    MuxKeyWithDefault #(2, 4, 1) m1(//parameter：查询表项数 key的位宽 value的位宽
     aw_ready_o,//输出端口
     sel_w,//key     
     1'b0,  
     {//查询表
        4'b0001,aw_ready_i_1,
        4'b0010,aw_ready_i_2 
     }
    ); 

//写数据通道
    assign w_data_o_1= (sel_w==4'b0001)?w_data_i:0;
    assign w_data_o_2= (sel_w==4'b0010)?w_data_i:0; 

    assign w_strb_o_1= (sel_w==4'b0001)?w_strb_i:0;
    assign w_strb_o_2= (sel_w==4'b0010)?w_strb_i:0; 

    assign w_valid_o_1= (sel_w==4'b0001)?w_valid_i:0;
    assign w_valid_o_2= (sel_w==4'b0010)?w_valid_i:0; 

    
    
    MuxKeyWithDefault #(2, 4, 1) m2(//parameter：查询表项数 key的位宽 value的位宽
     w_ready_o,//输出端口
     sel_w,//key     
     1'b0,  
     {//查询表
        4'b0001,w_ready_i_1,
        4'b0010,w_ready_i_2 
     }
    ); 

//写回应通道
    assign b_ready_o_1= (sel_w==4'b0001)?b_ready_i:0;
    assign b_ready_o_2= (sel_w==4'b0010)?b_ready_i:0; 

    
    MuxKeyWithDefault #(2, 4, `AXI_RESP_WIDTH) m3(//parameter：查询表项数 key的位宽 value的位宽
     b_resp_o,//输出端口
     sel_w,//key     
     2'b0,  
     {//查询表
        4'b0001,b_resp_i_1,
        4'b0010,b_resp_i_2 
     }
    ); 

    MuxKeyWithDefault #(2, 4, 1) m4(//parameter：查询表项数 key的位宽 value的位宽
     b_valid_o,//输出端口
     sel_w,//key     
     1'b0,  
     {//查询表
        4'b0001,b_valid_i_1,
        4'b0010,b_valid_i_2 
     }
    ); 

//读地址通道
    assign ar_addr_o_1= (sel_r==4'b0001)?ar_addr_i:0;
    assign ar_addr_o_2= (sel_r==4'b0010)?ar_addr_i:0; 

    assign ar_valid_o_1= (sel_r==4'b0001)?ar_valid_i:0;
    assign ar_valid_o_2= (sel_r==4'b0010)?ar_valid_i:0; 

    MuxKeyWithDefault #(2, 4, 1) m5(//parameter：查询表项数 key的位宽 value的位宽
     ar_ready_o,//输出端口
     sel_r,//key     
     1'b0,  
     {//查询表
        4'b0001,ar_ready_i_1,
        4'b0010,ar_ready_i_2 
     }
    ); 

//读数据通道
    assign r_ready_o_1= (sel_r==4'b0001)?r_ready_i:0;
    assign r_ready_o_2= (sel_r==4'b0010)?r_ready_i:0;
    
    MuxKeyWithDefault #(2, 4, `REG_WIDTH) m6(//parameter：查询表项数 key的位宽 value的位宽
     r_data_o,//输出端口
     sel_r,//key     
     0,  
     {//查询表
        4'b0001,r_data_i_1,
        4'b0010,r_data_i_2 
     }
    ); 

    MuxKeyWithDefault #(2, 4, 1) m7(//parameter：查询表项数 key的位宽 value的位宽
     r_valid_o,//输出端口
     sel_r,//key     
     1'b0,  
     {//查询表
        4'b0001,r_valid_i_1,
        4'b0010,r_valid_i_2 
     }
    ); 

    MuxKeyWithDefault #(2, 4, `AXI_RESP_WIDTH) m8(//parameter：查询表项数 key的位宽 value的位宽
     r_resp_o,//输出端口
     sel_r,//key  
     2'b0,   
     {//查询表
        4'b0001,r_resp_i_1,
        4'b0010,r_resp_i_2 
     }
    ); 
 


    
endmodule