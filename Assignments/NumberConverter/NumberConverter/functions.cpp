//
//  functions.cpp
//  NumberConverter
//
//  Created by Vinutha Raja on 9/7/21.
//

#include "functions.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const vector<string> hexvec = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

int stringToInt(const string &number, int base){
    int sign = 1, startindex = 0, exponent = 0, result = 0;
    if(number[0] == '-'){ // checking if first digit has the sign
        sign = -1;
        startindex = 1;
    }
    for (int i = (int) number.size() - 1; i >= startindex; i--) {
        int digit;
        if (number[i] >= '0' && number[i] <= '9') {
            digit = number[i] - '0';
        }
        else if (number[i] >= 'a' && number[i] <= 'f'){
            digit = number[i] - 'a' + 10;
        }
        else {
            digit = number[i] - 'A' + 10;
        }
        result += digit * pow(base, exponent);
        exponent++;
    }
    return result * sign;
}


string intToBinaryString(int number){
    string result = "";
    int num = abs(number);
    while(num !=0 ){
        num % 2 == 1 ? result = '1' + result : result = '0' + result;
        num /= 2;
    }
    if ( number < 0 ){
        return '-' + result;
    }
    return result;
}

string intToHexadecimalString(int number){
    string result = "";
    int num = abs(number);
    if ( num < 16) {
        result = hexvec[num];
    } else {
        while(num !=0 ){
            int remanider = num % 16 ;
            result = hexvec[remanider] + result;
            num /= 16;
        }
    }
    if ( number < 0 ){
        return '-' + result;
    }
    return result;
}

//string intToHexidecimalString1(int number){
//    string result;
//    sprintf(result, "%X", number);
//    cout<<result;
//    return result;
//}

int binaryToDecimal(string number){
    int result = 0;
    int exponent = 0;
    for (int i = (int) number.size() - 1; i >= 0; i--, exponent++) {
        result += number[i] * pow(2, exponent);
    }
    return result;
}

string intToDecimalString(int number){
    std::string s = std::to_string(number);
    return s;
}
    
//Part 2: Message encryption(Belongs to Num representation assignment)
string getEncodedString(string word, int secretKey){
    string encodedWord = "";
    char encodedChar;
    for(char ch : word){
        if(ch >= 'a' && ch <= 'z'){
            ch -= 'a';
            encodedChar = (ch + secretKey) % 26 + 'a';
            encodedWord += encodedChar;
        }else if(ch >= 'A' && ch <='Z'){
            ch -= 'A';
            encodedChar = (ch + secretKey) % 26 + 'A';
            encodedWord += encodedChar;
        }else{
            encodedWord += ch; //  leaving any numbers and punctuation unmodified
        }
    }
    return encodedWord;
}
