//
//  cards.cpp
//  deck_of_cards
//
//  Created by Vinutha Raja on 9/1/21.
//

#include "cards.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<list>

Deck createDeck(){
    Deck newDeck;
    for (int i = 0; i < 4; i++) {
        for(int j = 1; j < 14; j++){
            Card newCard;
            newCard.suit = suits[i];
            newCard.rank = j + 1;
            newDeck.cards.push_back(newCard);
        }
    }
    return newDeck;
}

void printDeck(const Deck &d){
    cout << "The Complete Deck in Order: " << endl;
    for(auto c : d.cards){
        if(c.rank >= 2 && c.rank <= 10){
            cout << "{" <<  c.suit << " " << c.rank << "} ";
        } else {
            if(c.rank == 11) cout << "{" << c.suit << " J} ";
            if(c.rank == 12) cout << "{" << c.suit << " Q} ";
            if(c.rank == 13) cout << "{" << c.suit << " K} ";
            if(c.rank == 14) cout << "{" << c.suit << " A} ";
            
        }
    }
    cout << endl;
}

void swapCards(Card &x, Card &y){
    Card temp;
    temp = y;
    y = x;
    x = temp;
}

void shuffle(Deck &d){
//    srand((int) time(0));
    for(int i = 0; i < 20; i++){
        swapCards(d.cards[rand() % 52], d.cards[rand() % 52]);
    }
}

bool isFlush(Deck &d){
    string suit = d.cards[0].suit;
    for(int i = 1; i < 5; i++){
        if(d.cards[i].suit != suit) return false;
    }
    return true;
}


void sortHand(vector<Card> &cards){
    for (int i = 0; i < 4; i++) {
        for(int j = i; j < 5; j++){
            if(cards[j].rank < cards[i].rank) swap(cards[j], cards[i]);
        }
    }
}

bool isStraight(Deck d){
    sortHand(d.cards);
    for(int i = 0; i < 4; i++){
        if(d.cards[i+1].rank - d.cards[i].rank != 1) return false;
    }
    return true;
}

// Return true if this hand is both a straight and a flush
bool isStraightFlush(Deck d){
    return isStraight(d) && isFlush(d);
}

// Return true if this hand is a straight flush whose low card is a ten
bool isRoyalFlush(Deck d){
    return isStraightFlush(d) && d.cards[0].rank == 10;
}

bool isFullHouse(Deck &d){
    int num1 = 0, num2 = 0; // store the numbers of cards with same rank
    num1 = d.cards[0].rank;
    for(int i = 1; i < 5; i++){
        if(d.cards[i].rank != num1) num2 = d.cards[i].rank;
    }

    int count1 = 0, count2 = 0;
    for(int i = 0; i < 5; i++){
        if(d.cards[i].rank == num1) count1++;
        if(d.cards[i].rank == num2) count2++;
    }
    
    if(count1 == 3 && count2 == 2) return true;
    if(count1 == 2 && count2 == 3) return true;
    return false;
}


