#ifndef OBJECTIVE_H
#define OBJECTIVE_H
/************************************************
 ** File:    Objective.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the Objective object.
 **   See Objective.h for details.
 **
 ***********************************************/
#include "Commodity.h"
#include "CommodityStore.h"
#include <iostream>

using namespace std;

class Objective{
public:
    Objective();
    Objective(string Destination, Commodity* Commodity, int Payoff);
    string getDestination()const;
    Commodity* getCommodity()const;
    int getPayoff()const;
    void printObjective(ofstream& fileStream);
private:
    string m_sDestination;
    Commodity* m_pCommodity;
    int m_iPayoff;
};
#endif // OBJECTIVE_H
