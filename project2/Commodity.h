#ifndef COMMODITY_H
#define COMMODITY
#include <string>
using namespace std;

//remember to add default and non constructors

class Commodity{
public:
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
#endif
