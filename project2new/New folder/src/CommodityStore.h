#ifndef COMMODITYSTORE_H
#define COMMODITYSTORE_H

#include <string>
#include <vector>
#include "Commodity.h"
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;


class CommodityStore{
public:
    CommodityStore();
    void loadCommodities(string filename);
    Commodity* getCommodity(string name);
private:
    map<string, Commodity*> m_store;
};

#endif // COMMODITYSTORE_H
