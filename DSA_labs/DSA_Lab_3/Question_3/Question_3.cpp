#include <iostream>
#define MAX_SIZE 100  

using namespace std;


class TwoStacks {
    int arr[MAX_SIZE];
    int top1;  
    int top2;  

public:
   
    TwoStacks() {
        initialize();
    }
    void initialize(){
        top1=-1;
        top2=MAX_SIZE;
    }

    void push1(int x) {
        
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << 1 << endl;  
        }
    }

   
    void push2(int x) {
       
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << 1 << endl;  
        }
    }

    
    int pop1() {
        
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << -1 << endl;  
            return -1;
        }
    }

    int pop2() {
        
        if (top2 < MAX_SIZE) {
            return arr[top2++];
        } else {
            cout << -1 << endl;  
            return -1;
        }
    }

 
    void printBoth() {
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = MAX_SIZE - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    TwoStacks ts;

    int x, y;
    cin >> x;

    
    for (int i = 0; i < x; i++) {
        int val;
        cin >> val;
        ts.push1(val);
    }

    cin >> y;


    for (int i = 0; i < y; i++) {
        int val;
        cin >> val;
        ts.push2(val);
    }

 
    ts.printBoth();


    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;

    ts.printBoth();

    return 0;
}
