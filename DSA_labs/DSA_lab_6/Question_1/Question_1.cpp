#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    ll k;
    vector<ll> a; 
public:
    Solution(ll damage, vector<ll> v) {
        k = damage;
        a = v;
    }
    
    // Function to find the order in which creatures are defeated
    vector<ll> solve() {
        vector<ll> order;
        
        while (true) {
            // Find the index of the creature with the highest health
            ll maxHealth = -1;
            ll Index = -1;
            
            for (ll i = 0; i < a.size(); i++) {
                if (a[i] > maxHealth) {
                    maxHealth = a[i];
                    Index = i;
                }
            }
            
            // If no creatures with positive health remain, break out of the loop
            if (maxHealth <= 0) break;
            
            // Attack the selected creature
            if (a[Index] <= k) {
                a[Index] = 0;  // Creature is defeated
                order.push_back(Index);
            } else {
                a[Index] -= k; // Reduce health by K
            }
        }
        
        return order; // Return the order of defeated creatures directly
    }
};

// Do not change this starter code
int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(k>0 && n>0){
         Solution S(k, a);

        vector<ll> ans = S.solve();
        for (auto i : ans) {
            cout << i << " ";
        }
    }

    return 0;
}
