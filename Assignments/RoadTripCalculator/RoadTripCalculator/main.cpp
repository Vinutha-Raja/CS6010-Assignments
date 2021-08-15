//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Vinutha Raja on 8/15/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int distance;
    int efficiency;
    int gas_cost;
    std::cout << "Enter the driving distance, in miles\n";
    std::cin >> distance;
    std::cout << "Enter the vehicle's miles per gallon efficiency\n";
    std::cin >> efficiency;
    std::cout << "Enter the cost of gas in dollars per gallon\n";
    std::cin >> gas_cost;
    int gallons_used = distance/efficiency;
    int total_cost = gallons_used*gas_cost;
    std::cout << "Total cost of the trip is: "<< total_cost;
    
    return 0;
}
