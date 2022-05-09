//
// Created by rivka on 25/04/2022.
//

#include "Player.hpp"
const int MAX_PLAYER = 6;
const int COUP_PRICE = 7;
const int MUST_COUP = 10;
namespace coup {

    Player::Player(coup::Game &game, const string &name) {
        if (game.player.size()==MAX_PLAYER){
            throw std::out_of_range{"2-6 players"};
        }
        if (game.start){
            throw std::out_of_range{"the game already begin"};
        }
        this->game = &game;
        this->name=name;
        this->game->player.push_back(this);
        this->coin=0;
        this->coupPlayer = nullptr;
    }

    int Player::coins() const{
        return this->coin;
    }

    string Player::role() const {
        return this->rolePlayer;
    }

    void Player::income() {
        if (this->game->player.size()==1){
            throw std::out_of_range{"cant play with 1 player"};
        }
        if (this != this->game->player.at(this->game->turnPlayer)){
            string s = "it is " + this->game->player.at(this->game->turnPlayer)->role() + "'s turn now";
            throw std::out_of_range{s};
        }
             this->game->start=true;
            this->coin++;
            this->game->updateTurn();
            this->lastAction = "income";
    }

    void Player::foreign_aid() {
        if (this->game->player.size()==1){
            throw std::out_of_range{"cant play with 1 player"};
        }
        if (this != this->game->player.at(this->game->turnPlayer)){
            string s = "it is " + this->game->player.at(this->game->turnPlayer)->role() + "'s turn now";
            throw std::out_of_range{s};
        }
        if (this->coins()>=MUST_COUP){
            throw std::out_of_range{"you must do coup"};
        }

        this->game->start=true;
        this->coin+=2;
        this->game->updateTurn();
        this->lastAction = "foreign_aid";
    }

    void Player::coup(Player &p) {
        if (this->game->player.size()==1){
            throw std::out_of_range{"cant play with 1 player"};
        }
        bool found = false;
        if (this != this->game->player.at(this->game->turnPlayer)){
            string s = "it is " + this->game->player.at(this->game->turnPlayer)->role() + "'s turn now";
            throw std::out_of_range{s};
        }
        if ((this->coin < COUP_PRICE)&&(this->rolePlayer!="Assassin")){
            throw std::out_of_range{"Not Enough Money"};
        }
        if ((this->coin < 3)&&(this->rolePlayer=="Assassin")){
            throw std::out_of_range{"Not Enough Money"};
        }
        vector<Player*>::iterator it;
        Player *coupP= nullptr;
        unsigned long i=0;
        for (it= this->game->player.begin(); it!=this->game->player.end(); it++,i++) {
                if(((*it)->name == p.name )&&((*it)->rolePlayer == p.rolePlayer))
                {
                    coupP = this->game->player.at(i);
                    this->game->player.erase(it);
                    found= true;
                    break;
                }
            }
        if (!found){
            throw std::out_of_range{"Not found"};
        }

        if ((this->coin < COUP_PRICE)&&(this->rolePlayer=="Assassin")){
            this->coin-=3;
            this->lastAction = "coup y" + to_string(i);
        }
        else{
            this->lastAction = "coup n"+ to_string(i);
            this->coin-=COUP_PRICE;
        }
        this->coupPlayer=coupP;
        if (this->game->turnPlayer >= this->game->player.size()){
            this->game->turnPlayer=0;
        }
        if (this->game->player.at(this->game->turnPlayer)->name == this->name) {
            this->game->updateTurn();
        }
        }
    void Player::add(int num){
         coin+=num;
    }
    void Player::add(const string &nameRole){
        this->rolePlayer=nameRole;

    }

}