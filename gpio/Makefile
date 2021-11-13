ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif
ifeq ($CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

ifeq ($(INCLUDES),)
	INCLUDES = -I/
endif

all: read write

read.o: read.c
	$(CC) $(CFLAGS) -c read.c

read: read.o
	$(CC) $(CFLAGS) read.o -o read -lgpiod

write.o: write.c
	$(CC) $(CFLAGS) -c write.c

write: write.o
	$(CC) $(CFLAGS) write.o -o write -lgpiod

clean:
	rm -f *.o
	rm -f read write

