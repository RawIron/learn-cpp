CC = gcc
CFLAGS = -g -pg

np:	np.c
	$(CC) $(CFLAGS) -o np np.c

.PHONY:	clean
clean:
	rm -f *.o *.out callgrind.out.* np
