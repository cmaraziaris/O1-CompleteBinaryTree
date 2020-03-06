# Makefile of CBT Implementation

MODULES= ../src

CFLAGS= -O3 -Wall -I . 

PROGRAM= O1_cbt

OBJS= Main.o

include $(MODULES)/CBT_Impl/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)						# Run with default arguments 
	./$(PROGRAM) 22 100000 10000000

check: $(PROGRAM)					# Check for memory leaks (Requires Valgrind Installation)
	valgrind ./$(PROGRAM) 22 10000 1000000