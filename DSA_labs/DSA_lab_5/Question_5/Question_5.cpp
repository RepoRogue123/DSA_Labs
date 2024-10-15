#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void RollingDice(int initialPlayerCount, vector<int> diceRolls) {
        vector<int> activePlayers(initialPlayerCount);
        for(int i = 0; i < initialPlayerCount; i++){
            activePlayers[i] = i + 1;
        }
        
        int currentPlayerIndex = 0;  // Index of the player who will roll the dice
        int remainingPlayers = initialPlayerCount;
        
        for(int round = 0; round < diceRolls.size(); round++){
            int diceValue = diceRolls[round];
            cout << "Dice Roll: " << diceValue << ", ";
            
            currentPlayerIndex = (currentPlayerIndex + diceValue) % remainingPlayers;
            int eliminatedPlayer = activePlayers[currentPlayerIndex];
            
            cout << "Player " << eliminatedPlayer << " is eliminated" << endl;
            
            activePlayers.erase(activePlayers.begin() + currentPlayerIndex);
            remainingPlayers--; // Update the count of remaining players
            
            // Adjust currentPlayerIndex if it's now out of bounds
            if (currentPlayerIndex == remainingPlayers) {
                currentPlayerIndex = 0;
            }
        }
        
        cout << "The winner is Player " << activePlayers[0] << endl;
    }
};

int main() {
    int playerCount;
    cin >> playerCount;
    
    // The array to store the dice rolls
    vector<int> diceRolls(playerCount - 1);
    // Input dice rolls
    for (int i = 0; i < playerCount - 1; i++) {
        cin >> diceRolls[i];
    }
    
    Solution s;
    s.RollingDice(playerCount, diceRolls);
    
    return 0;
}