//
//  main.cpp
//  Palindrome
//
//  Created by Vinutha Raja on 8/16/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str;
    std::cout << "Enter a word!\n";
    std::cin >> str;
    std::string reversed;
    for (int i=str.length()-1; i>=0; i--){
        reversed.push_back(str[i]);
    }
        
    if (str == reversed){
        std::cout << "Its a Palindrome";
    }
    return 0;
}
