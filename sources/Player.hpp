//
// Created by rivka on 25/04/2022.
//
#ifndef COUP_A_PLAYER_H
#define COUP_A_PLAYER_H
#pragma once
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "stdlib.h"

using namespace std;
namespace coup {
    class Game;
    class Player {
    public:
        Game *game;
        string name;
        int coin;
        string rolePlayer;
        string lastAction;
        Player *coupPlayer;

    public:
        Player(coup::Game &game, const string &name);
        int coins() const;
        string role() const;
        void income();
        void foreign_aid();
        void coup(Player &p);
        void add(int num);
        void add(const string &nameRole);
    };
}
#endif //COUP_A_PLAYER_H
