#ifndef OBJECTIVE_CPP
#define OBJECTIVE_CPP
//#include "Commodity.h"
//#include "CommodityStore.h"
#include "Objective.h"
#include <iostream>

using namespace std;

Objective::Objective()
{
    //intentionally empty
}
Objective::Objective(string Destination, Commodity* Commodity, int Payoff)
{
    m_sDestination = Destination;
    m_pCommodity = Commodity;
    m_iPayoff = Payoff;
}
string Objective::getDestination()const
{
    return m_sDestination;
}
Commodity* Objective::getCommodity()const
{
    return m_pCommodity;
}
int Objective::getPayoff()const
{
    return m_iPayoff;
}
void Objective::printObjective(ofstream& fileStream)
{
    fileStream << getDestination() << getCommodity()->getName() << getPayoff() << endl;
}
#endif // OBJECTIVE_CPP
