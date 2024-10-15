#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class Stack{
    int top;
    vector<int> v;
    int maxSize;

public:

    Stack(int size){
        v = vector<int>(size,0);
        maxSize = size;
        top = -1;
    }

    bool isEmpty(){
        if(top == -1) 
            return true;
        return false;
          // single boolean expression : when is the stack empty? //
    }

    bool isFull(){
        if( top == maxSize - 1)return true;
        return false; // single boolean expression : when is the stack full? //
    }

    int peek(){
        // return the element at the top
        return v[top];
    }

    int pop(){
        if(isEmpty()) cerr << "Popping from empty stack";
        // remomove the top element and return it
        return v[top--];
    }

    void push(int x){
        if(isFull()) cerr << "Pushing into a full stack";
        v[++top] = x;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--) cout << v[i] <<" ";
        cout<<'\n';
    }

};

ll sum_minOfSubArrays(vector<ll>& v){
    int n = v.size();

    vector<int> before(n, -1), after(n, -1);

    Stack s1(2*n);
    Stack s2(2*n);

    // calculation of before
    for (int i = n-1; i >=0; i--) {
        while (!s1.isEmpty() && v[s1.peek()] >= v[i]) {
            before[s1.pop()]=i;
        }
        s1.push(i);
    }


    // calculation of after
    for (int i = 0; i < n; ++i) {
        while (!s2.isEmpty() && v[s2.peek()] > v[i]) {
            after[s2.pop()] = i;
        }
        s2.push(i);
    }

    ll result = 0;
    // calculation of result sum
    for (int i = 0; i < n; ++i) {
        if(after[i]==-1){
            after[i]=n;
        }
        result = (result + v[i] * (after[i]-i)* (i-before[i])) % mod;
    }

    return result;
    // Complete the function now

}

int main() {

    int n; cin >> n;
    vector<ll> v(n,0); for(int i=0;i<n;i++) cin >> v[i];

    cout << sum_minOfSubArrays(v);

    return 0;
}