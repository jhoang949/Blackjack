//
// Created by Joseph Hoang on 9/12/23.
//

#ifndef BLACKJACK_GIT_PLAYER_H
#define BLACKJACK_GIT_PLAYER_H

#include <vector>
#include "Cards.h"
using namespace std;

class Player {
private:
    string name;
    float stack;
    float bet=0;
    vector<Card> hand;
public:
    Player(string n,float startingStack);
    void clearHand();
    void dealCard(Card c);
    void playerHit(Card card);
    int checkHand();

    void playerBet(float b);
    void playerWin();
    void playerLose();

    string getName();
    vector<Card> getHand();
};


#endif //BLACKJACK_GIT_PLAYER_H
