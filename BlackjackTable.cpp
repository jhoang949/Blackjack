//
// Created by Joseph Hoang on 9/12/23.
//

#include <iostream>
#include <iosfwd>
#include <utility>
#include "BlackjackTable.h"


BlackjackTable::BlackjackTable(vector<Player> p) {
    tablePlayers = move(p);
    tablePlayers.insert(tablePlayers.begin(), Player("Dealer", 0));
}

void BlackjackTable::addPlayer(Player p) {
    tablePlayers.push_back(p);
}

void BlackjackTable::dealHands() {
    for (auto & player : tablePlayers) {
        player.clearHand();
    }
    for(int j=0; j<2; j++) {
        for (auto & player : tablePlayers) {
            player.dealCard(bjDeck.drawCard());
        }
    }
}

void BlackjackTable::hitDealer(){
    while (tablePlayers.at(0).checkHand()<17)
        tablePlayers.at(0).playerHit(bjDeck.drawCard());
}

void BlackjackTable::printTable() {
    cout << "\n\nDealer hand:    (" << tablePlayers.at(0).getHand().at(0).getRank()
    << tablePlayers.at(0).getHand().at(0).getSuit() << ") (**)\n";
    cout << "Player Hands: " << "\n";
    for(auto i=tablePlayers.begin()+1; i!=tablePlayers.end(); i++){
        printf("%-15s ", i->getName().c_str());
        for(auto & j : i->getHand())
            cout << "(" << j.getRank() << j.getSuit() << ") ";
        cout << "\n";
    }
}

void BlackjackTable::shuffleDeck() {
    bjDeck.shuffleStack();
}


void BlackjackTable::hitPlayer(const string& name){
    for(auto &i : tablePlayers){
        if(i.getName() == name) {
            i.dealCard(bjDeck.drawCard());
            break;
        }
    }
}

vector<Player> BlackjackTable::getPlayers() {
    return tablePlayers;
}



