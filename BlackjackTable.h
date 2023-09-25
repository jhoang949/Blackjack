//
// Created by Joseph Hoang on 9/12/23.
//

#ifndef BLACKJACK_GIT_BLACKJACKTABLE_H
#define BLACKJACK_GIT_BLACKJACKTABLE_H

#include "Player.h"
#include "Deck.h"


class BlackjackTable {
private:
    vector<Player> tablePlayers;
    Deck bjDeck=Deck('B');
public:
    explicit BlackjackTable(vector<Player> p);
    void addPlayer(Player p);
    void dealHands();
    void hitDealer();


    void printTable();



    void shuffleDeck();


    void hitPlayer(string name);
    vector<Player> getPlayers();
};


#endif //BLACKJACK_GIT_BLACKJACKTABLE_H
