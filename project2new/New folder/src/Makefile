
all: Driver.cpp
	g++ -Wall -c Game.cpp
	g++ -Wall -c Card.cpp
	g++ -Wall -c Commodity.cpp
	g++ -Wall -c CommodityStore.cpp
	g++ -Wall -c Player.cpp
	g++ -Wall -c Objective.cpp
	g++ -Wall -c Driver.cpp
	g++  Driver.o Objective.o Player.o CommodityStore.o Commodity.o Card.o Game.o -o Driver.out

clean:
	rm -rf *.o
	rm -f *.out
	rm rm -f *~ *.h.gch *#

run:
	./Driver.out $(CARDS) $(COMMODITIES) $(PLAYERS) $(STRATEGY)
valgrind:
	valgrind ./Driver.out CARDS=cards.txt COMMODITIES=commodities.txt PLAYERS=4 STRATEGY = 0