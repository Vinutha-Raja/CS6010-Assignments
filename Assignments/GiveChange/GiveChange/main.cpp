//
//  main.cpp
//  GiveChange
//
//  Created by Vinutha Raja on 8/15/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int cost ;
    int amount_paid;
    std::cout << "What is the cost of the item in cents?!\n";
    std::cin >> cost;
    std::cout << "What is the amount paid in cents?!\n";
    std::cin >> amount_paid;
    
    int diff = amount_paid - cost;
    std::cout << "change: " << diff;
    
    int quarters = diff /25;
    diff = diff - quarters * 25;
    int dimes = diff/10;
    diff = diff - dimes * 10;
    int nickels = diff/5;
    diff = diff - nickels * 5;
    std::cout << "\nquarters: " << quarters;
    std::cout << "\ndimes: " << dimes;
    std::cout << "\nnickels: " << nickels;
    std::cout << "\ncents: " << diff;
  
    return 0;
    // Range of dimes = 0-2
    // Range of nickels = 0-1
    // Range of pennies = 0-4
    // Range of quarters = 0-any.
}
