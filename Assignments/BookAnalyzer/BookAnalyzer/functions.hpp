//
//  functions.hpp
//  BookAnalyzer
//
//  Created by Vinutha Raja on 9/7/21.
//

#ifndef functions_h
#define functions_h
#include <fstream>
#include<vector>
using namespace std;

vector<string> book (ifstream &ins);

int index(const vector<string> & words, string lookfor);

vector<string> getTitle(const vector<string> & words);

vector<string> getAuthor(const vector<string> & words);

int totalNumberOfWords(const vector<string> &words);

int totalNumberOfCharacters(const vector<string> &words);

string smallestWord(const vector<string> &words);

string largestWord(const vector<string> &words);

int keyWordCount(const vector<string> &words, string userWord);

void keywordLoc(const vector<string> &words, string userWord, int totalChar);

void findProNoun(const vector<string> &book);

// part 2 of book analyzer part 2 (cipher)
string getEncodedString(string word, int secretKey);

int stringToInt(const string &number, int base);

bool isDecimalWord(const string &word);

string decimalToBinaryString(string word);

void cipher(const vector<string> &book, int secretKey, string bookName);
#endif /* functions_h */
