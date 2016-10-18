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
Card::Card(string Destination1, string Commodity1, string Payoff1, string Destination2, string Commodity2, string Payoff2, string Destination3, string Commodity3, string Payoff3)
{

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
void Card::printCard()//std::ofstream& fileStream)
{
    cerr << "Card" << endl;
    for(int i = 0; i < m_objectives.size(); i++){
        m_objectives[i]->printObjective();
    }
    //for (std::vector<Objective*>::const_iterator i = m_objectives.begin(); i != m_objectives.end(); ++i)
    //cerr << &i->printObjective() << ' ';
}

#endif
