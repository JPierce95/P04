//Author: Joshua E. Pierce
#include <string>

#ifndef _ITEM_SELLING_
#define _ITEM_SELLING
class ItemSelling
{
private:
    double cost;
    std::string name;
    
public:
    ItemSelling(int, std::string);
    double getCost();
    std::string getName();

};
#endif