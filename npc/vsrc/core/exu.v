`include "define.v"
module exu(
     
    
   //from idu_exu
   input wire[`REG_WIDTH-1:0]       debug_pc_i,
   input wire[`REG_WIDTH-1:0]       instr_i,
   input wire[`REG_WIDTH-1:0]       op_data1_i,  //操作数1
   input wire[`REG_WIDTH-1:0]       op_data2_i,  //操作数2
   input wire[`REG_WIDTH-1:0]       op_data3_i,  //操作数3
   input wire[`REG_WIDTH-1:0]       op_data4_i,  //操作数4

   input wire                       wr_en_i,     //写gpr使能信号
   input wire[`GPR_ADDR_WIDTH-1:0]  wr_addr_i,   //写gpr地址
    
   //to gpr
   output reg                      wr_reg_en_o,
   output reg[`REG_WIDTH-1:0]      wr_reg_data_o,
   output reg[`GPR_ADDR_WIDTH-1:0] wr_reg_addr_o,

   //to ifu
   output wire                     jmp_o,
   output wire[`REG_WIDTH-1:0]     jmp_pc_o,
   
   //to ifu_idu_reg & idu_exu_reg
   output wire                     flush_o,
   output wire                     stall_o,

   //to lsu
   output wire[1:0]                 flag_o,//00无请求 01读请求 10写请求
   output wire[`REG_WIDTH-1:0]      addr_o,//读或写地址
   output wire[`REG_WIDTH/8-1:0]    wr_mem_mask_o,//写掩码（若为写，标记写哪个字节的数据）
   output wire[`REG_WIDTH-1:0]      wr_mem_data_o,//写数据（若为写）

   //from lsu
   input wire                       success_i,//lsu完成读或写信号
   input wire[`REG_WIDTH-1:0]       mem_rdata_i//lsu读数据（若为读）
    

);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   import "DPI-C" context function void STOP(int stop_type,int instr);
   import "DPI-C" context function void ftrace(int ftype,int fpc,int dnpc,int inst);
   import "DPI-C" context function void disassemble_exu(int pc, int instr); 
   import "DPI-C" context function void finish_one(int finish_pc,int is_store,int store_addr); 

   //处理一些特殊情况 
   always @(*) begin
       
      /*
      //jar
      if(instr_i[6:0]==7'b1101111) begin  
          ftrace(1,pc,debug_npc,instr_i);
      //jalr
      end
      if(instr_i[6:0]==7'b1100111&&instr_i[14:12]==3'b000) begin  
          ftrace(2,pc,debug_npc,instr_i);
      end*/
   end
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    wire[6:0] opcode = instr_i[6:0];
    wire[2:0] func3  = instr_i[14:12];
    wire[6:0] func7  = instr_i[31:25];
    /* verilator lint_off WIDTHTRUNC */
    wire[1:0] mem_rindex = (op_data1_i+op_data2_i)& `REG_WIDTH'h00000003;
    wire[1:0] mem_windex = (op_data1_i+op_data3_i)& `REG_WIDTH'h00000003;
    /* verilator lint_off WIDTHTRUNC */

    always@(instr_i) begin
      disassemble_exu(debug_pc_i,instr_i);
    end

    always@(*) begin
      if(instr_i!=`NOP) begin
       if(instr_i==32'b00000000_00010000_00000000_01110011) begin  
          STOP(1,0);
       end
       else begin
            case(opcode) 
                  `OPCODE_U1: begin //lui
                     wr_reg_en_o=wr_en_i;
                     wr_reg_data_o=op_data1_i;
                     wr_reg_addr_o=wr_addr_i;

                     flag_o=0;
                     addr_o=0;
                     wr_mem_data_o=0;
                     wr_mem_mask_o=0;

                     stall_o=0; 
                     jmp_o=0;
                     jmp_pc_o=0;
                     flush_o=0;
                     finish_one(debug_pc_i,0,0);//表示下一个clk上升沿到来时刻就完成一条指令
                  end
                  `OPCODE_U2: begin //auipc
                     wr_reg_en_o=wr_en_i;
                     wr_reg_data_o=op_data1_i+op_data2_i;
                     wr_reg_addr_o=wr_addr_i;

                     flag_o=0;
                     addr_o=0;
                     wr_mem_data_o=0;
                     wr_mem_mask_o=0;
                     
                     stall_o=0; 
                     jmp_o=0;
                     jmp_pc_o=0;
                     flush_o=0;
                     finish_one(debug_pc_i,0,0);;
                  end
                  `OPCODE_J1:begin//jal
                     wr_reg_en_o=wr_en_i;
                     wr_reg_data_o=op_data1_i+4;
                     wr_reg_addr_o=wr_addr_i;

                     flag_o=0;
                     addr_o=0;
                     wr_mem_data_o=0;
                     wr_mem_mask_o=0;
                     
                     stall_o=0; 
                     jmp_o=1;
                     jmp_pc_o=op_data1_i+op_data2_i;
                     flush_o=1;
                     finish_one(debug_pc_i,0,0);;
                  end
                  `OPCODE_I1:begin//jalr
                     wr_reg_en_o=wr_en_i;
                     wr_reg_data_o=op_data1_i+4;
                     wr_reg_addr_o=wr_addr_i;

                     flag_o=0;
                     addr_o=0;
                     wr_mem_data_o=0;
                     wr_mem_mask_o=0;
                     
                     stall_o=0; 
                     jmp_o=1;
                     jmp_pc_o=(op_data3_i+op_data2_i)&(~1);
                     flush_o=1;
                     finish_one(debug_pc_i,0,0);;
                  end
                  `OPCODE_B1:begin//BEQ BNE BLT BGE BLTU BGEU
                     finish_one(debug_pc_i,0,0);;
                     case(func3)
                        `FUNC3_BEQ:begin//BEQ 
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;

                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= (op_data1_i==op_data2_i)?1:0;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= (op_data1_i==op_data2_i)?1:0;
                        end
                        `FUNC3_BNE:begin//BNE 
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;

                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= (op_data1_i==op_data2_i)?0:1;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= (op_data1_i==op_data2_i)?0:1;
                        end
                        `FUNC3_BLT:begin//BLT 
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;

                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= ($signed(op_data1_i)<$signed(op_data2_i))?1:0;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= ($signed(op_data1_i)<$signed(op_data2_i))?1:0;
                        end
                        `FUNC3_BGE:begin//BGE 
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;
                           
                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= ($signed(op_data1_i)>=$signed(op_data2_i))?1:0;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= ($signed(op_data1_i)>=$signed(op_data2_i))?1:0;
                        end
                        `FUNC3_BLTU:begin//BLTU   
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;

                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= op_data1_i<op_data2_i;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= op_data1_i<op_data2_i;
                        end
                        `FUNC3_BGEU:begin//BGEU 
                           wr_reg_en_o=wr_en_i;
                           wr_reg_data_o=0;
                           wr_reg_addr_o=wr_addr_i;

                           flag_o=0;
                           addr_o=0;
                           wr_mem_data_o=0;
                           wr_mem_mask_o=0;
                     
                           stall_o=0; 
                           jmp_o= op_data1_i>=op_data2_i;
                           jmp_pc_o= op_data3_i+op_data4_i;
                           flush_o= op_data1_i>=op_data2_i; 
                        end
                        default:begin
                           STOP(2,instr_i);
                        end
                     endcase
                  end
                  `OPCODE_I2:begin//LB LH LW LBU LHU
                     //STOP(2,instr_i);
                     case(func3) 
                        `FUNC3_LB:begin//LB 
                              if(success_i) begin
                                 finish_one(debug_pc_i,1,op_data1_i+op_data2_i);
                                 wr_reg_en_o=wr_en_i;
                                 //wr_reg_data_o=mem_rdata_i;
                                 wr_reg_addr_o=wr_addr_i;
                                       
                                 flag_o=2'b00;
                                 addr_o=0;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=0; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                                 case(mem_rindex)  
                                    2'b00: begin
                                       wr_reg_data_o = {{24{mem_rdata_i[7]}}, mem_rdata_i[7:0]};
                                    end
                                    2'b01: begin
                                       wr_reg_data_o = {{24{mem_rdata_i[15]}}, mem_rdata_i[15:8]};
                                    end
                                    2'b10: begin
                                       wr_reg_data_o = {{24{mem_rdata_i[23]}}, mem_rdata_i[23:16]};
                                    end
                                    default: begin
                                       wr_reg_data_o = {{24{mem_rdata_i[31]}}, mem_rdata_i[31:24]};
                                    end
                                 endcase
                              end
                              else begin
                                 wr_reg_en_o=0;
                                 wr_reg_data_o=0;
                                 wr_reg_addr_o=0;
                                       
                                 flag_o=2'b01;
                                 addr_o=op_data1_i+op_data2_i;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=1; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                              end
                        end
                        `FUNC3_LH:begin//LH
                           if(success_i) begin
                                 finish_one(debug_pc_i,1,op_data1_i+op_data2_i);
                                 wr_reg_en_o=wr_en_i;
                                 //wr_reg_data_o=mem_rdata_i;
                                 wr_reg_addr_o=wr_addr_i;
                                       
                                 flag_o=2'b00;
                                 addr_o=0;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=0; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                                 
                                 if (mem_rindex == 2'b0) begin
                                    wr_reg_data_o = {{16{mem_rdata_i[15]}}, mem_rdata_i[15:0]};
                                 end else begin
                                    wr_reg_data_o = {{16{mem_rdata_i[31]}}, mem_rdata_i[31:16]};
                                 end
                              end
                              else begin
                                 wr_reg_en_o=0;
                                 wr_reg_data_o=0;
                                 wr_reg_addr_o=0;
                                       
                                 flag_o=2'b01;
                                 addr_o=op_data1_i+op_data2_i;
                                 wr_mem_data_o=0;

                                 stall_o=1; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                              end
                        end
                        `FUNC3_LW:begin//LW
                              if(success_i) begin
                                 finish_one(debug_pc_i,1,op_data1_i+op_data2_i);
                                 wr_reg_en_o=wr_en_i;
                                 wr_reg_data_o=mem_rdata_i;
                                 wr_reg_addr_o=wr_addr_i;
                                       
                                 flag_o=2'b00;
                                 addr_o=0;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=0; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                                 
                                
                                 wr_reg_data_o = mem_rdata_i[31:0];           
                                  
                              end
                              else begin
                                 wr_reg_en_o=0;
                                 wr_reg_data_o=0;
                                 wr_reg_addr_o=0;
                                       
                                 flag_o=2'b01;
                                 addr_o=op_data1_i+op_data2_i;
                                 wr_mem_data_o=0;

                                 stall_o=1; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                              end
                        end
                        `FUNC3_LBU:begin//LBU
                              if(success_i) begin
                                 finish_one(debug_pc_i,1,op_data1_i+op_data2_i);
                                 wr_reg_en_o=wr_en_i;
                                 //wr_reg_data_o=mem_rdata_i;
                                 wr_reg_addr_o=wr_addr_i;
                                       
                                 flag_o=2'b00;
                                 addr_o=0;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=0; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                                 
                                 case (mem_rindex)
                                    2'b00: begin
                                       wr_reg_data_o = {24'h0, mem_rdata_i[7:0]};
                                    end
                                    2'b01: begin
                                       wr_reg_data_o = {24'h0, mem_rdata_i[15:8]};
                                    end
                                    2'b10: begin
                                       wr_reg_data_o = {24'h0, mem_rdata_i[23:16]};
                                    end
                                    default: begin
                                       wr_reg_data_o = {24'h0, mem_rdata_i[31:24]};
                                    end
                                 endcase
                              end
                              else begin
                                 wr_reg_en_o=0;
                                 wr_reg_data_o=0;
                                 wr_reg_addr_o=0;
                                       
                                 flag_o=2'b01;
                                 addr_o=op_data1_i+op_data2_i;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=1; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                              end
                        end
                        `FUNC3_LHU:begin//LHU
                              if(success_i) begin
                                 finish_one(debug_pc_i,1,op_data1_i+op_data2_i);
                                 wr_reg_en_o=wr_en_i;
                                 //wr_reg_data_o=mem_rdata_i;
                                 wr_reg_addr_o=wr_addr_i;
                                       
                                 flag_o=2'b00;
                                 addr_o=0;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=0; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                                 
                                 if (mem_rindex == 2'b0) begin
                                    wr_reg_data_o = {16'h0, mem_rdata_i[15:0]};
                                 end else begin
                                    wr_reg_data_o = {16'h0, mem_rdata_i[31:16]};
                                 end
                              end
                              else begin
                                 wr_reg_en_o=0;
                                 wr_reg_data_o=0;
                                 wr_reg_addr_o=0;
                                       
                                 flag_o=2'b01;
                                 addr_o=op_data1_i+op_data2_i;
                                 wr_mem_data_o=0;
                                 wr_mem_mask_o=0;
                     
                                 stall_o=1; 
                                 jmp_o=0;
                                 jmp_pc_o=0;
                                 flush_o=0;
                              end
                        end
                        default:begin
                           STOP(2,instr_i);
                        end
                     endcase        
                  end
                  /* verilator lint_off WIDTHCONCAT */
                  `OPCODE_S1:begin//SB SH SW
                     //STOP(2,instr_i);
                     case(func3) 
                        `FUNC3_SB:begin
                           if(success_i) begin 
                              finish_one(debug_pc_i,1,op_data1_i+op_data3_i);
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b00;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=4'b0000;
                  
                              stall_o=0; 
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;
                           end
                           else begin
                              
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b10;
                              addr_o=op_data1_i+op_data3_i;
                              //wr_mem_data_o=op_data2_i;
                              case (mem_windex)
                                 2'b00: begin 
                                    wr_mem_data_o = {24'h0, op_data2_i[7:0]};
                                    wr_mem_mask_o = 4'b0001;
                                 end
                                 2'b01: begin
                                   
                                    wr_mem_data_o = {16'h0, op_data2_i[7:0],8'h0};
                                    wr_mem_mask_o = 4'b0010;
                                 end
                                 2'b10: begin
                                    wr_mem_data_o = {8'h0, op_data2_i[7:0], 16'h0};
                                    wr_mem_mask_o = 4'b0100;
                                 end
                                 default: begin
                                    wr_mem_data_o = {op_data2_i[7:0], 24'h0};
                                    wr_mem_mask_o = 4'b1000;
                                 end
                              endcase


                              stall_o=1; 
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;
                           end
                        end
                        `FUNC3_SH:begin
                           if(success_i) begin 
                              finish_one(debug_pc_i,2,op_data1_i+op_data3_i);
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b00;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=4'b0000;
                  
                              stall_o=0;
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;
                           end
                           else begin
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b10;
                              addr_o=op_data1_i+op_data3_i;
                              //wr_mem_data_o=op_data2_i;
                              //wr_mem_mask_o = 4'b1111;
                              if (mem_windex == 2'b00) begin
                                 wr_mem_data_o = {16'h0 , op_data2_i[15:0]};
                                 wr_mem_mask_o = 4'b0011;
                              end else begin
                                 wr_mem_data_o = {op_data2_i[15:0], 16'h0};
                                 wr_mem_mask_o = 4'b1100;
                              end 
                              
                              stall_o=1; 
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;

                              
                           end
                        end
                        `FUNC3_SW:begin
                           if(success_i) begin
                              finish_one(debug_pc_i,3,op_data1_i+op_data3_i);
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b00;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=4'b0000;
                  
                              stall_o=0;
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;
                           end
                           else begin
                              wr_reg_en_o=0;
                              wr_reg_data_o=0;
                              wr_reg_addr_o=0;
                                    
                              flag_o=2'b10;
                              addr_o=op_data1_i+op_data3_i;
                              wr_mem_data_o = op_data2_i;
                              wr_mem_mask_o = 4'b1111;
                         
                              stall_o=1; 
                              jmp_o=0;
                              jmp_pc_o=0;
                              flush_o=0;
                           end
                        end
                        default:begin
                           STOP(2,instr_i);
                        end
                     endcase
                  end
                  /* verilator lint_off WIDTHCONCAT */ 
                  `OPCODE_I3:begin//ADDI SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI
                     finish_one(debug_pc_i,0,0);;
                     case(func3)
                        `FUNC3_ADDI:begin//ADDI
                              wr_reg_en_o=wr_en_i;
                              wr_reg_data_o= op_data1_i+op_data2_i;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0; 
                        end
                        `FUNC3_SLTI:begin//SLTI
                              wr_reg_en_o=1;
                              wr_reg_data_o= ($signed(op_data1_i)<$signed(op_data2_i))?1:0 ;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;

                              stall_o=0; 
                              jmp_o= 0;  
                              jmp_pc_o= 0;
                              flush_o=0; 
                        end
                        `FUNC3_SLTIU:begin//SLTIU
                              wr_reg_en_o=1;
                              wr_reg_data_o= (op_data1_i<op_data2_i)?1:0 ;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0; 
                        end
                        `FUNC3_XORI:begin//XORI
                              wr_reg_en_o=wr_en_i;
                              wr_reg_data_o= op_data1_i^op_data2_i;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0; 
                        end
                        `FUNC3_ORI:begin//ORI
                              wr_reg_en_o=wr_en_i;
                              wr_reg_data_o= op_data1_i|op_data2_i;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0; 
                        end
                        `FUNC3_ANDI:begin//ANDI
                              wr_reg_en_o=wr_en_i;
                              wr_reg_data_o= op_data1_i&op_data2_i;
                              wr_reg_addr_o=wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0;
                        end
                        `FUNC3_SLLI:begin//SLLI
                              wr_reg_en_o = wr_en_i;
                              wr_reg_data_o = op_data1_i<<op_data2_i[5:0];
                              wr_reg_addr_o = wr_addr_i;

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0;
                        end
                        `FUNC3_SRI:begin//SRLI SRAI
                              wr_reg_en_o = wr_en_i;
                              if(op_data2_i[10])
                                  wr_reg_data_o = ($signed(op_data1_i)>>>op_data2_i[5:0]);
                              else 
                                  wr_reg_data_o = (op_data1_i>>op_data2_i[5:0]);
                              wr_reg_addr_o =wr_addr_i;
                              

                              flag_o=0;
                              addr_o=0;
                              wr_mem_data_o=0;
                              wr_mem_mask_o=0;

                              stall_o=0; 
                              jmp_o= 0;
                              jmp_pc_o= 0;
                              flush_o=0;
                        end
                        default:begin
                              STOP(2,instr_i);
                        end
                     endcase
                     
                  end 
                  `OPCODE_R1:begin  //ADD SUB SLL SLT SLTU XOR SRL SRA OR AND
                     finish_one(debug_pc_i,0,0);;
                     wr_reg_en_o=wr_en_i;
                     wr_reg_addr_o=wr_addr_i;

                     flag_o=0;
                     addr_o=0;
                     wr_mem_data_o=0;
                     wr_mem_mask_o=0;

                     stall_o=0; 
                     jmp_o=0;
                     jmp_pc_o=0;
                     flush_o=0;
                     case({func7,func3})
                        {`FUNC7_ADD,`FUNC3_ADD}:begin
                           wr_reg_data_o=op_data1_i+op_data2_i;
                        end
                        {`FUNC7_SUB,`FUNC3_SUB}:begin
                           wr_reg_data_o=op_data1_i-op_data2_i;
                        end
                        {`FUNC7_SLL,`FUNC3_SLL}:begin
                           wr_reg_data_o=op_data1_i<<op_data2_i;
                        end
                        {`FUNC7_SLT,`FUNC3_SLT}:begin
                           wr_reg_data_o=($signed(op_data1_i) < $signed(op_data2_i)) ? 1 : 0;    
                        end
                        {`FUNC7_SLTU,`FUNC3_SLTU}:begin
                           wr_reg_data_o=(op_data1_i < op_data2_i) ? 1 : 0;    
                        end
                        {`FUNC7_XOR,`FUNC3_XOR}:begin
                           wr_reg_data_o=op_data1_i ^ op_data2_i;
                        end
                        {`FUNC7_SRL,`FUNC3_SRL}:begin
                           wr_reg_data_o=op_data1_i>>op_data2_i;
                        end
                        {`FUNC7_SRA,`FUNC3_SRA}:begin
                           wr_reg_data_o=($signed(op_data1_i)) >>> op_data2_i;  
                        end
                        {`FUNC7_OR,`FUNC3_OR}:begin
                           wr_reg_data_o=op_data1_i|op_data2_i;
                        end
                        {`FUNC7_AND,`FUNC3_AND}:begin
                           wr_reg_data_o=op_data1_i&op_data2_i;
                        end   
                        default:begin
                           STOP(2,instr_i);
                        end
                     endcase
                  end
                  `OPCODE_I4:begin
                     STOP(2,instr_i);
                  end
                  `OPCODE_I5:begin
                     STOP(2,instr_i);
                  end
                  default:begin
                     STOP(2,instr_i);
                  end
            endcase
       end
        
      end
      else begin
        wr_reg_en_o=0;
        wr_reg_data_o=0;
        wr_reg_addr_o=0;

        jmp_o=0;
        jmp_pc_o=0;
        flush_o=0;
      end
    end


endmodule