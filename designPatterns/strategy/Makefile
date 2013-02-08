main.o:	main.cpp LinearGrowth.h
	g++ -c main.cpp

Plant.o:	Plant.cpp Plant.h GrowBehavior.h
	g++ -c Plant.cpp

LinearGrowth.o:	LinearGrowth.cpp LinearGrowth.h GrowBehavior.h
	g++ -c LinearGrowth.cpp

a.out:	main.o Plant.o LinearGrowth.o GrowBehavior.h
	g++ -lm main.o Plant.o LinearGrowth.o GrowBehavior.h
