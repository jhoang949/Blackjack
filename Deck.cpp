//
// Created by Joseph Hoang on 8/31/23.
//

#include <algorithm>
#include <random>
#include "Deck.h"
using namespace std;

// Deck constructor
Deck::Deck(char s){
    // Initialize deck types depending on the input. input calls other methods that create deck
    // L - standard 52 card deck where Ace has a value 1 (the lowest value)
    // H - standard 52 card deck where Ace has a value of 14 (the highest value)
    // B - creates a 156 card deck (3 standard decks)
    switch (s){
        case 'L':
            createLowADeck();
            break;
        case 'H':
            createHighADeck();
            break;
        case 'B':
            createBjDeck();
            break;
    }
}

// Creates a standard 52 card deck where Ace has a value 1 (the lowest value)
void Deck::createLowADeck() {
    vector<Card> deck;
    Card card=Card(0,'S');
    char suit;
    for(int i=1; i < 14; i++){
        for(int j=1; j<5; j++){
            switch (j){
                case (1):
                    suit = 'S';
                    break;
                case (2):
                    suit = 'C';
                    break;
                case (3):
                    suit = 'D';
                    break;
                case (4):
                    suit = 'H';
                    break;
            }
            card = Card(i, suit);
            deck.push_back(card);
        }
    }
    cardStack = deck;
}

// Creates a standard 52 card deck where Ace has a value of 14 (the highest value)
void Deck::createHighADeck() {
    vector<Card> deck;
    Card card=Card(0,'S');
    char suit;
    for(int i=2; i < 15; i++){
        for(int j=1; j<5; j++){
            switch (j){
                case (1):
                    suit = 'S';
                    break;
                case (2):
                    suit = 'C';
                    break;
                case (3):
                    suit = 'D';
                    break;
                case (4):
                    suit = 'H';
                    break;
            }
            card = Card(i, suit);
            deck.push_back(card);
        }
    }
    cardStack = deck;
}

// Creates a 156 card deck (3 standard decks)
void Deck::createBjDeck() {
    vector<Card> deck;
    Card card=Card(0,'S');
    char suit;
    for(int k = 0; k < 3; k++)
        for(int i=1; i < 14; i++){
            for(int j=1; j<5; j++){
                switch (j){
                    case 1:
                        suit = 'S';
                        break;
                    case 2:
                        suit = 'C';
                        break;
                    case 3:
                        suit = 'D';
                        break;
                    case 4:
                        suit = 'H';
                }
                card = Card(i, suit);
                deck.push_back(card);
            }
        }
    cardStack = deck;
}

// Returns the vector stack
vector<Card> Deck::getStack() {
    return cardStack;
}
// Returns drawn stack
vector<Card> Deck::getDrawn() {
    return cardsDrawn;
}

// Algorithm that shuffles the deck
// Pushes the drawn cards back into the vector first
// so that you have the whole stack again before shuffling
void Deck::shuffleStack(){
    for(auto & i : cardsDrawn){
        cardStack.push_back(i);
    }
    cardsDrawn.clear();
    auto rd = random_device{}();
    auto rng = default_random_engine{ rd};
    shuffle(begin(cardStack), end(cardStack), rng);
}

// Retrieves the top card of the deck and removes it from the deck
// Adds removed card to stack "drawnCards" that saves all cards drawn
// to be added back to deck when shuffled
Card Deck::drawCard(){
    Card draw = *getStack().begin();
    cardsDrawn.push_back(draw);
    cardStack.erase(cardStack.begin());
    return draw;
}




