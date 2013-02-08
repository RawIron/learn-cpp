timerStrand.o:	timerStrand.cpp timerStrand.h
	g++ -c timerStrand.cpp

main.o:	main.cpp
	g++ -c main.cpp

timerStrand:	main.o timerStrand.o
	g++ -lm -o timerStrand main.o timerStrand.o /usr/lib/libboost_thread.a -lpthread

clean:
	rm -f *.o
