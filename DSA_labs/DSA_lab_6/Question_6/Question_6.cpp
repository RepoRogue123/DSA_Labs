#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Competition {
public:
    void solveTestCases() {
        ll n;
        cin >> n; 
        vector<ll> challenges(n);
        vector<ll> stamina(n);
        for (int i = 0; i < n; i++) {
            cin >> challenges[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> stamina[i];
        }
        cout << calculateMaxDays(n, challenges, stamina) << endl;
    }

private:
    ll calculateMaxDays(ll n, vector<ll>& challenges, vector<ll>& stamina) {
        vector<pair<ll, ll>> friends(n);
        for (int i = 0; i < n; i++) {
            friends[i] = {stamina[i] - challenges[i], i};
        }
        
        // Sort friends by the difference between stamina and challenges (descending)
        sort(friends.rbegin(), friends.rend());
        
        ll days = 0;
        ll left = 0, right = n - 1;
        
        while (left < right) {
            ll total_stamina = stamina[friends[left].second] + stamina[friends[right].second];
            ll total_challenges = challenges[friends[left].second] + challenges[friends[right].second];
            
            if (total_stamina >= total_challenges) {
                days++;
                left++;
                right--;
            } else {
                right--;
            }
        }
        
        return days;
    }
};

int main() {
    Competition competition;
    competition.solveTestCases();
    return 0;
}