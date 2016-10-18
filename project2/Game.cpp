#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"
#include <iostream>
#include <istream>

using namespace std;

Game::Game()
{
    //intentionally empty
}
Game::Game(string filename)
{
    ifstream dataFile;
    istream *line;
    string Destination, Commodity, Payoff;//aspects of an Objective
    filename = "cards.txt";
    dataFile.open("cards.txt");
    Objective *myObjective;
    Card *myCard;
    while (dataFile)
    {
        &line = getline(dataFile);
        myCard = new Card(line);
        //dataFile >> Destination;
        //dataFile >> Commodity;
        //dataFile >> Payoff;
        //*Commodityobj = CommodityStore::getCommodity(Commodity);
        //myObjective = new Objective(Destination, Commodityobj, atoi(Payoff);
        //m_drawPile.push(myCard);
        //new Commodity(dataFile >> line, dataFile >> line)
    }
    dataFile.close();
}
void Game::runSimulation(int players, Player::STRATEGY strategy)
{

}
void Game::printDrawPile(std::ofstream& fileStream)
{

}
void Game::printResults(std::ofstream& fileStream)
{

}

#endif //GAME_CPP
