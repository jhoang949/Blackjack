//
// Created by Joseph Hoang on 9/12/23.
//

#ifndef BLACKJACK_GIT_BLACKJACKTABLE_H
#define BLACKJACK_GIT_BLACKJACKTABLE_H

#include "Player.h"
#include "Deck.h"

// Blackjack table class
class BlackjackTable {
private:
    vector<Player> tablePlayers;
    Deck bjDeck=Deck('B');
    bool play = true;

public:
    // Blackjack table constructor
    explicit BlackjackTable(vector<Player> p);
    // Void method to start and stop dealing hands
    void startGame();
    void stopGame();

    // Methods to change table state
    void addPlayer(const Player& p);
    void playerBet(const string& name, float bet);
    void dealHands();
    void hitDealer();

    // Void method to print the state of the table with player hands
    void printTable(string action = "pre");

    // Void method to shuffle table deck
    void shuffleDeck();

    // Void method to hit player
    void hitPlayer(string name);
    unsigned checkPlayer(string name);

    // Getter functions to get private values
    vector<Player> getPlayers();
};


#endif //BLACKJACK_GIT_BLACKJACKTABLE_H
