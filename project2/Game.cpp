#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"
#include <iostream>
#include <istream>
#include <sstream>

using namespace std;

Game::Game()
{
    //intentionally empty
}
Game::Game(string cardsFilename, string commodityFilename)
{
    m_bank.loadCommodities(commodityFilename);
    ifstream dataFile(cardsFilename.c_str());
    string line;
    string Destination1, Commodity1, Payoff1, Destination2, Commodity2, Payoff2, Destination3, Commodity3, Payoff3;//aspects of an Objective
    //dataFile.open();
    Card *myCard;
    Objective *myObjective;
    while (getline(dataFile, line))
    {
        istringstream myData(line);
        myData >> Destination1;
        myData >> Commodity1;
        myData >> Payoff1;
        myData >> Destination2;
        myData >> Commodity2;
        myData >> Payoff2;
        myData >> Destination3;
        myData >> Commodity3;
        myData >> Payoff3;
        //cerr << Destination2 << Commodity2 << Payoff2 << endl;
        myCard = new Card();
        myObjective = new Objective((Destination1), (m_bank.getCommodity(Commodity1)), (atoi(Payoff1.c_str())));//Payoff must be converted from a string to an integer
        myCard->addObjective(myObjective);
        myObjective = new Objective((Destination2), (m_bank.getCommodity(Commodity2)), (atoi(Payoff2.c_str())));
        myCard->addObjective(myObjective);
        myObjective = new Objective((Destination3), (m_bank.getCommodity(Commodity3)), (atoi(Payoff3.c_str())));
        //cerr << myObjective->getDestination() << myObjective->getCommodity()->getName() << myObjective->getPayoff() << endl;
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
    stack<Card*> printPile = m_drawPile;
    cerr << printPile.size() << endl;
    for(int i = 0; i < printPile.size(); i++){
        printPile.top()->printCard(fileStream);
        printPile.pop();
    }
}
void Game::printResults(std::ofstream& fileStream)
{

}

#endif //GAME_CPP
