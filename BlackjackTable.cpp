//
// Created by Joseph Hoang on 9/12/23.
//

#include <iostream>
#include <iosfwd>
#include <utility>
#include <chrono>
#include <thread>
#include "BlackjackTable.h"
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


// Blackjack table constructor
BlackjackTable::BlackjackTable(vector<Player> p) {
    tablePlayers = move(p);
    tablePlayers.insert(tablePlayers.begin(), Player("Dealer", 0));
}

// Void method to start and stop dealing hands
// INCOMPLETE
void BlackjackTable::startGame() {
    while (play){
        shuffleDeck();
        dealHands();
        printTable();

        stopGame();
    }
}
void BlackjackTable::stopGame() {
    play = false;
}

// Void method to add player to table
void BlackjackTable::addPlayer(const Player& p) {
    tablePlayers.push_back(p);
}
// Void method to set a player's bet
void BlackjackTable::playerBet(const string& name, float bet) {
    for (auto &i : tablePlayers){
        if(i.getName() == name){
            i.setBet(bet);
            break;
        }
    }
}
// Void method to deal player hands
void BlackjackTable::dealHands() {
    for (auto & player : tablePlayers) {
        player.clearHand();
    }
    for(int j=0; j<2; j++) {
        for (auto & player : tablePlayers) {
            player.dealPlayer(bjDeck.drawCard());
        }
    }
}

// Void method to hit the dealer until at least a value of 17 or bust
void BlackjackTable::hitDealer(){
    while (tablePlayers.at(0).checkHand()<17)
        tablePlayers.at(0).dealPlayer(bjDeck.drawCard());
}

// Void method to print the state of the table with player hands
void BlackjackTable::printTable(string act) {
    cout << "\nDealer hand:    ";
    if (act == "pre"){
        cout << "(" << tablePlayers.at(0).getHand().at(0).getRank()
             << tablePlayers.at(0).getHand().at(0).getSuit() << ") (**)";
    }
    else{
        for(auto &i:tablePlayers.at(0).getHand()){
            cout << "(" << i.getRank() << i.getSuit() << ") ";
            sleep_for(seconds(1));
        }
    }
    cout << "\nPlayer Hands: " << "\n";
    for(auto i=tablePlayers.begin()+1; i!=tablePlayers.end(); i++){
        printf("%-15s ", i->getName().c_str());
        for (auto &j: i->getHand())
            cout << "(" << j.getRank() << j.getSuit() << ") ";
        cout << "\n";
    }
}

// Void method to shuffle table deck
void BlackjackTable::shuffleDeck() {
    bjDeck.shuffleStack();
}

// Void method to hit player
void BlackjackTable::hitPlayer(string name){
    for(auto &i : tablePlayers){
        if(i.getName() == name) {
            i.dealPlayer(bjDeck.drawCard());
            break;
        }
    }
}
unsigned BlackjackTable::checkPlayer(string name){
    for(auto &i : tablePlayers){
        if(i.getName() == name) {
            return i.checkHand();
        }
    }
}




// Getter functions to get private values
vector<Player> BlackjackTable::getPlayers() {
    return tablePlayers;
}









