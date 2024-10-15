#include<bits/stdc++.h>

using namespace std;

int countWays(int n) {
    // Base cases
    if (n == 1) return 3;  //These are the base cases 
    if (n == 2) return 8;  

    // Recursive step
    return 2 * countWays(n - 1) + 2 * countWays(n - 2);
}

int main() {
    int n;
    cin >> n;

    int result = countWays(n);
    cout << result << endl;

    return 0;
}
