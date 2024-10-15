#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Juice {
private:
    int numJugs, maxTransfers;
    vector<int> Amount;

public:
    Juice(int numJugs, int maxTransfers, vector<int>& Amount) {
        this->numJugs = numJugs;
        this->maxTransfers = maxTransfers;
        this->Amount = Amount;
    }

    long long solve() {    
        // Sort the juice quantities in ascending order
        sort(Amount.begin(), Amount.end());
        
        // Edge case: No transfers allowed, return max - min directly
        if (maxTransfers == 0) {
            return Amount[numJugs - 1] - Amount[0];
        }

        // Calculate initial max value after transfers
        ll largestJuice = Amount[numJugs - 1];

        // If transfers are enough to empty all but one jug, take the sum of all elements
        if (maxTransfers >= numJugs - 1) {
            for (int i = 0; i < numJugs; ++i) {
                largestJuice += Amount[i];
            }
            return largestJuice;
        }
        
        // Perform up to 'maxTransfers' additions to maximize the largest jug
        for (int i = 0; i < maxTransfers; ++i) {
            largestJuice += Amount[numJugs - 2 - i];
        }

        return largestJuice;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Juice JuiceClass(n,k,arr);
    cout<<JuiceClass.solve()<<"\n";

    return 0;
}
