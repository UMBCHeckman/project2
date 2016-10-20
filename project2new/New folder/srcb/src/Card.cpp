#ifndef CARD_CPP
#define CARD_CPP
/************************************************
 ** File:    Card.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "Card" object.


 **   This file contains constructors and functions.
 **   This file contains a vector that changes in size dynamically.
 **   This file does NOT call new directly.
 **   This file has only a default constructor for Card.
 **
 ***********************************************/
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "CommodityStore.h"
#include "Card.h"
#include "Objective.h"
//#include "CommodityStore.h"
//#include <map>
//#include <fstream>
//#include <sstream>
//#include <cstdlib>

using namespace std;

Card::Card()
{
    //intentionally empty
}

void Card::addObjective(Objective* objective)//adds an objective to a card, should be called by Game 3 times per card.
{
    m_objectives.push_back(objective);
}
Objective* Card::getBestPayoff()//get the highest payoff among the 3 objectives, should be called by Player.cpp.
{
    Objective *bestObjective;
    int bestSoFar = 0;
    for(unsigned int j = 0; j < m_objectives.size(); j++)//for all the objectives on a card. Should always be 3, but better safe than sorry.
    {
        if((m_objectives[j]->getPayoff()) > bestSoFar)//standard logic for finding the largest value.
        {
            bestSoFar = (m_objectives[j]->getPayoff());
            bestObjective = m_objectives[j];
        }
    }
    return bestObjective;
}
Objective* Card::getFirstAlphaDestination()//finds the first destination in alphabetical order and returns the objective with that destination.
{
    Objective *bestObjective;
    string bestSoFar = "zzzzzzzzzzzzzzzzzzzzzzzzz";//this will certainly be last country name in any alphabetical list.
    for(unsigned int j = 0; j < m_objectives.size(); j++)
    {
        if((m_objectives[j]->getDestination().compare(bestSoFar)) < 0)//when = 0, the names are the same. In that case, we specifically want the first instance of that destination.
        {
            bestSoFar = m_objectives[j]->getDestination();
            bestObjective = m_objectives[j];
        }
    }
    return bestObjective;
}
Objective* Card::getByColor(Commodity::COLOR color)//returns objective with the chosen color for commodity. Called by Player.cpp
{
    Objective *bestObjective;
    int bestSoFar = 0;
    for(unsigned int j = 0; j < m_objectives.size(); j++)
    {
        if((m_objectives[j]->getCommodity()->getColor()) == color)//if we found the color of choice
        {
            if((m_objectives[j]->getPayoff()) > bestSoFar) //if another commodity with the chosen color and a larger payoff is discovered, that should be returned instead.
            {
                bestSoFar = m_objectives[j]->getPayoff();
                bestObjective = m_objectives[j];
            }
        }
    }
    if (bestSoFar == 0) //if none of the selected color appear the Color based strategies resolve as if they were the highest value strategy.
    {
        return getBestPayoff();
    }
    return bestObjective;
}
void Card::printCard(std::ofstream& fileStream)//prints a card to the results file.
{
    fileStream << "---------- CARD ----------" << endl;
    for(unsigned int i = 0; i < m_objectives.size(); i++)
    {
        m_objectives[i]->printObjective(fileStream);
    }
    fileStream << "--------------------------" << endl;
    //for (std::vector<Objective*>::const_iterator i = m_objectives.begin(); i != m_objectives.end(); ++i)
    //cerr << &i->printObjective() << ' ';
}

#endif
