//
// Created by Joseph Hoang on 8/24/23.
//
#include "Cards.h"

// Card Constructor - takes value and suit and assigns rank based on value
Card::Card(unsigned val, char sut){
    value = val;
    suit = sut;
    // Assigns rank based on value of the card
    switch (value){
        case 1:
            rank = 'A';
            break;
        case 2:
            rank = '2';
            break;
        case 3:
            rank = '3';
            break;
        case 4:
            rank = '4';
            break;
        case 5:
            rank = '5';
            break;
        case 6:
            rank = '6';
            break;
        case 7:
            rank = '7';
            break;
        case 8:
            rank = '8';
            break;
        case 9:
            rank = '9';
            break;
        case 10:
            rank = '10';
            break;
        case 11:
            rank = 'J';
            break;
        case 12:
            rank = 'Q';
            break;
        case 13:
            rank = 'K';
            break;
        case 14:
            rank = 'A';
            break;
    };
}

// Card getters

// Gets card value
unsigned Card::getValue() {
    return value;
}

// Gets card rank
char Card::getRank() {
    return rank;
}

// Gets card suit
char Card::getSuit() {
    return suit;
}

