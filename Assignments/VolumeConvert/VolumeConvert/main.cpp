//
//  main.cpp
//  VolumeConvert
//
//  Created by Vinutha Raja on 8/15/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    float ounce;
    std::cout << "Hello, Enter the number of ounces\\n";
    std::cin >> ounce;
    std::cout << "ounces : " << ounce;
    std::cout << "\nCups : " << ounce/8;
    std::cout << "\nPints : " << ounce/16;
    std::cout << "\nGallons : " << ounce/128;
    std::cout << "\nLiters : " << ounce*0.0296;
    std::cout << "\nCubic Inches : " << ounce*1.8;
    return 0;
}
