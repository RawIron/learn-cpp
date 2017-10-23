.PHONY:	clean
clean:
	-rm -f bowlingTest bowling.o

all:	bowling.o bowlingTest

bowling.o:	bowling.cpp
	g++ -g -c -std=c++14 bowling.cpp

bowlingTest:	bowlingTest.cpp
	g++ -g -std=c++14 bowlingTest.cpp -lcppunit -o bowlingTest
