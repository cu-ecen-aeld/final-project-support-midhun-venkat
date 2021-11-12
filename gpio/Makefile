CROSS_COMPILE=

ifeq ($(CC),)
	CC=$(CROSS_COMPILE)gcc
endif

ifeq ($(CFLAGS),)
	CFLAGS= -g -Wall -Werror
endif

ifeq ($(LDFLAGS),)
	LDFLAGS= -lgpiod
endif

all: readtest writetest 
default: readtest writetest

readtest : read.o
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o readtest read.o $(LDFLAGS)

writetest : write.o
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o writetest write.o $(LDFLAGS)

read.o : read.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c read.c $(LDFLAGS)

write.o : write.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c write.c $(LDFLAGS)

clean :
	rm -f readtest writetest *.o
