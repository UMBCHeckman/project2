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
    if (argc !=5){
    cerr << "Not enough command line arguments!" << endl;
    exit(1);
    }
    string cardsFilename = argv[1];
    string commodityFilename = argv[2];
    string numPlayersS = argv[3];
    string strategyS = argv[4];
    int numPlayers = atoi(numPlayersS.c_str());
    int strategy = atoi(strategyS.c_str());
      //string cardsFilename = "cards.txt";
      //string commodityFilename = "commodities.txt";
      //int numPlayers = 4;
      //int strategy = 0;
    ofstream results("results.txt");
    //results<< numPlayers <<  strategy << endl;
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
