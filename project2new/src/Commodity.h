#ifndef COMMODITY_H
#define COMMODITY_H

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
