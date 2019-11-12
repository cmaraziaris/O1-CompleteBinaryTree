MODULES= ../Modules
# TODO: Remove -g3 before publishing
CFLAGS= -O3 -g3 -Wall -I . 

PROGRAM= O1_cbt

OBJS= Main.o

include $(MODULES)/CBT_Impl/Makefile

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)						# Default argument : 22
	./$(PROGRAM) 22