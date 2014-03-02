CC=gcc
CFLAGS=-std=c99 -O3 -Wall 

# run with $ DEBUG=1 make 
# this will add debug symbols to the binary
ifdef DEBUG
  CFLAGS+=-g
endif 
# if compiling dynamically you can run the program with 
# LD_LIBRARY_PATH=3rd_party/argparse ./src/cofre
#

all:
	$(CC) $(CFLAGS) bitshape.c -o bitshape
