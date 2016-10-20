#ifndef OBJECTIVE_H
#define OBJECTIVE_H
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
