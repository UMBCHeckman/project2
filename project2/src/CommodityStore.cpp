#ifndef COMMODITYSTORE_CPP
#define COMMODITYSTORE_CPP
/************************************************
 ** File:    CommodityStore.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "CommodityStore" object.
 **
 **   This file contains a constructor a map and functions.
 **   This file will map the name of a commodity to an enum "COLOR".
 **   This file will open a datafile of all the commodities and digest them into commodity objects.
 **
 ***********************************************/
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

CommodityStore::CommodityStore()//default constructor
{
    //intentionally blank
}
void CommodityStore::loadCommodities(string filename)//non default constructor, takes in the filename for the commodities text file.
{
    ifstream dataFile(filename.c_str());
    string line;//for getline
    string name;//what type of commodity it is
    string color;//the color of that commodity
    Commodity *myCommodity;
    while (dataFile)//reads through datafile
    {
        dataFile >> name;
        dataFile >> color;
        myCommodity = new Commodity(name, color);//calls a new commodity
        m_store.insert(pair<string, Commodity*>(name, myCommodity));//adding commodities to commodity store
    }
    dataFile.close();
}
Commodity* CommodityStore::getCommodity(string name){
    return m_store.find(name)->second;//gets the commodity object based on the name of the commodity.
}
#endif
