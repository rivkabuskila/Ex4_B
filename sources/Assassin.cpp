//
// Created by rivka on 25/04/2022.
//

#include "Assassin.hpp"
namespace coup {

//    Assassin::Assassin(const coup::Game &game, const string &name) {}
    Assassin::Assassin(coup::Game &game, const string &name): Player::Player(game,name){
        add("Assassin");
    }

}