#include "Monopoly.h"
#include "Card.h"
#include "Tile.h"
#include "Player.h"

#include <iostream>
#include <utility>

namespace Monopoly{
    Monopoly::Monopoly() :
    mChanceDeck(new std::vector<Card>),
    mCommunityChestDeck(new std::vector<Card>),
    mBoard(new std::vector<Tile>)
    {
        Monopoly::createBoard();
        Monopoly::createChanceDeck();
        Monopoly::createCommunityChestDeck();
    }

    void Monopoly::createBoard(){

    }

    void Monopoly::createChanceDeck(){
        auto collectEffect = [](Player player, int amount) {player.addMoney(amount);};
        auto payEffect = [](Player player, int amount) {player.addMoney(amount);};
        auto movePlayerWithoutPassingGo = [](Player player, int tileId) {player.moveTo(Monopoly::getTile[tileId]);};
        auto movePlayerWithPassingGo = [](Player player, int tileId) {player.moveTo(Monopoly::getTile[tileId]); if (player.getCurrentTile().getId() < tileId) player.addMoney(200);};

        int id = -1;
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to Boardwalk", movePlayerWithoutPassingGo));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to Go. Collect $200", advanceToGoEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to Illinois Avenue. If you pass Go, collect $200", advanceToIllinoisAveEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to St. Charles Place. If you pass Go, collect $200", advanceToStCharlesEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay owner twice the rental to which they are otherwise entitled", advanceToNearestRailroadEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay owner twice the rental to which they are otherwise entitled", advanceToNearestRailroadEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times amount thrown.", advanceToNearestUtilityEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Bank pays you dividend of $50", bankDividendEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Get Out of Jail Free", getOutOfJailEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Go Back 3 Spaces", goBack3SpacesEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Go to Jail. Go directly to Jail, do not pass Go, do not collect $200", movePlayerWithoutPassingGo));
        mChanceDeck->push_back(Card(++id, "Chance", "Make general repairs on all your property. For each house pay $25. For each hotel pay $100", makeRepairsEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Speeding fine $15", speedingFineEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Take a trip to Reading Railroad. If you pass Go, collect $200", tripToReadingRailroadEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "You have been elected Chairman of the Board. Pay each player $50", chairmanOfTheBoardEffect));
        mChanceDeck->push_back(Card(++id, "Chance", "Your building loan matures. Collect $150", speedingFineEffect));
    }

    void Monopoly::createCommunityChestDeck(){
        int id = -1;

        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Advance to Go (Collect $200)", advanceToGoEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Bank error in your favor. Collect $200", bankErrorEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Doctor's fee. Pay $50", payDoctorFeeEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "From sale of stock you get $50", stockSaleEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Get Out of Jail Free", getOutOfJailEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Go to Jail. Go directly to jail, do not pass Go, do not collect $200", goToJailEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Holiday fund matures. Receive $100", holidayFundEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Income tax refund. Collect $20", incomeTaxRefundEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "It is your birthday. Collect $10 from every player", birthdayCollectEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Life insurance matures. Collect $100", lifeInsuranceMaturesEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Pay hospital fees of $100", payHospitalFeeEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Pay school fees of $50", paySchoolFeeEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "Receive $25 consultancy fee", consultancyFeeEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "You are assessed for street repair. $40 per house. $115 per hotel", streetRepairAssessmentEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "You have won second prize in a beauty contest. Collect $10", beautyContestPrizeEffect));
        mCommunityChestDeck->push_back(Card(++id, "CommunityChest", "You inherit $100", inheritMoneyEffect));
    }

    Tile Monopoly::getTile(int tileId){
        return mBoard->at(tileId);
    }
}