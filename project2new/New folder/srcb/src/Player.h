#ifndef PLAYER_H
#define PLAYER_H
/************************************************
 ** File:    Player.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the Player object.
 **   See Player.h for details.
 **
 ***********************************************/
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
    Player(string name);
    string getName()const;
    int getScore()const;
    void addCard(Card*card);
    int calculateScore(Player::STRATEGY strategy);
    void printResult(std::ofstream& fileStream);
private:
    string m_sName;
    queue<Card*> m_cards;
    queue<Objective*> m_objectives;
    int m_score;
};
#endif // PLAYER_H
