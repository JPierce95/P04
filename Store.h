//Author: Joshua E. Pierce
#include <string>
#include <vector>
#include <iostream>
#include "ItemSelling.h"

#ifndef _STORE_
#define _STORE_
class Store
{
private:
    double price;
    std::string storeName;
    std::vector < ItemSelling > movies;
    std::vector < ItemSelling > snacks;
    std::vector < ItemSelling > checkout;
    
public:
    Store();
    double getTotalCost();
    void addMovieToCheckout(int);
    void addSnackToCheckout(int);
    void removeFromCheckout(int);
    void printMovies();
    void printSnacks();
    void printCheckout();
    int getCheckoutSize();
    std::string getCheckoutItemName(int &);
    std::string getSnackName(int);
    std::string getMovieName(int);
    std::string getStoreName();
};
#endif