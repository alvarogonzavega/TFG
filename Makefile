CC = gcc
CFLAGS = -Wall -g -o
HEADERS = parser.h suggestions.h

OBJS = main.c parser.c suggestions.c

all: esh start

esh: $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS)
clean:
	rm -f *.o *~ *.txt core esh
start:
	echo "PLEASE TYPE "./esh" TO START THE WSHELL"
