#include <iostream>
#include <string>
#include "Sales_data.h"


int main() { 

    Sales_data data1, data2; 

    double price = 0; // price per book, used to calculate total revenue
    // read the first transactions: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;

    // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price; 

    std::cout << "book name is: " << data1.bookNo << " revenue is: " << data1.revenue << std::endl;
    
    // read the second transaction, ISBN, number of books sold, price per book
    std::cin >> data2.bookNo >> data2.units_sold >> price; 

    // calculate the total 
    


    return 0;
}