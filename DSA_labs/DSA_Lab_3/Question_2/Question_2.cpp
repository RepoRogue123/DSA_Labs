#include <bits/stdc++.h>
using namespace std;

class Stack {
    int top;
    int size;
    vector<char> v;

public:
    Stack(int max_size) {
        top = -1;
        size = max_size;
        v = vector<char>(size, ' ');
    }

    int isEmpty() {
        return top == -1;
    }

    int push(char data) {
        if (top == (size - 1)) {
            return -1;  // Stack is full
        }
        v[++top] = data;
       
    }

    char pop() {
        if (isEmpty()) {
            return '\0';  // Stack is empty
        }
        return v[top--];
    }

    char peek() {
        if (isEmpty()) {
            return 0;  // Stack is empty
        }
        return v[top];
    }
};

bool isValid(string s) {
    Stack S1(s.size());

    for (int i=0;i<s.size();i++) {
        if (s[i]== '(' || s[i] == '{' || s[i] == '[') {
            S1.push(s[i]);
        } else {
            if (S1.isEmpty()) {
                return false;
            }
            char topChar = S1.peek();
            if ((s[i] == ')' && topChar != '(') ||
                (s[i]== '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                return false;
            }
            S1.pop();
        }
    }
    return S1.isEmpty(); 
}

int main() {
    string s;
    cin >> s;

    cout << (isValid(s) ? 1 : 0) << endl;

    return 0;
}
