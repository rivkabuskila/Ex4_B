//
// Created by rivka on 25/04/2022.
//

#include "Ambassador.hpp"
namespace coup {
    Ambassador::Ambassador(coup::Game &game, const string &name): Player::Player(game,name){
        add("Ambassador");
    }

    void Ambassador::transfer(Player &p1, Player &p2) {
        if (p1.coins() < 1){
            throw std::out_of_range{"not enough money "};

        }
        p1.add(-1);
        p2.add(1);
        this->game->updateTurn();
        this->lastAction = "transfer";
    }

    void Ambassador::block(Player &p1) {
        if (p1.rolePlayer!="Captain"){
            throw std::out_of_range{"invalid action"};
        }
        if (p1.lastAction=="steal"){
            p1.add(-2);
            p1.coupPlayer->add(2);
        }
    }
}