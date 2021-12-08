ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif
ifeq ($CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

ifeq ($(INCLUDES),)
	INCLUDES = -I/
endif

all: lcd_lib 


lcd.o: lcd.c
	$(CC) $(CFLAGS) -c lcd.c

lcd_lib: lcd.o
	$(CC) $(CFLAGS) lcd.o -o lcd_lib -lgpiod

clean:
	rm -f *.o
	rm -f lcd_lib

