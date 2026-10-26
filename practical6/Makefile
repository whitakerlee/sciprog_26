CC = gcc
CFLAGS = -Wall -Wextra -std=c11

matrix: main.o matmult.o
	$(CC) $(CFLAGS) main.o matmult.o -o matrix

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c

clean:
	rm -f *.o matrix
