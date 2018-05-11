//Author: Joshua E. Pierce
#include "Store.h"
#include <string>
#include <vector>

Store::Store()
{
    price = 0;
    storeName = "Josh's Theatre of Wonders";
    movies.push_back(ItemSelling(9.50, "Infinity War"));
    movies.push_back(ItemSelling(7.50, "Scott Pilgrim vs The World"));
    movies.push_back(ItemSelling(8.00, "Deadpool"));
    movies.push_back(ItemSelling(7.00, "Now You See Me"));
    movies.push_back(ItemSelling(8.50, "Ninja Turtles"));
    
    snacks.push_back(ItemSelling(3.00, "Soda"));
    snacks.push_back(ItemSelling(5.00, "Popcorn"));
    snacks.push_back(ItemSelling(2.50, "Red Vines"));
    snacks.push_back(ItemSelling(2.00, "Milk Duds"));
    snacks.push_back(ItemSelling(8.00, "Commemorative Cup"));
}

double Store::getTotalCost()
{
    price = 0;
    for(int i = 0; i < checkout.size(); i++)
    {
        price += checkout[i].getCost();
    }
    return price;
}

void Store::addMovieToCheckout(int itemToAdd)
{
    itemToAdd--;
    checkout.push_back(movies[itemToAdd]);
}

void Store::addSnackToCheckout(int itemToAdd)
{
    itemToAdd--;
    checkout.push_back(snacks[itemToAdd]);
}

void Store::removeFromCheckout(int itemToRemove)
{
    std::vector < ItemSelling > temp;
    for(int i = 0; i < checkout.size(); i++)
    {
        if(i != itemToRemove)
        {
            temp.push_back(checkout[i]);
        }
    }
    checkout.clear();
    for(int i = 0; i < temp.size(); i++)
    {
        checkout.push_back(temp[i]);
    }
}

void Store::printMovies()
{
    for(int i = 0; i < movies.size(); i++)
    {
        std::cout << i + 1 << ")" << movies[i].getName() << ", ";
    }
    std::cout << "\n" << std::endl;
}

void Store::printSnacks()
{
    for(int i = 0; i < snacks.size(); i++)
    {
        std::cout << i + 1 << ")" << snacks[i].getName() << ", ";
    }
    std::cout << "\n" << std::endl;
}

void Store::printCheckout()
{
    for(int i = 0; i < checkout.size(); i++)
    {
        std::cout << i + 1 << ")" << checkout[i].getName() << "  ";
    }
    std::cout << std::endl;
}

int Store::getCheckoutSize()
{
    return checkout.size();
}

std::string Store::getCheckoutItemName(int &item)
{
    item--;
    return checkout[item].getName();
}

std::string Store::getSnackName(int item)
{
    item--;
    return snacks[item].getName();
}

std::string Store::getMovieName(int item)
{
    item--;
    return movies[item].getName();
}

std::string Store::getStoreName()
{
    return storeName;
}