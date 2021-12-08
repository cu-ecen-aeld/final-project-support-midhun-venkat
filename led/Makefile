ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif
ifeq ($CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

ifeq ($(INCLUDES),)
	INCLUDES = -I/
endif

all: led 


led.o: led.c
	$(CC) $(CFLAGS) -c led.c

led: led.o
	$(CC) $(CFLAGS) led.o -o led -lgpiod

clean:
	rm -f *.o
	rm -f led

