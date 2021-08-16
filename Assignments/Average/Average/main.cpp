//
//  main.cpp
//  Average
//
//  Created by Vinutha Raja on 8/15/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int score1;
    int score2;
    int score3;
    int score4;
    int score5;
    std::cout << "Enter the scores\n";
    std::cin >> score1;
    std::cin >> score2;
    std::cin >> score3;
    std::cin >> score4;
    std::cin >> score5;
    float avg = (score1 + score2 + score3 + score4 + score5)/5.0;
    std::cout << "The avg is :" << avg;
    return 0;
}
