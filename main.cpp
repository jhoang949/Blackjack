//
// Created by Joseph on 9/14/2023.
//


#include <iostream>
#include "Player.h"
#include "BlackjackTable.h"
using namespace std;

int main(){
    string name;
    float amount;
    vector<Player> players;

    cout << "Please enter name: ";
    cin >> name;
    cout << "Please enter starting stack amount: ";
    cin >> amount;
    Player user(name, amount),player2=Player("Bluffaro", 69),
    player3=Player("beekilled0", 420);

    players.push_back(user);
    players.push_back(player2);
    players.push_back(player3);

    BlackjackTable table(players);
    table.shuffleDeck();
    table.dealHands();
    char act='H';
    while(act != 'S') {
        table.printTable();
        cout << "Hit or Stand: ";
        cin >> act;
        switch (act){
            case 'H':
                table.hitPlayer(name);
                continue;
            case 'S':
                break;
        }
    }


}