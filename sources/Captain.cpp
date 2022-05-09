//
// Created by rivka on 25/04/2022.
//

#include "Captain.hpp"
namespace coup {

//    Captain::Captain(const coup::Game &game, const string &name) {}
    Captain::Captain(coup::Game &game, const string &name): Player::Player(game,name){
        add("Captain");
    }

    void Captain::steal(Player &p) {
        if (this != p.game->player.at(this->game->turnPlayer)){
            string s = "it is " + this->game->player.at(this->game->turnPlayer)->role() + "'s turn now";
            throw std::out_of_range{s};
        }
        if (p.coins() >= 2){
            p.add(-2);
            add(2);
        }
        else{
            int coin = p.coins();
            p.add(-coin);
            add(coin);
        }
        this->lastAction = "steal";
        this->coupPlayer=&p;
        this->game->updateTurn();

    }

    void Captain::block(Player &p) {
        if (p.rolePlayer!="Captain"){
            throw std::out_of_range{"invalid action"};
        }
        if (p.lastAction=="steal"){
            p.add(-2);
            p.coupPlayer->add(2);
        }
    }
}