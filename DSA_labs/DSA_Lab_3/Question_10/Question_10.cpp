#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    void push(int value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    int top() const {
        if (!elements.empty()) {
            return elements.back();
        }
        return -1;  
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    vector<int> getElements() const {
        return elements;
    }
};

class Collisions {
private:
    vector<int> arr;
    Stack stack;

public:
    Collisions(vector<int>& arr) {
        this->arr = arr;
    }

    vector<int> solve() {
        for (int i = 0; i < arr.size(); ++i) {
            int curr = arr[i];

            
            while (!stack.empty() && stack.top() > 0 && curr < 0) {
                int topAsteroid = stack.top();
                
                // Collision case: both asteroids are moving towards each other
                if (topAsteroid + curr < 0) {
                    stack.pop();  // The top asteroid gets destroyed
                } else if (topAsteroid + curr == 0) {
                    stack.pop();  // Both asteroids get destroyed
                    curr = 0;  // Mark current as destroyed
                } else {
                    curr = 0;  // Current asteroid gets destroyed
                }
            }

            // If the current asteroid is still alive (not destroyed), push it onto the stack
            if (curr != 0) {
                stack.push(curr);
            }
        }

        return stack.getElements();  // Return the elements remaining in the stack after all collisions
    }
};
/*Logic-->The code simulates asteroid collisions using a stack. Right-moving asteroids (positive numbers) are added to the stack because they can't collide with each other. When a left-moving asteroid (negative number) is encountered, the code checks if it collides with the right-moving asteroid at the top of the stack. If the left-moving asteroid is larger, it destroys the one on the stack. If they are the same size, both are destroyed. If the right-moving asteroid is larger, it survives, and the left-moving one is destroyed. After processing all asteroids, the stack contains the final positions of any surviving asteroids.*/

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Collisions action(arr);
    vector<int> result = action.solve();

    for (int value : result) {
        cout << value << " ";
    }
    
    return 0;
}
