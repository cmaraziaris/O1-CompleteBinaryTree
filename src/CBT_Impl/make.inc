# Makefile of CBT Implementation in Modules

include $(MODULES)/BT_Impl/make.inc

CFLAGS+= -I$(MODULES)/CBT_Impl

OBJS+= $(MODULES)/CBT_Impl/CBTImplementation.o