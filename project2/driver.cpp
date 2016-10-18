#include "Commodity.h"
#include "CommodityStore.h"
#include "Objective.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

void printGreeting(){
    cout << "WELCOMB THIS IS A GREEITG!!00" << endl;
    cout << "Name: Steven Heckman. Section 5." << endl;
}
int main(int arg, char ** argv)
{
    printGreeting();
    string test = "test";
    CommodityStore MyStore = CommodityStore();
    MyStore.loadCommodities(test);
    //cerr << MyStore.getCommodity("Beer")->getColor();
    return 0;
}
