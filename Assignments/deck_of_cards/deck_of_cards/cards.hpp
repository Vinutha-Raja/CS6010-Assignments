//
//  cards.hpp
//  deck_of_cards
//
//  Created by Vinutha Raja on 9/1/21.
//

#ifndef cards_h
#define cards_h

#include <string>
#include <vector>
using namespace std;

const vector<string> suits = {"spade", "heart", "diamond", "club"};
struct Card{
    int rank;
    string suit;
};


struct Deck{
    vector<Card> cards;
};

Deck createDeck();

void printDeck(const Deck &d);

void shuffle(Deck &d);

//Return true if all the cards are the same suit
bool isFlush(Deck &d);


// Return true if all 5 cards in numerical order (note this is a little tricky because the hand is unsorted!)
bool isStraight(Deck d);


// Return true if this hand is both a straight and a flush
bool isStraightFlush(Deck d);


// Return true if this hand is a straight flush whose low card is a ten
bool isRoyalFlush(Deck d);


// Return true if there are 3 of one rank, and 2 of another (3 aces and 2 fives, for example)
bool isFullHouse(Deck &d);


#endif /* cards_h */
