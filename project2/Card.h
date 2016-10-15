#ifndef CARD_H
#define CARD
#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include <iostream>

using namespace std;

class Card(){
public:
    void addObjective(Objective* objective);
    Objective* getBestPayoff();
    Objective* getFirstAlphaDestination();
    Objective* getByColor(Commodity::COLOR color);
    void printCard(std::ofstream& fileStream);
private:
    std:vector<Objective*> m_objectives;
};

#endif // CARD_H
