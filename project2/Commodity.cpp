#ifndef COMMODITY_CPP
#define COMMODITY_CPP

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
    else
    {
        m_eColor = COLORLESS;
    }
}
Commodity::~Commodity()
{
    //dtor
}
string Commodity::getName()const
{
    return m_sName;
}
Commodity::COLOR Commodity::getColor()
{
    return m_eColor;
}
#endif
