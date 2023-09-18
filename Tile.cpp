#include "Tile.h"

namespace Monopoly{
    Tile::Tile(int id) :
    mId(id)
    {
        // Nothing to do
    }

    int Tile::getTileId() const{
        return mId;
    }
}