CC = gcc
AR = ar
CFLAGS = -g -Wall
ALL_OBJFILES = isort txtfind txtfind.o isort.o


all : $(ALL_OBJFILES)

isort: isort.o
	$(CC) $(CFLAGS) isort.o -o isort

txtfind: txtfind.o
	$(CC) $(CFLAGS) txtfind.o -o txtfind

isort.o: isort.c isort.h
	$(CC) $(CFLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(CFLAGS) -c txtfind.c 


.PHONY: clean all

clean:
	rm -f *.o $(ALL_OBJFILES)




