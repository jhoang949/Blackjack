//
// Created by Joseph on 9/14/2023.
//


#include <iostream>
#include <chrono>
#include <thread>
#include "Player.h"
#include "BlackjackTable.h"
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


// Using main function to call code to play heads up versus a dealer/casino
int main(){
    // Initialize variables used to create the player
    string name;
    float amount;
    vector<Player> seats;

    // Acquires user inputs to create player
    cout << "Please enter name: ";
    cin >> name;
    cout << "Please enter starting stack amount: ";
    cin >> amount;
    Player user(name, amount);

    // Add player to seat and create table
    seats.push_back(user);
    BlackjackTable table(seats);

    // Starts game
    // TEMPORARY
    bool play = true;
    cout << "\n\nPlease enter 'P' when you want to stop playing\n\n";
    while (play){
        // Get player bet
        int bet;
        cout << "How much do you want to bet this hand?  ";
        cin >> bet;
        table.playerBet(name, bet);

        // Shuffle deck and deal hands
        table.shuffleDeck();
        table.dealHands();

        // Allow players to act
        char act='H';
        while(act != 'S') {
            table.printTable();
            cout << "Hit(H) or Stand(S): ";
            cin >> act;
            switch (act) {
                case 'H':
                    table.hitPlayer(name);
                case 'S':
                    break;
                case 'P':
                    play = false;
                    cout << "Game will pause before next hand";
            }
            if (table.checkPlayer(name)<22)
                continue;
            else{
                table.printTable();
                cout << "\nPlayer busted! (total hand value: " << table.checkPlayer(name) << ")\n\n";
                sleep_for(seconds(1));
                act = 'S';
            }
        }

        // Player action completes. Reveal dealer hand and hit dealer
        cout << "Hitting Dealer...";
        table.hitDealer();
        table.printTable("post");
        // Compare player and dealer hands to see who wins
        // Rake money if player loses and pay player if player wins
    }



    /*char act='H';
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
    }*/


}