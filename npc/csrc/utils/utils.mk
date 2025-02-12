CXXSRC = disasm.cpp
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
LIBS += $(shell llvm-config --libs)

show:
	@echo $(LIBS)

all:
	g++  -c  $(CXXSRC) -o disasm.o  $(CXXFLAGS)  $(LIBS)