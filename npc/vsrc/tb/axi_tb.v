`timescale 1 ns / 1 ps


module axt_tb;

    reg clk;
    reg rst;

    top top_i(
        .clk(clk),
        .rst(rst)
    );

    initial begin
        clk=0;
    end
    always #10 clk=~clk;

    initial begin
        rst=1;
        #25
        rst=0;
        #1000
        
        $finish;
    end

    
    initial begin
        $readmemh ("inst.data", top_i.sram_i._ram); //注意inst.data的存放路径 应该是以Makefile文件的存放路径为起点的
        $display("======================================");
            $display("%h",top_i.sram_i._ram[0]);
            $display("%h",top_i.sram_i._ram[1]);
            $display("%h",top_i.sram_i._ram[2]);
            $display("");
        $display("======================================");
    end

    // generate wave file, used by gtkwave
    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, axt_tb);
    end

    

endmodule