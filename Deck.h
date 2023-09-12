//
// Created by Joseph Hoang on 8/31/23.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include <iostream>
#include <vector>
#include "Cards.h"
#include "string"
using namespace std;

// Deck class
class Deck {
private:
    // Stack for current cards in the deck
    vector<Card> cardStack;
    // Stack for cards that have been drawn
    // Used to push back into the stack when using the deck again
    vector<Card> cardsDrawn;
public:
    // Deck constructor
    // Deck() calls the void methods to initialize different decks
    Deck(char deckType);
    void createLowADeck();
    void createHighADeck();
    void createBjDeck();

    // Returns stack of cards as a vector
    vector<Card> getStack();
    // Returns drawn stack
    vector<Card> getDrawn();

    // Shuffles deck once game round is done
    void shuffleStack();

    // Retrieves the top card of the deck and removes it
    Card drawCard();
};


#endif //POKER_DECK_H
