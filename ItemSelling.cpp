//Author: Joshua E. Pierce
#include "ItemSelling.h"
#include <string>

ItemSelling::ItemSelling(int price, std::string itemSellingName)
{
    cost = price;
    name = itemSellingName;
}

double ItemSelling::getCost()
{
    return cost;
}

std::string ItemSelling::getName()
{
    return name;
}