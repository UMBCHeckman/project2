#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void printGreeting(){
    cout << "WELCOMB THIS IS A GREEITG!!00" << endl;
    cout << "Name: Steven Heckman. Section 5." << endl;
}
int main(int argc, char ** argv)
{
    string cardsFilename = "cards.txt";//argv[1];
    string commodityFilename = "commodities.txt";//argv[2];
    ofstream results("results.txt");
    printGreeting();
    Game myGame = Game(cardsFilename, commodityFilename);
    myGame.printDrawPile(results);
    //cerr << MyStore.getCommodity("Beer")->getColor();
    results.close();
    return 0;
}
