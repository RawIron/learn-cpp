CC = gcc
CFLAGS = -g -pg

np:	np.c
	$(CC) $(CFLAGS) -o np np.c

perimeter:	perimeter.c
	$(CC) $(CFLAGS) -o perimeter perimeter.c -lm

.PHONY:	clean
clean:
	rm -f *.o *.out callgrind.out.*
	rm -f np perimeter
