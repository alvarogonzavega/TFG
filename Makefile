CC = gcc
CFLAGS = -Wall -g -o
HEADERS = parser.h suggestions.h tutorial.h

OBJS = main.c parser.c suggestions.c tutorial.c

all: esh start

esh: $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS)
clean:
	rm -f *.o *~ *.txt core esh
start:
	echo "PLEASE TYPE "./esh" TO START THE WSHELL"
