#ifndef COMMODITYSTORE_H
#define COMMODITYSTORE_H
/************************************************
 ** File:    CommodityStore.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the CommodityStore object.
 **   See CommodityStore.cpp for details.
 **
 ***********************************************/
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
