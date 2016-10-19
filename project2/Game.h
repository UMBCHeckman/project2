#ifndef GAME_H
#define GAME_H
/************************************************
 ** File:    Game.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the Game object.
 **   See Game.h for details.
 **
 ***********************************************/
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Game{
public:
    Game();
    Game(string cardsFilename, string commodityFilename);
    void runSimulation(int players, Player::STRATEGY strategy);
    void printDrawPile(std::ofstream& fileStream);
    void printResults(std::ofstream& fileStream);
private:
    stack<Card*> m_drawPile;
    vector<Player*> m_players;
    CommodityStore m_bank;
};

#endif // GAME_H
