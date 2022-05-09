//
// Created by rivka on 25/04/2022.
//

#include "Contessa.hpp"
const int INDEX = 6;
const int INDEX_A = 5;

namespace coup {

    Contessa::Contessa(coup::Game &game, const string &name): Player::Player(game,name){
        add("Contessa");

    }

    void Contessa::block(Player &p) {
        if ((p.rolePlayer!="Assassin")||(p.lastAction.rfind("coup",0)!=0)){
            throw std::out_of_range{"invalid action"};
        }
        if ((p.rolePlayer=="Assassin")&&(p.lastAction.at(INDEX_A) == 'n')){
            throw std::out_of_range{"invalid action"};
        }
            string s = p.lastAction.substr(INDEX,p.lastAction.size());
            int i= (int)stod(s);
            // Create Iterator pointing to 4th Position
            auto itPos = this->game->player.begin() + i;
// Insert element with value 9 at 4th Position in vector
            this->game->player.insert(itPos, p.coupPlayer);
            if (i < this->game->turnPlayer){
                this->game->updateTurn();
            }
    }

}