cmake_minimum_required(VERSION 3.21)
project(blackjack_git)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(blackjack_git
        BlackjackTable.cpp
        BlackjackTable.h
        Cards.cpp
        Cards.h
        Deck.cpp
        Deck.h
        Player.cpp
        Player.h
        main.cpp)
