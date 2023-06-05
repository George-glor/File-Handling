
CC=gcc
CFLAGS=-lm -I.

memo: memo.o libmemo.o
	$(CC) -o memo memo.o libmemo.o $(CFLAGS)
memo.o: memo.c
	$(CC) -c memo.c $(CFLAGS)
libmemo.o:libmemo.c
	$(CC) -c libmemo.c $(CFLAGS)

.PHONY: clean 
clean: 
	rm  *.o  memo memo.csv
