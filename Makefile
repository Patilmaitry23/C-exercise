CC=gcc
CFLAGS=-Wall -Wextra -g -O0

CFILES=$(wildcard *.c)     #all .c files in current dir
OBJECTS=$(CFILES:.c=.o)    #replace .c with .o
BINARY =bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS)
