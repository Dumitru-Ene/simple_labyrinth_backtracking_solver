CC = gcc
CFLAGS = -std=gnu99 -g -Wall -Wextra -pedantic 
extensions = .c
exec = lab.out

build:
	$(CC) $(CFLAGS) *$(extensions) -o $(exec)

run:
	./$(exec)

clean:
	rm -f $(exec)
