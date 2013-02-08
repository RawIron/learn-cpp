main.o:	main.cpp player.h resultSet.h
	g++ -c main.cpp

resultSet.o:	resultSet.h resultSetInterface.h
	g++ -c resultSet.h

a.out:	main.o resultSet.o
	g++ -lm main.o resultSet.o
