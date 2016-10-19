#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void printGreeting(std::ofstream& fileStream){
    fileStream << "Steven Heckman, Section 5." << endl;
}
int main(int argc, char ** argv)
{
    //if (argc !=4){
       // cerr << "Not enough command line arguments!" << endl;
     //   exit(1);
    //}
    cerr << "what";
    string cardsFilename = argv[1];
    string commodityFilename = argv[2];
    int numPlayers = atoi(argv[3]);
    int strategy = atoi(argv[4]);
    cardsFilename = "cards.txt";
    commodityFilename = "commodities.txt";
    numPlayers = 4;
    strategy = 0;
    ofstream results("results.txt");
    printGreeting(results);
    Game myGame = Game(cardsFilename, commodityFilename);
    myGame.printDrawPile(results);
    Player::STRATEGY myStrategy = (Player::STRATEGY)strategy;//converting int to enum
    myGame.runSimulation(numPlayers, myStrategy);
    myGame.printResults(results);
    //cerr << MyStore.getCommodity("Beer")->getColor();
    results.close();
    return 0;
}
