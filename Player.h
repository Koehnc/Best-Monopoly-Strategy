#ifndef PLAYER_H
#define PLAYER_H

#include "Tile.h"

namespace Monopoly{
    class Player{
        public:
            void addMoney(int amount);
            void pay(int amount);
            void moveTo(Tile &newTile);
        private:
            int money;
            Tile *currentTile;
    };
}

#endif PLAYER_H