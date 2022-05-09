//
// Created by rivka on 25/04/2022.
//

#include "Duke.hpp"
namespace coup {

    Duke::Duke(coup::Game &game, const string &name): Player::Player(game,name){
        add("Duke");

    }

    void Duke::block(Player &p) {
        if (p.lastAction!="foreign_aid"){
            throw std::out_of_range{"invalid action"};
        }
        p.add(-2);
    }

    void Duke::tax() {
        add(3);
        this->game->updateTurn();
        this->lastAction = "tax";

    }
}