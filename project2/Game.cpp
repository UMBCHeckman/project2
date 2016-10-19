#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"
#include <iostream>
#include <istream>
#include <sstream>
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

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
    string playerName;
    Player *myPlayer;
    for(int i = 0; i < players; i++)
    {
        playerName = "Player " + SSTR(i+1);
        //cerr << playerName << endl;
        myPlayer = new Player(playerName);
        m_players.push_back(myPlayer);
    }
    int cardsPerPlayer = (m_drawPile.size() / m_players.size());
    if (cardsPerPlayer == 0)
    {
        cerr << "Not enough cards to go around! Try again with less players." << endl;
        exit(1);
    }
    for (int j = 0; j < cardsPerPlayer; j++)
    {
        for (int i = 0; i < m_players.size(); i++)
        {
            m_players[i]->addCard(m_drawPile.top());
            m_drawPile.pop();
        }
    }
    Player *bestPlayer;
    int bestScore = 0;
    for(int i = 0; i < m_players.size(); i++)
    {
        if(m_players[i]->calculateScore(strategy) > bestScore)
        {
            bestScore = m_players[i]->calculateScore(strategy);
            bestPlayer = m_players[i];
        }
    }

}
void Game::printDrawPile(std::ofstream& fileStream)
{
    fileStream << "---------- Draw Pile ----------" << endl;
    stack<Card*> printPile = m_drawPile;
    //cerr << printPile.size() << endl;
    int s = printPile.size();
    for(int i = 0; i < s; i++)
    {
        //cerr << i << endl;
        printPile.top()->printCard(fileStream);
        printPile.pop();
    }
}
void Game::printResults(std::ofstream& fileStream)
{
    fileStream << "---------- RESULTS ----------" << endl;
    Player *bestPlayer;
    int bestScore = 0;
    for(int i = 0; i < m_players.size(); i++)
    {
        fileStream << "--------" << m_players[i]->getName() << "------------" << endl;
        m_players[i]->printResult(fileStream);
        if(m_players[i]->getScore() > bestScore)
        {
            bestScore = m_players[i]->getScore();
            bestPlayer = m_players[i];
        }
    }
    fileStream << "--------------------------" << endl;
    fileStream << "Winner: " << bestPlayer->getName() << " Score: " << bestScore << " points.";
}

#endif //GAME_CPP
