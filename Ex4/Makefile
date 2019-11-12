MODULES= ../Modules

CFLAGS= -O3 -g -Wall -I . 

PROGRAM= ex4

OBJS= Main.o

include $(MODULES)/CBT_Impl/Makefile

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)
