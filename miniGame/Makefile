main.o:	main.cpp player.h
	g++ -c main.cpp

achievement.o:	achievement.cpp achievement.h
	g++ -c achievement.cpp

counter.o:	counter.cpp counter.h
	g++ -c counter.cpp

player.o:	player.cpp player.h
	g++ -c player.cpp

game:	main.o player.o achievement.o counter.o
	g++ -lm main.o player.o achievement.o counter.o
