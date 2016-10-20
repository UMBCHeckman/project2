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
    Objective *bestObjective;
    int bestSoFar = 0;
    for(unsigned int j = 0; j < m_objectives.size(); j++)
    {
        if((m_objectives[j]->getPayoff()) > bestSoFar)
        {
            bestSoFar = (m_objectives[j]->getPayoff());
            bestObjective = m_objectives[j];
        }
    }
    return bestObjective;
}
Objective* Card::getFirstAlphaDestination()
{
    Objective *bestObjective;
    string bestSoFar = "zzzzzzzzzzzzzzzzzzzzzzzzz";
    for(unsigned int j = 0; j < m_objectives.size(); j++)
    {
        if((m_objectives[j]->getDestination().compare(bestSoFar)) < 0)
        {
            bestSoFar = m_objectives[j]->getDestination();
            bestObjective = m_objectives[j];
        }
    }
    return bestObjective;
}
Objective* Card::getByColor(Commodity::COLOR color)
{
    Objective *bestObjective;
    int bestSoFar = 0;
    for(unsigned int j = 0; j < m_objectives.size(); j++)
    {
        if((m_objectives[j]->getCommodity()->getColor()) == color)
        {
            if((m_objectives[j]->getPayoff()) > bestSoFar){
            bestSoFar = m_objectives[j]->getPayoff();
            bestObjective = m_objectives[j];
            }
        }
    }
    if (bestSoFar == 0){
        return getBestPayoff();
    }
    return bestObjective;
}
void Card::printCard(std::ofstream& fileStream)
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
