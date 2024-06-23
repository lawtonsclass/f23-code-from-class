# the programs we want to use to compile our stuff
CXX=g++
CXXFLAGS=-g
CC=gcc
CCFLAGS=-g
AS=as
ASFLAGS=-g
LD=ld
LDFLAGS=

# if this computer isn't running an ARM32 processor, use QEMU
UNAME=$(shell uname -m)
ifneq ($(UNAME), aarch64)
	CXX=g++-aarch64-linux-gnu
	CC=gcc-aarch64-linux-gnu
	AS=as-aarch64-linux-gnu
	LD=ld-aarch64-linux-gnu
	CXXFLAGS+= -static
	CCFLAGS+= -static
	LDFLAGS+= -static
endif

# what we want to build when we just say "make"
BINARIES=filter
all: $(BINARIES)

# how to compile each different kind of .o file
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^
%.o : %.c
	$(CC) $(CCFLAGS) -c $^
%.o : %.s
	$(AS) $(ASFLAGS) $^ -o $@

filter: filter.o swapColors.o bw.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
