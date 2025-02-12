module decoder(
    input  wire[31:0] inst,

    output reg[2:0] ALUCon,
    output reg RegWr
);  
    import "DPI-C" context function void STOP();
  
  
    wire[6:0] opcode=inst[6:0];
    wire[2:0] funct3=inst[14:12];
    //assign all={funct3[2:0],opcode[6:0]};

    always@(*)begin
        if(opcode==7'b0010011||opcode==7'b1100111||opcode==7'b0000011||opcode==7'b0001111||opcode==7'b1110011) begin//I
            //ebreak   
            if(inst==32'b00000000_00010000_00000000_01110011) begin
                ALUCon=3'b000;
                RegWr=0;
                STOP();
            end
            //addi
            else if(funct3==3'b000) begin 
                ALUCon=3'b001;
                RegWr=1;
               
            end
            //TODO
            else begin
                ALUCon=3'b000;
                RegWr=0;
                
            end
        end
        else begin//其他类型TODO
            ALUCon=3'b000;
            RegWr=0;
            
        end         
    end
 
endmodule;