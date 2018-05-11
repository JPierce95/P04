//Author: Joshua E. Pierce
#include <string>
#include <iostream>
#include "Store.h"

void buyTicket();
void buySnacks();
void editCheckout();
void buyer(bool);

Store theatre;

int main()
{
    char input = ' ';
    do
    {
        std::cout << "Would you like to \'A\' Buy a movie ticket, \'B\' Reserve some concessions, or \'C\' Look at your checkout?" << std::endl;
        std::cout << "Enter \'Q\' once you're finished." << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        if(!(tolower(input) == 'a' || tolower(input) == 'b' || tolower(input) == 'c' || tolower(input) == 'q'))
        {
            std::cout << "\'" << input << "\' Is not a valid response.\n" << std::endl;
        }  
        else if(tolower(input) == 'a')
        {
            buyTicket();
        }
        else if(tolower(input) == 'b')
        {
            buySnacks();
        }
        else if(tolower(input) == 'c')
        {
            editCheckout();
        }
    }
    while(!(tolower(input) == 'q'));
    
    std::cout << "The total cost of your visit will be $" << theatre.getTotalCost() << ".\nThank you for choosing " << theatre.getStoreName() << "!" << std::endl;
    
    return 0;
}

void buyTicket()
{
    char input = ' ';
    do
    {
        std::cout << "Would you like to \'A\' look at the list of movies, or \'B\' buy a ticket for a movie?" << std::endl;
        std::cout << "Once you're done with this menu enter \'Q\' to go back to the last screen." << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        if(!(tolower(input) == 'a' || tolower(input) == 'b' || tolower(input) == 'q'))
        {
            std::cout << "\'" << input << "\' is not a valid response." << std::endl;
        }
        else if(tolower(input) == 'a')
        {
            theatre.printMovies();
        }
        else if(tolower(input) == 'b')
        {
            buyer(true);
        }
    }
    while(tolower(input) != 'q');
}

void buySnacks()
{
    char input = ' ';
    do
    {
        std::cout << "Would you like to \'A\' look at the list of snacks, or \'B\' reserve a snack?" << std::endl;
        std::cout << "Once you're done with this menu enter \'Q\' to go back to the last screen." << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        if(!(tolower(input) == 'a' || tolower(input) == 'b' || tolower(input) == 'q'))
        {
            std::cout << "\'" << input << "\' is not a valid response." << std::endl;
        }
        else if(tolower(input) == 'a')
        {
            theatre.printSnacks();
        }
        else if(tolower(input) == 'b')
        {
            buyer(false);
        }
    }
    while(tolower(input) != 'q');
}

void editCheckout()
{
    char input = ' ';
    if(theatre.getCheckoutSize() == 0) //Checks to see if there's even anyhing in checkout
    {
        std::cout << "It appears there's nothing in your checkout at this moment.\n" << std::endl;
    }
    else
    {
        do
        {
            std::cout << "Would you like to \'A\' look at your checkout list, or \'B\' remove an item from checout?" << std::endl;
            std::cout << "Once you're done with this menu enter \'Q\' to go back to the last screen." << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            if(!(tolower(input) == 'a' || tolower(input) == 'b' || tolower(input) == 'q'))
            {
                std::cout << "\'" << input << "\' is not a valid response." << std::endl;
            }
            else if(tolower(input) == 'a')
            {
                theatre.printCheckout();
                std::cout << std::endl;
            }
            else if(tolower(input) == 'b') //Goes to the menu that prompts the user to remove an item
            {
                int remover = 0;
                do
                { //If the list is empty, will print something else.
                    std::cout << "Which would you like to remove?\nEnter a number 1-" << theatre.getCheckoutSize() << " cooresponding to what you'd like to remove." << std::endl;
                    std::cout << "If you'd like to back out of this menu enter \'-1\'" << std::endl;
                    std::cin >> remover;
                    std::cout << std::endl;
                    if(remover < 1 || remover > theatre.getCheckoutSize()) //Checks for valid response
                        {
                        std::cout << remover << " is not a valid entry." << std::endl;
                    }
                    else
                    { //removes item from checkout
                        std::cout << theatre.getCheckoutItemName(remover) << " has been removed from your checkout." << std::endl;
                        theatre.removeFromCheckout(remover);
                        std::cout << std::endl;
                        break;
                    }
                }
                while(remover != -1);
            }
        }
        while(tolower(input) != 'q');
    }
}

void buyer(bool addMovie)
{
    int purchase = 0;
    do
    {
        std::cout << "Which would you like to purchase?\nEnter a number 1-5 cooresponding to what you'd like." << std::endl;
        std::cout << "If you'd like to back out of this menu enter \'-1\'" << std::endl;
        std::cin >> purchase;
        std::cout << std::endl;
        if(purchase < 1 || purchase > 5)
        {
            std::cout << purchase << " is not a valid entry." << std::endl;
        }
        else if(addMovie == true)
        {
            std::cout << theatre.getMovieName(purchase) << " has been added to your checkout.\n" << std::endl;
            theatre.addMovieToCheckout(purchase);
            break;
        }
        else if(addMovie == false)
        {
            std::cout << theatre.getSnackName(purchase) << " has been added to your checkout.\n" << std::endl;
            theatre.addSnackToCheckout(purchase); 
            break;
        }
    }
    while(purchase != -1);
}