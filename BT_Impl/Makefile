MODULES= ../Modules

CFLAGS= -O3 -Wall -I. 

PROGRAM= bt_impl

OBJS= Main.o

include $(MODULES)/BT_Impl/Makefile

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)
