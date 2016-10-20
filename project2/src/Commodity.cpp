#ifndef COMMODITY_CPP
#define COMMODITY_CPP
/************************************************
 ** File:    Commodity.cpp

 ** Project: CMSC 341 Project 2, Fall 2016

 ** Author:  Steven Heckman
 ** Date:    10/19/16
 ** Section: 05
 ** E-mail:  heckman1@umbc.edu
 **
 **   This file generates a "Commodity" object.
 **
 **   This file contains constructors a destructor and functions.
 **   This file gives an Commodity a name and a COLOR.
 **
 ***********************************************/
#include "Commodity.h"
#include <iostream>
#include <string>

using namespace std;

Commodity::Commodity()//default constructor, intentionally blank.
{
    //intentionally empty
}
Commodity::Commodity(string name, string color)//Non default constructor, takes in strings, converts color as a string to an enum value.
{
    m_sName = name;
    //If else block for assigning colors
    if (color == "Purple")
    {
        m_eColor = PURPLE;
    }
    else if (color == "Red")
    {
        m_eColor = RED;
    }
    else if (color == "Orange")
    {
        m_eColor = ORANGE;
    }
    else if (color == "Black")
    {
        m_eColor = BLACK;
    }
    else if (color == "Green")
    {
        m_eColor = GREEN;
    }
    else if (color == "Brown")
    {
        m_eColor = BROWN;
    }
    else//this should never come up
    {
        m_eColor = COLORLESS;
    }
}
Commodity::~Commodity()
{
    //delete
}
string Commodity::getName()const//gets the name of the commodity, in other words, what commodity it is
{
    return m_sName;
}
Commodity::COLOR Commodity::getColor()//gets the color of the commodity.
{
    return m_eColor;
}
#endif
