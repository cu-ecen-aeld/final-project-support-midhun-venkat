ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif
ifeq ($CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

ifeq ($(INCLUDES),)
	INCLUDES = -I/
endif

all: lcd 


lcd.o: lcd.c
	$(CC) $(CFLAGS) -c lcd.c

lcd: lcd.o
	$(CC) $(CFLAGS) lcd.o -o lcd -lgpiod


#lcd1: lcd1.o wiringPi.o
#	$(CC) $(CFLAGS) -c -o lcd1.o wiringPi.o -lgpiod


clean:
	rm -f *.o
	rm -f lcd

