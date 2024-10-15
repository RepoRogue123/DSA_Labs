#include <iostream>
#include <vector>

using namespace std;

int IndicesIncrementAndEvenCounter(vector<vector<int>>& index, int n, int m) {
    int evenCount = 0;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < index.size(); ++i) {
        int row = (*index)[i].first;
        int col = (*index)[i].second;

        if (row >= 0 && row < n) {
            for (int j = 0; j < m; ++j) {
                matrix[row][j]++;
            }
        }

        if (col >= 0 && col < m) {
            for (int k = 0; k < n; ++k) {
                matrix[k][col]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] % 2 == 0) {
                evenCount++;
            }
        }
    }

    return evenCount;
}

int main() {
    int n, m;
    int index_len;

    // Read the dimensions of the matrix
    cin >> n >> m;

    // Read the number of index pairs
    cin >> index_len;

    // Initialize the vector to hold the index pairs
    vector<pair<int,int>> index(index_len);

    // Read the index pairs if index_len > 0
    if (index_len > 0) {
        for (int i = 0; i < index_len; i++) {
            cin >> index[i].first >> index[i].second;
        }
    }

    int evenCount = IndicesIncrementAndEvenCounter(index, n, m);
    cout << evenCount << endl;

    return 0;
}