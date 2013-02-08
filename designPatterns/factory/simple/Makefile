main.o:	main.cpp
	g++ -c main.cpp

EventCleaner.o:	EventCleaner.cpp EventCleaner.h Event.h
	g++ -c EventCleaner.cpp

CleanerSimpleFactory.o:	CleanerSimpleFactory.cpp Task.h Event.h
	g++ -c CleanerSimpleFactory.cpp

cleaner:	main.o EventCleaner.o CleanerSimpleFactory.o Task.h Event.h
	g++ -lm -o cleaner main.o EventCleaner.o CleanerSimpleFactory.o
