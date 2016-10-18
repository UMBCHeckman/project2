#ifndef CARD_CPP
#define CARD_CPP

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "CommodityStore.h"
#include "Card.h"
#include "Objective.h"
#include "CommodityStore.h"
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

Card::Card()
{
    //intentionally empty
}
Card::Card(istream &line)
{
    Objective *myObjective;
    //ifstream iss;
    //iss = ifstream(line);
    //getline(cin,line);
    //istringstream iss(line);
    string Destination,Commodity,Payoff;
    while(line) {
    line >> Destination;//lines within cards.txt should all follow this structure
    line >> Commodity;
    line >> Payoff;
    myObjective = new Objective((Destination), (Commodity), (atoi(Payoff.c_str())));//Payoff must be converted from a string to an integer
    addObjective(myObjective);
    }
}
void Card::addObjective(Objective* objective)
{
    m_objectives.push_back(objective);
}
Objective* Card::getBestPayoff()
{

}
Objective* Card::getFirstAlphaDestination()
{

}
Objective* Card::getByColor(Commodity::COLOR color)
{

}
void Card::printCard(std::ofstream& fileStream)
{

}

#endif
