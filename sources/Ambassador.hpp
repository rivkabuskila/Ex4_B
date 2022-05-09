//
// Created by rivka on 25/04/2022.
//

#ifndef COUP_A_AMBASSADOR_H
#define COUP_A_AMBASSADOR_H
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
namespace coup {
    class Ambassador : public Player {
    public:
        Ambassador(coup::Game &game, const string &name);

        void transfer(Player &p1, Player &p2);

        void static block(Player &p);
    };
}
#endif //COUP_A_AMBASSADOR_H
