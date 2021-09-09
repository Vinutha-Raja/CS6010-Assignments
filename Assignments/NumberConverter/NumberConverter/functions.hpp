//
//  functions.h
//  NumberConverter
//
//  Created by Vinutha Raja on 9/7/21.
//

#ifndef functions_h
#define functions_h
#include <iostream>
#include <string>
#include <string>

using namespace std;

int stringToInt(const string &number, int base);
string intToBinaryString(int number);
string intToHexadecimalString(int number);
int binaryToDecimal(string number);
string intToDecimalString(int number);
string getEncodedString(string word, int secretKey);
#endif /* functions_h */
