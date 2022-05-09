//
// Created by rivka on 25/04/2022.
//


#ifndef COUP_A_GAME_H
#define COUP_A_GAME_H
#pragma once
#include "Player.hpp"
#include <vector>
#include <string>
using namespace std;
namespace coup {
    class Player;
    class Game {
    public:
        vector<Player*>player;
        unsigned long turnPlayer;
        bool start = false;
    public:
        vector<string> players();
        string turn();
        string winner();
        void updateTurn();
    };
}

#endif //COUP_A_GAME_H
