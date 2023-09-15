//
// Created by Joseph Hoang on 9/12/23.
//

#include "Player.h"

Player::Player(float startingStack) {
    stack = startingStack;

}

void Player::playerHit(Card card) {
    hand.push_back(card);
}

int Player::checkHand() {
    int sum = 0;
    unsigned ace=0;
    for (auto i=hand.begin(); i != hand.end(); i++){
        if(i->getRank() == 'A'){
            sum += 11;
            ace+=1;
        }
        else if (i->getRank() == 'K' || i->getRank() == 'Q'  || i->getRank() == 'J')
            sum += 10;
        if(sum > 21 && ace != 0)
            sum -= 10;
    }
    return 0;
}
