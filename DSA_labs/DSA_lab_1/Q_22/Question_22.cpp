#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<char>> convertTo2DArray(const string& str) {
    int count = 0;
    vector<int> len;

    // Calculate the length of each word
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            len.push_back(count);
            count = 0;
            continue;
        }
        count++;
    }
    len.push_back(count); // Push the last word length

    // Find the maximum word length
    int max = len[0];
    for (int i = 1; i < len.size(); i++) {
        if (len[i] > max) {
            max = len[i];
        }
    }

    // Initialize the matrix with spaces
    vector<vector<char>> matrix(len.size(), vector<char>(max, ' '));

    // Fill the matrix with characters from the string
    int row = 0, col = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            row++;
            col = 0;
            continue;
        }
        matrix[row][col] = str[i];
        col++;
    }

    return matrix;
}

int main() {
    string input;
    getline(cin, input);

    // Convert the input string to a 2D matrix
    vector<vector<char>> result = convertTo2DArray(input);

    // Print the matrix
    for (const auto& row : result) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << "'" << row[j] << "' ";
        }
        cout << "]" << endl;
    }

    return 0;
}
