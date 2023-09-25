//
// Created by Joseph Hoang on 9/12/23.
//

#include "Player.h"

Player::Player(string n, float startingStack) {
    name = n;
    stack = startingStack;
}

void Player::clearHand() {
    hand.clear();
}

void Player::dealCard(Card c) {
    hand.push_back(c);
}

int Player::checkHand() {
    int sum = 0;
    unsigned ace=0;
    for (auto & i : hand){
        if(i.getRank() == 'A'){
            sum += 11;
            ace+=1;
        }
        else if (i.getRank() == 'K' || i.getRank() == 'Q'  || i.getRank() == 'J')
            sum += 10;
        if(sum > 21 && ace != 0)
            sum -= 10;
    }
    return 0;
}

void Player::playerBet(float b) {
    bet = b;
}

void Player::playerWin() {
    stack += bet;
}

void Player::playerLose() {
    stack -= bet;
}

string Player::getName() {
    return name;
}

vector<Card> Player::getHand() {
    return hand;
}



