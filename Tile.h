#ifndef TILE_H
#define TILE_H

namespace Monopoly{
    class Tile{
        public:
            Tile(int id);
            int getTileId() const;

        private:
            int mId;
    };
}

#endif TILE_H