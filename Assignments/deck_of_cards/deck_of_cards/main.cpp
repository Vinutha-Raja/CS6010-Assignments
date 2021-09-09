//
//  main.cpp
//  deck_of_cards
//
//  Created by Vinutha Raja on 9/1/21.
//

#include <iostream>
#include "cards.hpp"
// test analyze functions
void test();

// shuffle a deck many times.
// After each shuffle, check whether the hand is one of the hands you test for above and keep track of the total numbers of flushes, straights, royal flushes, etc.
void statistic(Deck &d, int times);

int main(int argc, const char * argv[]) {
    std::cout << "Test Build a New Deck and Print It: \n";
    Deck deck = createDeck();
    
    printDeck(deck);
    shuffle(deck);
    cout << "After shuffling: \n" <<endl;
    printDeck(deck);

    test(); // test analyze functions
    // Print statitical analysis
    statistic(deck, 10000);
    
    return 0;
}

// display test error messages
void testError(string msg){
    cout << "Test Failed: " << msg << endl;
    exit(1);
}

// test analyze functions
void test(){
    
    cout << "///////////////////////////////////////////////\n" << "Begin test" << endl;
    Deck stFl = {  {
        {2, suits[0]},
        {3, suits[0]},
        {4, suits[0]},
        {5, suits[0]},
        {6, suits[0]}
    } };
    
    Deck st = {   {
        {2, suits[0]},
        {3, suits[3]},
        {4, suits[1]},
        {5, suits[3]},
        {6, suits[2]}
    } };
    
    Deck fl = {  {
        {10, suits[0]},
        {4, suits[0]},
        {2, suits[0]},
        {4, suits[0]},
        {14, suits[0]}
    } };
    
    Deck roStFl = {  {
        {10, suits[0]},
        {11, suits[0]},
        {12, suits[0]},
        {13, suits[0]},
        {14, suits[0]}
    } };
    
    Deck fullHouse = {   {
        {3, suits[0]},
        {3, suits[1]},
        {3, suits[2]},
        {14, suits[3]},
        {14, suits[1]}
    } };
    
    Deck random = {   {
        {3, suits[1]},
        {2, suits[3]},
        {13, suits[2]},
        {14, suits[1]},
        {5, suits[0]}
    } };
    
    // Test isFlush
    if(!isFlush(fl)) testError("test isFlush 1");
    if(!isFlush(stFl)) testError("test isFlush 2");
    if(!isFlush(roStFl)) testError("test isFlush 3");
    if(isFlush(random)) testError("test isFlush 4");
    if(isFlush(st)) testError("test isFlush 5");
    
    // Test isStraight
    if(!isStraight(stFl)) testError("test isStraight 1");
    if(!isStraight(st)) testError("test isStraight 2");
    if(!isStraight(roStFl)) testError("test isStraight 3");
    if(isStraight(fl)) testError("test isStraight 4");
    if(isStraight(random)) testError("test isStraight 5");
    
    // Test isStraightFlush
    if(!isStraightFlush(stFl)) testError("test isStraightFlush 1");
    if(!isStraightFlush(roStFl)) testError("test isStraightFlush 2");
    if(isStraightFlush(st)) testError("test isStraightFlush 3");
    if(isStraightFlush(fl)) testError("test isStraightFlush 4");
    if(isStraightFlush(random)) testError("test isStraightFlush 5");
    
    // Test isRoyalFlush
    if(isRoyalFlush(stFl)) testError("test isRoyalFlush 1");
    if(!isRoyalFlush(roStFl)) testError("test isRoyalFlush 2");
    if(isRoyalFlush(st)) testError("test isRoyalFlush 3");
    if(isRoyalFlush(fl)) testError("test isRoyalFlush 4");
    if(isRoyalFlush(random)) testError("test isRoyalFlush 5");
    
    // Test isFullHouse
    if(!isFullHouse(fullHouse)) testError("test isFullHouse 1");
    if(isFullHouse(roStFl)) testError("test isFullHouse 2");
    if(isFullHouse(st)) testError("test isFullHouse 3");
    if(isFullHouse(fl)) testError("test isFullHouse 4");
    if(isFullHouse(random)) testError("test isFullHouse 5");
    
    cout << "Passed All Test!" << endl;
}


// shuffle a deck many times.
// After each shuffle, check whether the hand is one of the hands you test for above and keep track of the total numbers of flushes, straights, royal flushes, etc.
void statistic(Deck &d, int times){
    int fl = 0, st = 0, stFl = 0, roFl = 0, fuHo = 0;
    
    int i = 0;
    while(i++ < times){
        shuffle(d);
        if(isFlush(d)) fl++;
        if(isStraight(d)) st++;
        if(isStraightFlush(d)) stFl++;
        if(isRoyalFlush(d)) roFl++;
        if(isFullHouse(d)) fuHo++;
    }
    
    cout  << "Statistical Results \n"<< "After runing " << times <<" times:" << endl;
    cout << "  Number of flushes: " << fl << endl;
    cout << "  Number of straights: " << st << endl;
    cout << "  Number of straight flushes: " << stFl << endl;
    cout << "  Number of royal flushes: " << roFl << endl;
    cout << "  Number of full houses: " << fuHo << endl;
}

