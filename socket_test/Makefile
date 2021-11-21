
# the compiler: gcc for C program, define as g++ for C++
ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
ifeq ($(CFLAGS),)
	CFLAGS  = -g -Wall -Werror
endif

ifeq ($(LDFLAGS),)
	LDFLAGS = -pthread -lrt
endif

all: client_test server_test
default: all

client_test: socket-client_test.c
	$(CC) $(CFLAGS) -o client_test socket-client_test.c $(LDFLAGS)

server_test: socket-server_test.c
	$(CC) $(CFLAGS) -o server_test socket-server_test.c $(LDFLAGS)


.PHONY: all

clean:
	\rm client_test server_test
	$(RM) $(TARGET) 
