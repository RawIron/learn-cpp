Invoker.o:	Invoker.cpp Invoker.h
	g++ -c Invoker.cpp

main.o:	main.cpp Invoker.h Counter.h CountCommand.h
	g++ -c main.cpp

a.out:	main.o Invoker.o
	g++ -lm main.o Invoker.o
