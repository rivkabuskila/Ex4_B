//
// Created by rivka on 25/04/2022.
//

#include "Game.hpp"
namespace coup {

    vector<string>Game::players() {
        vector<string>v;
        vector<Player*>::iterator it;
        for (unsigned long  i =0; i < this->player.size(); i++) {
            v.push_back(this->player.at(i)->name);
        }
        return v;
    }
    string Game::turn() {
        return this->player.at(this->turnPlayer)->name;
    }
    string Game::winner() {
        if (this->players().size()>1){
            throw std::out_of_range{"The game is not over"};
        }
        if (!this->start){
            throw std::out_of_range{"The game is not over"};
        }
        return this->players().at(0);
    }

    void Game::updateTurn() {
        if (this->turnPlayer < this->player.size()-1){
            this->turnPlayer++;
        }
        else{
            this->turnPlayer=0;
        }
    }
}