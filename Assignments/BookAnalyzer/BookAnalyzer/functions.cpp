//
//  functions.cpp
//  BookAnalyzer
//
//  Created by Vinutha Raja on 9/7/21.
//
#include "functions.hpp"
#include<iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include<vector>
#include <cmath>
using namespace std;

vector<string> book (ifstream &ins){
    vector<string>words;
    string word;
    while (ins >> word){
        words.push_back(word);
    }
    return words;
}

int index(const vector<string> & words, string lookfor){
    for (int i=0; i < words.size(); i++){
        if(words[i] == lookfor){
            return i;
        }
    }
    return -1;
}

vector<string> getTitle(const vector<string> & words){
   int start= index(words, "Title:");
    int end = index(words, "Author:");
    vector<string>title;
    for (int i=start+1; i<end;i++){
            title.push_back(words[i]);
        }
    cout<<"Title: ";
    for (int i=0; i<title.size();i++){
        cout << title[i]<< " ";
    }
    cout<<endl;
    return title;
}

vector<string> getAuthor(const vector<string> & words){
    int start= index(words, "Author:");
    int end = index(words, "Release");
    vector<string>author;

    for (int i=start+1; i<end;i++){
        author.push_back(words[i]);
    }
    cout<<"Author: ";
    for (int i=0; i<author.size();i++){
        cout << author[i]<< " ";
    }
    cout<< endl;
    return author;
}

int totalNumberOfWords(const vector<string> &words){
    int totWords = (int)words.size();
    return totWords;
}

int totalNumberOfCharacters(const vector<string> &words){
    int counter = 0;
    for (string s : words){
        counter+=s.size();
    }
    return counter;
}

string smallestWord(const vector<string> &words){
    int minLoc = 0;
    for (int i =1; i<words.size(); i++){
        if(words[i].size() < words[minLoc].size()){
            minLoc=i;
        }
    }
    string smallWord = words[minLoc];
    return smallWord;
}

string largestWord(const vector<string> &words){
    int maxLoc = 0;
    for (int i =0;i<words.size();i++){
        if(words[i].size()>words[maxLoc].size()){
            maxLoc=i;
        }
        
    }
    string largeWord = words[maxLoc];
    return largeWord;
}

int keyWordCount(const vector<string> &words, string userWord){
    int wordCount=0;
    for (int i=0; i< words.size(); i++){
        if(words[i]==userWord){
            wordCount++;
        }
    }
    return wordCount;
}

void keywordLoc(const vector<string> &words, string userWord, int totalChar){
    int charCount=0;
//    vector<WordLocation>location;
    for (int i=0;i<words.size();i++){
         charCount+=words[i].size();
        if (words[i]== userWord){
            cout<<" at "<<(charCount/(totalChar*1.0))*100<<": "<<words[i-1]<<" "<<words[i]<<" "<<words[i+1]<<endl;
        }
       
    }
}

bool isTerminator(char c){
    return c == '.' || c == '?' || c == '!';
}

// Part  1 of book analyzer part 2
void findProNoun(const vector<string> &book){
    int times = 0;
    int totChars = totalNumberOfCharacters(book);
    vector<string> pronoun, prevWord, nextWord;
    vector<int> location;
    int num = 0; // store the location of the found word
    for(int i = 1; i < book.size(); i++){
        if(book[i][0] >= 'A' && book[i][0] <= 'Z' && !isTerminator(book[i - 1][book[i - 1].size() -1])){
            times++;
            pronoun.push_back(book[i]);
            prevWord.push_back(i > 0 ? book[i - 1] : "");
            nextWord.push_back(i < book.size() - 1 ? book[i + 1] : "");
            location.push_back((num * 100) / totChars); // percentage
        }
        num += book[i].size();
    }

    // Print Proper Nouns:
    cout << "There are " << times << " pronouns:" << endl;
    for(int i = 0; i < times; i++){
        cout << "  at " << location[i] << "%: \"" << prevWord[i] << " " << pronoun[i] << " " << nextWord[i] << "\"" << endl;
    }
}


// part 2 of book analyzer part 2


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

bool isDecimalWord(const string &word){
    for(char c : word){
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string decimalToBinaryString(string word){
    int number = stringToInt(word, 10);
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

void cipher(const vector<string> &book, int secretKey, string bookName){
    bookName = bookName.insert(bookName.rfind(".txt"), "_encoded");
    ofstream outs(bookName);
    if(!outs){
        cerr << "failed to write the decoded book to " << bookName << endl;
        exit(0);
    }
    for(string  word : book){
        if(isDecimalWord(word)){
            outs << decimalToBinaryString(word) << " ";
        }else{
            outs << getEncodedString(word, secretKey) << " ";
        }
    }
    outs.close();
}

