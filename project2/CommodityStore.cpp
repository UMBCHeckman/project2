#include <string>
#include <vector>
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
    string line;
    filename = "commodities.txt";
    dataFile.open(filename);
    while (getline(dataFile, line))
    {
        dataFile >> line;
        cout << line << endl;
        dataFile >> line;
        cout << line << endl;
        //new Commodity(dataFile >> line, dataFile >> line)
    }
}
