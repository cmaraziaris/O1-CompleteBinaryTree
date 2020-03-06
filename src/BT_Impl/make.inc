# Makefile of BT Implementation in Modules

CFLAGS+= -I$(MODULES)/BT_Impl
 
OBJS += $(MODULES)/BT_Impl/BTImplementation.o

ifeq ($(ITEM_TYPE),int)
	CFLAGS += -D INT
else 
	CFLAGS += -D STR 
endif
