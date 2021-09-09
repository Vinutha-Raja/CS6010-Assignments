//
//  main.cpp
//  BitManipulation
//
//  Created by Vinutha Raja on 9/8/21.
//
//
//  bits.cpp
//  BitManipulation

/* The set of functions below are exercises to help you practice accessing
* and manipulating individual bits in program data, and to help understand
* how a computer represents numbers.
* Replace the TODO statements below with correct implementations of the functions.
* Each function's purpose is described in a comment.
* main() runs many tests on your functions and reports which ones failed or passed.
* Make sure you pass all tests.
*/


#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

/*
* Determines whether or not the specified bit is set in the input int
*
* Parameters:
*   input -- The input int
*   b -- The bit to retreive (0 = least significant, 31 = most significant)
*
* Returns:
*   true if the specified bit is set, false otherwise.
*
* Examples:
*   GetBit(5, 0) -> returns true, because the bit pattern for 5 is 101, we are looking at the rightmost bit
*   GetBit(5, 1) -> returns false
*   GetBit(-42, 31) -> returns true
*/
bool GetBit(uint32_t input, int b)
{

return (input >> b) & 1;
}


/*
* Determines whether or not an int is negative
*
* Do not use the < or > operators
*
* Parameters:
*   input -- The input int
*
* Returns:
*   Whether or not the int is negative
*/
bool IsNegative(int input)
{
return  GetBit(input, 31);
}

/*
* Determines the number of bits set (to 1) in a number
*
* Parameters:
*   input -- The input int
*
* Returns:
*   The number of set bits.
*
* Examples:
*   NumBitsSet(5) -> returns 2
*   NumBitsSet(64) -> returns 1
*   NumBitsSet(-1) -> returns 32
*/
int NumBitsSet(uint32_t input)
{
int count = 0;
for (int i = 0; i < 32; i++){
    if(GetBit(input, i)){
    count++;
    }
}
return count;
}


/*
* Returns a specified byte from a 4-byte value
*
* Parameters:
*   input -- The input value
*   b -- The byte to retreive (0 = least significant, 3 = most significant)
*
* Returns:
*   The specified byte within the input.
*
* Examples:
*   GetByte(5, 0) -> returns 5
*   GetByte(5, 1) -> returns 0
*   GetByte(0x1234abcd, 0) -> returns 0xcd (205 as unsigned char)
*   GetByte(0x1234abcd, 3) -> returns 0x12 (18 as an unsigned char)
*/
unsigned char GetByte(uint32_t input, int b)
{
    unsigned char c;
    uint32_t temp = input;
    // left shift to move the required byte to msb and right shift 24 to remove the remaining 3 bytes
    if(b == 3) {
        temp = temp << 0;
    }
    else if(b == 2) {
        temp = temp << 8;
    }
    else if(b == 1) {
        temp = temp << 16;
    }
    else if(b == 0) {
        temp = temp << 24;
    }
    temp = temp >> 24;
    c = (unsigned char)(temp);
//    cout<<"temp "<<temp<<endl;
//    cout<<"c "<<+c;
    return c;

}


/*
* Sets the specified byte in the input to the specified value, and returns the result
*
* Parameters:
*   input -- The input value
*   value -- The value to set the input's specified byte to
*   b -- The byte to set (0 = least significant, 3 = most significant)
*
* Returns:
*   The modified result
*
* Examples:
*   SetByte(0, 5, 0) -> returns 5
*   SetByte(0, 5, 1) -> returns 0x500 (1280 as unsigned int)
*   SetByte(0xffffffff, 0, 2) -> returns 0xff00ffff (4278255615 as unsigned int)
*   SetByte((unsigned int)-1, 0, 2) -> returns 0xff00ffff (4278255615 as unsigned int)
*   SetByte(0xabcd, 7, 1) -> returns 0x7cd (1997 as unsigned int)
*/
uint32_t SetByte(uint32_t input, uint8_t value, int b)
{
    uint32_t val = value;
    // left shift val by 8*b times to move the byte to the right position in 4 bytes and do bitwise or.
    val = val << (8*b);
    return val | input;

}

/* Challenge Question
Increment
This function should return x + 1 but should only make use of bitwise operators and == or !=
*/

int Increment(uint32_t x){
    int m = 1;
      
     // Flip all the set bits to 0 until a 0 is found
     while( x & m )
     {
         x = x ^ m;
         m <<= 1;
     }
     // flip the rightmost 0 bit to 1
     x = x ^ m;
     return x;
}

/*
* Computes the negation of an integer
*
* Do not use the * or *= operators
* Do not use the / or /= operators
* Do not use the + or += operators
* Do not use the - or -= operators
* Do not use the unary - operator
*
* Assumes that input is not equal to INT_MIN (a bit pattern of 100...0, or the minimum integer)
*
* Parameters:
*   input -- The input int
*
* Returns:
*   -i (negative i)
*
* Examples:
*   Negate(5) -> returns -5
*   Negate(-1) -> returns 1
*/
int Negate(int input)
{
    input = ~input;
    return Increment(input);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"GetBit(5, 0): "<<GetBit(5, 0)<<endl;
    cout<<"GetBit(5, 1): "<<GetBit(5, 1)<<endl;
    cout<<"GetBit(-42, 31): "<<GetBit(-42, 31)<<endl;
    
    
    cout<<"NumBitsSet(5): "<<NumBitsSet(5)<<endl;
    cout<<"NumBitsSet(64): "<<NumBitsSet(64)<<endl;
    cout<<"NumBitsSet(-1): "<<NumBitsSet(-1)<<endl;
    
    cout<<"GetByte(5, 0): "<<+GetByte(5, 0)<<endl;
    cout<<"GetByte(5, 1) : "<<+GetByte(5, 1) <<endl;
    
    cout<<"Negate(5): "<<Negate(5)<<endl;
    cout<<"Increment(5): "<<Increment(5)<<endl;
    
    cout<<"SetByte(30, 7, 1): "<<SetByte(30, 7, 1)<<endl;
    cout<<"SetByte(0, 5, 0): "<<SetByte(0, 5, 0)<<endl;
    cout<<"SetByte(0, 5, 1): "<<SetByte(0, 5, 1)<<endl;
    cout<<"SetByte(0xffffffff, 0, 2): "<<SetByte(0xffffffff, 0, 2)<<endl;
    
    
    return 0;
}
