#include <iostream>
#include <vector>
using namespace std;

class CharacterMatrix {
private:
    int n;
    char startChar;
    char arr[100][100];
   

public:
    // Constructor to initialize the matrix size and starting character
    CharacterMatrix(int size, char ch) {
        // TODO: Initialize the matrix storage
        n=size;
        startChar=ch;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=' ';
            }
        }
       
       
       
        
    }

    // Method to generate the concentric character matrix
    void generateMatrix() {
        // TODO: Implement the logic to generate the matrix
        
        for (int row_start = 0, row_end = n - 1,col_start = 0, col_end = n- 1; row_start <= row_end && col_start <= col_end; row_start++, col_end--, row_end--, col_start++) {
        
        // Print the top row
            for (int i = col_start; i <= col_end; i++) {
                arr[row_start][i]=startChar;
            }

        // Print the right column
            for (int i = row_start + 1; i <= row_end; i++) {
                arr[i][col_end] = startChar;
            }

        // Print the bottom row
            if (row_start < row_end) {
                for (int i = col_end - 1; i >= col_start; i--) {
                    arr[row_end][i]=startChar;
                }
            }

        // Print the left column
            if (col_start < col_end) {
                for (int i = row_end - 1; i > row_start; i--) {
                    arr[i][col_start]=startChar;
                }
            }
            if(startChar=='z'|| startChar=='Z'){
                if(startChar=='z'){
                    startChar='a'-1;
                }
                if(startChar=='Z'){
                    startChar='A'-1;
                }
            }
            startChar++;
        }
        
    }

    // Method to print the generated matrix
    void printMatrix() const {
        // TODO: Implement the logic to print the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    char startChar;

    // Read the size of the matrix
    cin >> n;
    // Read the starting character
    cin >> startChar;

    // TODO: Create a CharacterMatrix object
    CharacterMatrix Mat(n,startChar);



    // TODO: Generate and print the character matrix
    Mat.generateMatrix();
    Mat.printMatrix();

    return 0;
}