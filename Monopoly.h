#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <iostream>
#include <vector>

#include "Card.h"
#include "Tile.h"

namespace Monopoly{
    class Monopoly{
        public:
            void createBoard();
            void createChanceDeck();
            void createCommunityChestDeck();
            Tile getTile(int tileId);

        private:
            std::vector<Card> *mChanceDeck;
            std::vector<Card> *mCommunityChestDeck;
            std::vector<Tile> *mBoard;
    };
}

#endif MONOPOLY_H