//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_ASSASSIN_H
#define COUP_A_ASSASSIN_H
#include "Player.hpp"
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup {
    class Assassin : public Player {
    public:
        Assassin(coup::Game &game, const string &name);
    };
}

#endif //COUP_A_ASSASSIN_H
