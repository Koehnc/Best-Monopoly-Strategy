import random
import matplotlib.pyplot as plt

class Player:
    def __init__(self, startingMoney = 10000, startingLocation = 0):
        self.currentLocation = startingLocation
        self.ownedLocations = []
        self.money = startingMoney
    
    def buy(self, location):
        if (self.money >= location.cost):
            self.ownedLocations.append(location)
            self.money -= location.cost
            return True
        else:
            return False

    def pay(self, amount):
        self.money -= amount


class Location:
    def __init__(self):
        self.name = "Boardwalk"     # All locations are now known as Boardwalk
        self.houses = 0
        self.cost = 200
        self.owner = None

    def getRent(self):
        return 100 * 5 ** self.houses

    def getHouseCost(self):
        return 200


class Board:
    def __init__(self, size = 40, numPlayers = 2, startingMoney = None):
        self.size = size

        if (startingMoney == None):
            startingMoney = [10000] * numPlayers
        
        self.startingMoney = startingMoney

        # 11 x 11 board is 40 squares long
        self.board = []
        for i in range(0, size):
            self.board.append(Location())
        self.board[0].name = "Go"   # Just for the aesthetic

        self.players = []
        for i in range(0, numPlayers):
            self.players.append(Player(startingMoney[i]))

    def getNextRandomState(self):
        for player in self.players:
            player.currentLocation += random.randint(1,6)
            # Handle passing go
            if (player.currentLocation >= self.size):
                player.currentLocation %= self.size
                player.money += 200

            # Can't buy the "Go" square
            if (player.currentLocation == 0):
                return

            currentSquare = self.board[player.currentLocation]
            # Buy it if the square is available
            if (currentSquare.owner == None):
                if (player.buy(currentSquare)):
                    currentSquare.owner = player

            # Buy house on owned square
            elif (currentSquare.owner == player):
                if (player.money > currentSquare.getHouseCost()):
                    player.pay(currentSquare.getHouseCost())
                    currentSquare.houses += 1

            # No owner and not owned by the player, pay rent, return if player died
            else:
                player.pay(currentSquare.getRent())
                if (player.money < 0):
                    return self.players.index(player)

    def randomSimulation(self):
        loser = None
        while (loser == None):
            loser = game.getNextRandomState()
        # Switch 0 and 1, only works for 2 player game
        winner = abs(loser - 1)

        return winner

startingAmounts = []
winningPercentage = []
iterations = 10000
startingMoney = [10000, 10250]  # 10320 is a really close 50/50
for i in range(0, 200):
    winners = []
    for i in range(0, iterations):
        game = Board(startingMoney=startingMoney)
        winner = game.randomSimulation()
        winners.append(winner)
    startingMoney[1] += 1
    startingAmounts.append(startingMoney[1])
    winningPercentage.append(abs(float(winners.count(0)) / iterations - .5))

print(winningPercentage)
plt.plot(startingAmounts, winningPercentage)
plt.xlabel("P2 Starting Amount")
plt.ylabel("abs distance from .5 avg across 10000 games")
plt.show()
# print(winners.count(0))
# print(startingMoney)