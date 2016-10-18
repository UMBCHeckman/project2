#ifndef CARD_H
#define CARD_H
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
    Card(istream &line);
    void addObjective(Objective* objective);
    Objective* getBestPayoff();
    Objective* getFirstAlphaDestination();
    Objective* getByColor(Commodity::COLOR color);
    void printCard(std::ofstream& fileStream);
private:
    vector<Objective*> m_objectives;
};

#endif // CARD_H
