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
    Card(string Destination1, string Commodity1, string Payoff1, string Destination2, string Commodity2, string Payoff2, string Destination3, string Commodity3, string Payoff3);
    void addObjective(Objective* objective);
    Objective* getBestPayoff();
    Objective* getFirstAlphaDestination();
    Objective* getByColor(Commodity::COLOR color);
    void printCard();//std::ofstream& fileStream);
private:
    vector<Objective*> m_objectives;
};

#endif // CARD_H
