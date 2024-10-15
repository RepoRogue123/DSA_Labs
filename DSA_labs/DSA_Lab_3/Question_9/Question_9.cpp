#include <iostream>
#define MAX 100

using namespace std;

class Queue {
private:
    int items[MAX];
    int start, end;

public:
    Queue() {
        start = -1;
        end = -1;
    }

    bool isFull() {
        return (end == MAX - 1);
    }

    bool isEmpty() {
        return (start == -1 && end == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            start = 0;
            end = 0;
        } else {
            end++;
        }
        items[end] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int item = items[start];
        if (start == end) {
            start = -1;
            end = -1;
        } else {
            start++;
        }
        return item;
    }

    int getstart() {
        if (isEmpty()) {
            return -1;
        }
        return items[start];
    }

    void printWholeQueue() {
        if (isEmpty()) {
            return;
        }
        while (!isEmpty()) {
            cout << dequeue() << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n, value;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << q.getstart() << endl;
    cout << q.dequeue() << endl;
    q.printWholeQueue();
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}