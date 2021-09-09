//
//  main.cpp
//  NumberRepresentation
//
//  Created by Vinutha Raja on 9/7/21.
//

#include <iostream>
#include <cstdint>
#include <string>
#include<vector>
#include <cassert>
#include <iomanip>
#include<cmath>
#include <fstream>
using namespace std;

bool approxEquals(double a, double b, double tolerance){
    cout<<"abs"<<abs(a-b);
    return (abs(a-b) < tolerance);
}

//Part 2: Message encryption
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

void readTextFile(ifstream & ins){
    char c;
    
    int countUni = 0;
    int numNonUni = 0;
    while( ins >> c){
        if( c < 0 ) {
            countUni++;
        }
        else {
            numNonUni++;
        }
        //cout<< c<< endl;
    }
    cout << "Num of Uni chars: " << countUni << "\n";
    cout << "Num of non-uni chars: " << numNonUni << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "The size of a character is: "<< sizeof(char)<< endl;
    int x;
    cout<< "The size of an integer is: "<< sizeof(x)<< endl;
    string h;
    cout << "The size of a string is: "<< sizeof(h)<< endl;
    vector<string> vec;
    cout<< "The size of a vector is: "<< sizeof(vec) << endl;
    long y;
    cout << "The size of a long is: "<< sizeof(y)<< endl;
    int8_t a;
    cout << "The size of int8_t a is: "<< sizeof(a)<< endl;
    uint8_t b;
    cout << "The size of unsigned uint8_t b is: "<< sizeof(b)<< endl;
    int16_t c;
    cout << "The size of int int16_t is: "<< sizeof(c)<< endl;
    uint16_t d;
    cout << "The size of unsigned uint16_t d is: "<< sizeof(d)<< endl;
    int64_t e;
    cout << "The size of int64_t e is: "<< sizeof(e)<< endl;
    uint8_t max8 = 0xFF;
    cout << +max8<< endl;
    uint8_t min8= 0x00;
    cout <<+min8<< endl;
    uint16_t max16 = 0xFFFF;
    uint16_t min16 = 0x0000;
    cout<< +min16<< endl;
    cout<< +max16<< endl;
    uint64_t max64 = 0xFFFFFFFFFFFFFFFF;
    uint64_t min64 = 0x0000000000000000;
    cout<< +min64<< endl;
    cout<< +max64<<endl;
    // The min and max of signed:
    int8_t maxs8 = 0x7F;
    cout << +maxs8<< endl;
    int8_t mins8= 0x80;
    cout <<+mins8<< endl;
    int16_t maxs16 = 0x7FFF;
    int16_t mins16 = 0x8000;
    cout<< +mins16<< endl;
    cout<< +maxs16<< endl;
    int64_t maxs64 = 0x7FFFFFFFFFFFFFFF;
    int64_t mins64 = 0x8000000000000000;
    cout<< +mins64<< endl;
    cout<< +maxs64<<endl;
    // incrementing max values
    maxs8++;
    cout<< +maxs8 << endl;
    maxs16++;
    cout << +maxs16<< endl;
    maxs64++;
    cout << +maxs64<< endl;
    // decrementing min values
    mins8--;
    cout<< +mins8<< endl;
    mins16--;
    cout<< +mins16<< endl;
    mins64--;
    cout<< +mins64<< endl;
    
    float j = 0.1+0.2;
    cout << setprecision(18)<< j<<  endl;
    
    
//    assert(j == 0.3);
    assert(approxEquals(0.3, j, 0.00001) == true);
    
    ifstream ins("./utf.txt");
    if(ins.fail()){
        cout<<"failed to open file";
    }
    readTextFile(ins);
    
    //part 2: Encryption
    
    return 0;
}
