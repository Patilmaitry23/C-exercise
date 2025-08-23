CC=gcc
CFLAGS=-Wall -Wextra -g -O0

SRC=$(wildcard *.c)     #all .c files in current dir
EXE=$(SRC:.c=)          #each .c builds into its own program
#OBJS=$(SRC:.c=.o)    #replace .c with .o
#BINARY =bin

all: $(EXE) # $(BINARY)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

#$(BINARY): $(OBJS)
#	$(CC) $^ -o  $@

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE) *.o #$(OBJS) $(BINARY)
