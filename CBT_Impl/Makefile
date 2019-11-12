MODULES= ../Modules

CFLAGS= -O3 -Wall -I . 

PROGRAM= O1_cbt

OBJS= Main.o

include $(MODULES)/CBT_Impl/Makefile

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)
