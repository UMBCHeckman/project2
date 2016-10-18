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
Game::Game(string cardsFilename, string commodityFilename)
{
    m_bank.loadCommodities(commodityFilename);
    ifstream dataFile(cardsFilename.c_str());
    string Destination1, Commodity1, Payoff1, Destination2, Commodity2, Payoff2, Destination3, Commodity3, Payoff3;//aspects of an Objective
    //dataFile.open();
    Card *myCard;
    Objective *myObjective;
    while (dataFile)
    {

        dataFile >> Destination1;
        dataFile >> Commodity1;
        dataFile >> Payoff1;
        dataFile >> Destination2;
        dataFile >> Commodity2;
        dataFile >> Payoff2;
        dataFile >> Destination3;
        dataFile >> Commodity3;
        dataFile >> Payoff3;
        myCard = new Card();
        myObjective = new Objective((Destination1), (m_bank.getCommodity(Commodity1)), (atoi(Payoff1.c_str())));//Payoff must be converted from a string to an integer
        myCard->addObjective(myObjective);
        myObjective = new Objective((Destination1), (m_bank.getCommodity(Commodity2)), (atoi(Payoff2.c_str())));
        myCard->addObjective(myObjective);
        myObjective = new Objective((Destination1), (m_bank.getCommodity(Commodity2)), (atoi(Payoff3.c_str())));
        myCard->addObjective(myObjective);
        m_drawPile.push(myCard);
        //myCard = new Card(Destination1, Commodity1, Payoff1, Destination2, Commodity2, Payoff2, Destination3, Commodity3, Payoff3);
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
