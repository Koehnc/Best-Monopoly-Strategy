#include "Card.h"

#include "Player.h"

#include <iostream>
#include <string>
#include <functional>

namespace Monopoly{
    Card::Card(int id, const std::string &type, const std::string &text, const std::function<void(Player &player, int amount)>& pAdjustPlayer) :
    mId(id),
    mType(type),
    mText(text),
    mAdjustPlayer(pAdjustPlayer)
    {}

    void Card::adjustPlayer(Player player, int amount) const{
        mAdjustPlayer(player, amount);
    }
}