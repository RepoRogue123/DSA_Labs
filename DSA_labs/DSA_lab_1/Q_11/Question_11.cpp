#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> M;

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) {
        n = size;
        M = vector<vector<int>>(n, vector<int>(n)); // Initialize M with the correct size
    }

    // Method to input matrix elements
    void inputMatrix() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
    }

    // Method to print the lower triangular matrix
    void printLowerTriangularMatrix() const {
        vector<vector<int>> final_arr(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i > j) {
                    final_arr[i][j] = M[i][j];
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << final_arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> Matrix(n); // Initialize the Matrix with the correct size

    // Create a SquareMatrix object
    SquareMatrix Mat(n);

    // Input matrix elements
    Mat.inputMatrix();

    // Print the lower triangular matrix
    Mat.printLowerTriangularMatrix();

    return 0;
}
