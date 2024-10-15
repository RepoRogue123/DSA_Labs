#include <bits/stdc++.h>

using namespace std;


class Solution{
public:
    void RollingDice(int n,vector<int> diceRolls){
        vector<int> position(n);
        for(int i=0; i<n; i++){
            position[i]=i+1;
        }
        int current_player=0;  //variable to check who is going to start
        for(int i=0; i<diceRolls.size(); i++){

            int x=diceRolls[i];
            cout<<x<<" ";

            current_player=(current_player+x)%n;//update who is going to get removed after diceroll
            cout<<position[current_player];

            position.erase(position.begin()+current_player);
            n--;//update the size of position vector after removal of one element;


            cout<<endl;
            cout<<"The updated vector is :"<<endl;
             for(int i=0;i<n;i++){  // To check the updated vector 
                cout<<position[i]<<" ";
            }
            
            cout<<endl;
           
        }
        cout<<"THE WINNER IS:"<< endl;

        cout<<position[0]<<endl;//prints the winner i.e. the only element in the vector trace remaining
    }
      
};
/*Logic----->>>>  The code initializes the positions of n players in a vector and processes each dice roll to determine which player will be removed.
After each dice roll, the current player's position is updated, and the corresponding player is removed from the game.
The process continues until only one player remains, who is declared the winner.*/

int main() {
    int n; // number of players
    cin>>n;
    
    // The array to store the dice rolls
    vector<int> diceRolls(n - 1);

    // Input dice rolls
    for (int i = 0; i < n - 1; i++) {
        cin>>diceRolls[i];
    }
    
    Solution s;
    s.RollingDice(n,diceRolls);

    

    return 0;
}