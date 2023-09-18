#ifndef CARD_H
#define CARD_H

#include <string>
#include <functional>

namespace Monopoly{
    class Card{
        public:
            Card(int id, const std::string &type, const std::string &text, const std::function<void(Player &player, int amount)> &pAdjustPlayer);

            void adjustPlayer(Player player, int amount = 0) const;

        private:
            int mId;
            std::string mType;
            std::string mText;
            std::function<void(Player &player, int amount)> mAdjustPlayer;
    };
}

#endif CARD_H