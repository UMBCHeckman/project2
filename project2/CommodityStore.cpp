#ifndef COMMODITYSTORE_CPP
#define COMMODITYSTORE_CPP

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "CommodityStore.h"
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

CommodityStore::CommodityStore()
{

}
void CommodityStore::loadCommodities(string filename)
{
    ifstream dataFile;
    string line;//for getline
    string name;//what type of commodity it is
    string color;//the color of that commodity
    filename = "commodities.txt";
    dataFile.open("commodities.txt");//, ios_base::in);
    while (getline(dataFile, line))
    {
        dataFile >> name;
        cout << name << endl;
        dataFile >> color;
        cout << color << endl;
        *myCommodity = new Commodity(name, color);
        m_store.insert(filename, myCommodity);
        //new Commodity(dataFile >> line, dataFile >> line)
    }
Commodity* getCommodity(string name){

}
}
#endif
