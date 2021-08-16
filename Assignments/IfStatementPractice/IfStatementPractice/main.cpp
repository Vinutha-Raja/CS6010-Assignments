//
//  main.cpp
//  IfStatementPractice
//
//  Created by Vinutha Raja on 8/15/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int age;
    std::cout << "Enter your age\n";
    std::cin >> age;
    if (age > 30){
        std::cout << "Eligible to run for senate";
    }
    if (age > 18){
        std::cout << ", eligible to vote";
    }
    if (age > 80){
        std::cout << " and belongs to greatest generation";
    }else if(age > 60){
        std::cout << " and belongs to baby boomers";
    }else if(age > 40) {
        std::cout << " and belongs to generation X";
    }else if (age > 20) {
        std::cout << " and belongs to Millenials";
    } else{
        std::cout << "is a iKid";
    }
    
    // Character input (getchar() ?)
    
    char weekdayResponse;
    char holidayResponse;
    char children;
    std::cout << "Is it a weekday?\n";
    std::cin >> weekdayResponse ;
    std::cout << "Is it a holiday?\n";
    std::cin >> holidayResponse ;
    std::cout << "do you have a young children?\n";
    std::cin >> children ;
    
    bool isWeekDay =  true; if (weekdayResponse == 'Y'); else isWeekDay = false;
    bool isholiday = true; if (holidayResponse == 'Y'); else isholiday = false;
    bool haveChildren = true; if (children == 'Y'); else haveChildren = false;
    
    if ((!isWeekDay && !haveChildren) || (isholiday && !haveChildren)){
        std::cout<< "You are good to sleep";
    } else {
        std::cout<< "sorry";
    }
    return 0;
}
