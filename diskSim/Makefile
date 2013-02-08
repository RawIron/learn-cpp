main.o:	main.cpp player.h resultSet.h
	g++ -c main.cpp

a.out:	main.o resultSet.o
	g++ -lm main.o resultSet.o


platter:	platter.cpp platterTest.cpp
	g++ -g -std=c++0x platterTest.cpp -lcppunit -o platter

ticker.o:	ticker.h ticker.cpp
	g++ -c -std=c++0x ticker.cpp

tickerListener.o:	tickerListener.h tickerListener.cpp
	g++ -c -std=c++0x tickerListener.cpp

platterServer:	platterServer.cpp platterServerTest.cpp ticker.o tickerListener.o
	g++ -g -std=c++0x platterServerTest.cpp -lm ticker.o tickerListener.o -lcppunit -o platterServer

drive:	physicalDiskDrive.cpp physicalDiskDriveTest.cpp
	g++ -g -std=c++0x physicalDiskDriveTest.cpp -lcppunit -o drive


ticker:	tickerTest.cpp ticker.o tickerListener.o
	g++ -g -std=c++0x tickerTest.cpp -lm ticker.o tickerListener.o -lcppunit -o ticker
