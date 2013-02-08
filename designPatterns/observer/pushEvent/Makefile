main.o:	main.cpp Observer.h Observable.h
	g++ -c main.cpp

Observable.o:	Observable.cpp Observable.h Observer.h Event.h
	g++ -c Observable.cpp

Observer.o:	Observer.cpp Observer.h Event.h ObserverInterface.h
	g++ -c Observer.cpp

a.out:	main.o Observer.o Observable.o
	g++ -lm main.o Observer.o Observable.o
