#ifndef PLAYER_H
#define PLAYER_H
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include <iostream>
#include <queue>

using namespace std;

class Player{
public:
    enum STRATEGY{
        BEST_PAYOFF,
        FIRST_ALPHA_DESTINATION,
        COLOR_PURPLE,
        COLOR_RED,
        COLOR_ORANGE,
        COLOR_BLACK,
        COLOR_GREEN,
        COLOR_BROWN
    };
    Player();
    string getName()const;
    int getScore()const;
    void addCard(Card*card);
    int calculateScore(Player::STRATEGY strategy);
    void printResult(std::ofstream& fileStream);
private:
    string m_sName;
    queue<Card*> m_cards;
    queue<Objective*> m_objectives;
};
#endif // PLAYER_H
