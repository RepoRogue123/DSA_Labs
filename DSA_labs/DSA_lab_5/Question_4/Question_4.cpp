#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class SubListFinder {
public:
    SubListFinder(const T* arr) : arr(arr), n(strlen(arr)) {}
    
    void findSublists() const {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] == arr[i+1]) {
                printSublist(arr[i], arr[i+1]);
            }
            if (i < n - 2 && arr[i] == arr[i+2]) {
                printSublist(arr[i], arr[i+1], arr[i+2]);
            }
        }
        cout << "..." << endl;
    }

private:
    const T* arr;
    int n;

    void printSublist(char a, char b) const {
        cout << a << b << ", ";
    }

    void printSublist(char a, char b, char c) const {
        cout << a << b << c << ", ";
    }
};

int main() {
    char input[100001]; 
    cin >> input;
    SubListFinder<char> finder(input);
    finder.findSublists();
    return 0;
}