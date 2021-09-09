//
//  main.cpp
//  NumberConverter
//
//  Created by Vinutha Raja on 9/7/21.
//

#include <iostream>
#include "functions.hpp"

int main() {
    // insert code here...
    int value = stringToInt( "99" , 10 );
    cout<<value<<endl;
    int value2 = stringToInt( "1100", 2 );
    cout<<value2<<endl;
    int value3 = stringToInt( "FF", 16 );
    cout<<value3<<endl;
    cout<<"intToDecimalString( 10 ): "<<intToDecimalString( 10 )<<endl;
    cout<<"intToHexidecimalString( -10 ): " <<intToHexadecimalString( -10 )<<endl;
    cout<<"intToHexadecimalString( 243 ): " <<intToHexadecimalString( 243 )<< endl;
    cout<<"stringToInt( intToHexadecimalString( 243 ), 16 ): "<< stringToInt( intToHexadecimalString( 243 ), 16 )<<endl;
    cout<<"stringToInt( intToHexadecimalString( 576 ), 16 ): "<< stringToInt( intToHexadecimalString( 576 ), 16 )<<endl;
    
    // part 2: encryption(Belongs to Num representation assignment)
    
    cout<< "enter line to translate"<<endl;
    string rawString;
    getline(cin, rawString);
    cout<<rawString;
    cout<< "Enter a secret key"<<endl;
    int secretKey;
    cin>>secretKey;
    cout<< "Encoded string is : "<<getEncodedString(rawString, secretKey)<<endl;
    return 0;
}
