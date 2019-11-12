MODULES= ../Modules

CFLAGS= -g -Wall -I. 

PROGRAM= ex1-3

OBJS= Main.o

include $(MODULES)/BT_Impl/Makefile

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)
