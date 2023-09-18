#include "Player.h"

#include "Tile.h"

#include <utility>

namespace Monopoly{
    Player::Player() :
    money(0),
    currentTile(new Tile(0))
    {}

    void Player::addMoney(int amount){
        money += amount;
    }

    void Player::pay(int amount){
        money -= amount;
    }

    void Player::moveTo(Tile &newTile){
        currentTile = &newTile;
    }
}