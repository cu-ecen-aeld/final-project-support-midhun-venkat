ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif
ifeq ($CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

ifeq ($(INCLUDES),)
	INCLUDES = -I/
endif

all: read writelow writehigh toggle lcd

read.o: read.c
	$(CC) $(CFLAGS) -c read.c

read: read.o
	$(CC) $(CFLAGS) read.o -o read -lgpiod

writelow.o: writelow.c
	$(CC) $(CFLAGS) -c writelow.c

writelow: writelow.o
	$(CC) $(CFLAGS) writelow.o -o writelow -lgpiod

writehigh.o: writehigh.c
	$(CC) $(CFLAGS) -c writehigh.c

writehigh: writehigh.o
	$(CC) $(CFLAGS) writehigh.o -o writehigh -lgpiod

toggle.o: toggle.c
	$(CC) $(CFLAGS) -c toggle.c

toggle: toggle.o
	$(CC) $(CFLAGS) toggle.o -o toggle -lgpiod

lcd.o: lcd.c
	$(CC) $(CFLAGS) -c lcd.c

lcd: lcd.o
	$(CC) $(CFLAGS) lcd.o -o lcd -lgpiod

clean:
	rm -f *.o
	rm -f read writelow writehigh toggle lcd

