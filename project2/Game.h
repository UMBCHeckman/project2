#ifndef GAME_H
#define GAME_H
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include <iostream>

using namespace std;

class Game{
public:
    void runSimulation(int players, Player::STRATEGY strategy);
    void printDrawPile(std::ofstream& fileStream);
    void printResults(std::ofstream& fileStream);
private:
    stack<Card*> m_drawPile;
    vector<Player*> m_players;
    CommodityStore m_bank;
};

#endif // GAME_H
