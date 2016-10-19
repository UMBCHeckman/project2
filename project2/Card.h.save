#ifndef CARD_H
#define CARD_H
/************************************************
 ** File:    Card.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the Card object.
 **   See Card.cpp for details.
 **
 ***********************************************/
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include <iostream>
#include <istream>
#include <vector>

using namespace std;

class Card{
public:
    Card();
    void addObjective(Objective* objective);
    Objective* getBestPayoff();
    Objective* getFirstAlphaDestination();
    Objective* getByColor(Commodity::COLOR color);
    void printCard(std::ofstream& fileStream);
private:
    vector<Objective*> m_objectives;
};

#endif // CARD_H
