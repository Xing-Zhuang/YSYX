#用来对verilog模块进行单元测
TB=tb/axi_tb.v
SRCS=$(TB) $(shell find soc/ core/ -name '*.v') top.v
target:
	iverilog $(SRCS) -o wave -I core/
	vvp -n wave -lxt2

show_wave:
	gtkwave wave.vcd


show:
	@echo $(SRCS)