CC = gcc 
CFLAGS = -Wall
LDFLAGS = -lrt -lgpiod -pthread
OBJFILES = wiringPi.o softTone.o softPwm.o lcd.o client.o
TARGET = test_lcd
all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
