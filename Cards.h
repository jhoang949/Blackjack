//
// Created by Joseph Hoang on 8/24/23.
//

#ifndef POKER_CARDS_H
#define POKER_CARDS_H

#include "string"
using namespace std;

// Card Class
class Card{
private:
    unsigned value=0;
    char rank='0';
    char suit='S';

public:
    // Card constructor - takes value and suit and assigns rank based on value
    Card(unsigned val, char sut);

    // Card getters for value, rank and suit
    unsigned getValue();
    char getRank();
    char getSuit();
};



#endif //POKER_CARDS_H
