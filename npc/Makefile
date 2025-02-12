all:
	@echo "请选择verilator还是nvboard" 
	@echo "nv_complier   nv_run   nv_clean"   
	@echo "ver_complier  ver_run  ver_wave  ver_clean"   

#nvboard所需参数
TOPNAME = top#verilog代码的顶层模块名字
NXDC_FILES = constr/top.nxdc#引脚绑定约束文件
INC_PATH ?=

#verilator所需参数
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

#项目构建目录
BUILD_DIR = ./build
#目标文件夹
OBJ_DIR = $(BUILD_DIR)/obj_dir
#目标文件（可执行文件）
BIN = $(BUILD_DIR)/$(TOPNAME)


$(shell mkdir -p $(BUILD_DIR))   #创建构建目录

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)
EXCLUDE=$(shell find $(abspath ./csrc) -name "sim_main.cpp")
CSRCS := $(filter-out $(EXCLUDE), $(CSRCS))

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""


$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)  
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

nv_complier: $(BIN)

nv_run: $(BIN)
	@$^

nv_clean:
	rm -rf $(BUILD_DIR)

#verilator 1.将.v文件编译成.cpp文件 2.将
 
 
DISASM_LIBS += $(shell llvm-config --libs)

 

ver_complier:
	verilator  -I/home/xz/ysyx-workbench/npc/vsrc/core -cc --exe -j --trace --top-module top $(VSRCS) csrc/sim_main.cpp 
	make -C ./csrc/utils/ -f utils.mk
	@echo "" >> ./obj_dir/Vtop.mk
	@echo "LDLIBS += -lreadline"  >> ./obj_dir/Vtop.mk
	@echo "" >> ./obj_dir/Vtop.mk
	@echo "LDLIBS += $(DISASM_LIBS)"  >> ./obj_dir/Vtop.mk
	@echo "" >> ./obj_dir/Vtop.mk
	@echo "LOADLIBES += ../csrc/utils/disasm.o"  >> ./obj_dir/Vtop.mk
	make -C ./obj_dir/ -f Vtop.mk 
	
 
ver_run:ver_complier
	./obj_dir/Vtop $(IMG) $(ARGS)

ver_wave:
	sudo gtkwave dump.vcd
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
 
ver_clean:
	rm -rf ./obj_dir
	rm dump.vcd




clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./obj_dir
	rm -f dump.vcd

show:
	echo $(abspath ./vsrc)
	
.PHONY: nv_complier nv_run nv_clean ver_complier ver_wave ver_clean
include ../Makefile

