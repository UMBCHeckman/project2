#ifndef OBJECTIVE_CPP
#define OBJECTIVE_CPP
/************************************************
 ** File:    Objective.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "Objective" object.
 **
 **   This file contains constructors a map and functions.
 **   This file create an objective to be added to a card.
 **
 ***********************************************/
#include "Objective.h"
#include <iostream>

using namespace std;

Objective::Objective()//default constructor
{
    //intentionally empty
}
Objective::Objective(string Destination, Commodity* Commodity, int Payoff)//non default constructor, takes a string, a commodity object, and an int
{
    m_sDestination = Destination;
    m_pCommodity = Commodity;
    m_iPayoff = Payoff;
}
string Objective::getDestination()const//get the destination of the objective
{
    return m_sDestination;
}
Commodity* Objective::getCommodity()const//get the commodity of the objective. Note this is a commodity object, not just the commodity's name.
{
    return m_pCommodity;
}
int Objective::getPayoff()const//get the payoff of the objective.
{
    return m_iPayoff;
}
void Objective::printObjective(ofstream& fileStream)//print the objective.
{
    fileStream << getCommodity()->getName() << " to " << getDestination() << " for " << getPayoff() << endl;
}
#endif // OBJECTIVE_CPP
