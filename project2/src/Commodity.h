#ifndef COMMODITY_H
#define COMMODITY_H
/************************************************
 ** File:    Commodity.h

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file is the header file for the Commodity object.
 **   See Commodity.cpp for details.
 **
 ***********************************************/
#include <string>
using namespace std;

//remember to add default and non constructors

class Commodity{
public:
    Commodity();
    Commodity(string name, string color);
    ~Commodity();

        enum COLOR{
            PURPLE,
            RED,
            ORANGE,
            BLACK,
            GREEN,
            BROWN,
            COLORLESS
        };
    string getName()const;
    COLOR getColor();
private:
    string m_sName;
    COLOR m_eColor;
};
#endif
