#include <iostream>
#include <vector>
using namespace std;

class ArrayProcessor {
private:
    int *arr; // Vector to hold the array elements
    int n;           // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations

public:
    // Constructor to initialize the array size and elements
    ArrayProcessor(int size) {
        n = size;
        arr = new int[n];    
    }

    // Function to input the elements of the array from the user
    void inputArray() {
        for(int i=0;i<n;i++) cin>>arr[i];
    }

    // Function to print reversed or original groups of 3 elements
void printReversedGroups() {
    int count = 0;
    
    for (int i = 0; count < 20; i++) {
        for (int j = 0; j < 3; j++) {
            int index = (i + 2 - j) % n;
            cout << arr[index] << " ";
        }
        
        if ((i + 3) % n == 0) {
            count++;
        }
        
        if ((i + 1) % n < i % n) {
            count++;
        }
    }
}

int main() {
    int n;

    // Ask the user for the number of elements in the array

    cin >> n;

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray();

    // Print the reversed groups
    processor.printReversedGroups();

    return 0;
}