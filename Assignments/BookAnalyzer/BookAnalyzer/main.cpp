//
//  main.cpp
//  BookAnalyzer
//
//  Created by Vinutha Raja on 9/7/21.
//

#include <iostream>
#include <iostream>
#include "functions.hpp"
#include<vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // insert code here...
    ifstream ins ("book.txt");
    vector<string> readbook = book(ins);
    getTitle(readbook);
    getAuthor(readbook);
    cout <<"Total number of words: "<< totalNumberOfWords(readbook)<< endl;
    cout<< "Total number of characters: "<< totalNumberOfCharacters(readbook) << endl;
    cout<< "The Shortest Word is: "<< smallestWord(readbook)<< endl;
    cout<< "The Longest Word is: "<< largestWord(readbook)<< endl;
    cout<<"Enter a keyword";
    int totalChar = totalNumberOfCharacters(readbook);
    string keyword;
    cin>>keyword;
    int count = keyWordCount(readbook, keyword);
    cout<<"The keyword appears "<<+count<<" times";
    keywordLoc(readbook, keyword, totalChar);
    
    // part2 : finding stats of pronoun
    
    findProNoun(readbook);
    
    // encoding the book
    cout<< "Enter a secretkey"<<endl;
    int secretkey;
    cin>>secretkey;
    cipher(readbook, secretkey, "book.txt");
    return 0;
}
