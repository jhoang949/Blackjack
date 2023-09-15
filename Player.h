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
    float stack;
    float bet=0;
    vector<Card> hand;
public:
    Player(float startingStack);
    void playerHit(Card card);
    int checkHand();
};


#endif //BLACKJACK_GIT_PLAYER_H
