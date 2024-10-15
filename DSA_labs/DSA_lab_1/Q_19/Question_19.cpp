#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> fillHashPatt(int n) {
    // Initialize a 2D vector with ' ' (space) as the default character
    vector<vector<char>> Pattern(n, vector<char>(n, ' '));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                Pattern[i][j] = '#';
            }
            else if(i == 0 || i == (n-1)) {
                Pattern[i][j] = '#';
            }
            else if(j == 0 || j == (n-1)) {
                Pattern[i][j] = '#';
            }
            Pattern[i][n-i-1]='#';
        }
    }

    return Pattern;
}

int main() {
    int n;
    
    // Taking input for the size of the matrix
    cin >> n;
    
    // Function call to generate the matrix pattern
    vector<vector<char>> result = fillHashPatt(n);
    
    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
