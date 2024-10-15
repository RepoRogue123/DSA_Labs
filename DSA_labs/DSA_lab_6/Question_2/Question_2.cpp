#include<bits/stdc++.h>
using namespace std;

class TriangleCounter {
private:
    long long n; // Number of sticks
    vector<long long> lengths; // Array to hold stick lengths

public:
    TriangleCounter(long long num, const vector<long long>& ar) : n(num), lengths(ar) {}

    void solve() {
        vector<long long> actualLengths(n);
        for (int i = 0; i < n; i++) {
            actualLengths[i] = pow(2,lengths[i]); // Calculate 2^ai
        }
        
        sort(actualLengths.begin(), actualLengths.end());
        
        long long count = 0;
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1; j++) {
                while (k < n && actualLengths[i] + actualLengths[j] > actualLengths[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        
        cout << count << endl;
    }
};

int main() {
    long long n;
    cin >> n;
    vector<long long> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    TriangleCounter counter(n, ar); // Create an object of TriangleCounter
    counter.solve(); // Call the solve method
    return 0;
}