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
    Commodity *myCommodity;
    while (dataFile)
    {
        dataFile >> name;
        dataFile >> color;
        myCommodity = new Commodity(name, color);
        m_store.insert(pair<string, Commodity*>(name, myCommodity));
        //new Commodity(dataFile >> line, dataFile >> line)
    }
    dataFile.close();
}
Commodity* CommodityStore::getCommodity(string name){
    //cerr << m_store.find(name)->second->getName() << " " << m_store.find(name)->second->getColor() << endl;
    return m_store.find(name)->second;
}
#endif
