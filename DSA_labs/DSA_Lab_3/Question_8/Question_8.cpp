#include <bits/stdc++.h>
using namespace std;

#define elif else if
#define print(s) cout << (s) << endl
#define ll long long

class Stack {

    vector<ll> values;

public:

    void push(ll val) {
        values.push_back(val);
    }
    
  
    ll pop() {
        if (!values.empty()) {
            ll temp = values.back();
            values.pop_back();
            return temp;
        }
        
        return -1;
    }
    
   
    ll top() {
        if (!values.empty()) {
            return values.back();
        }
        return -1;
    }
    

    ll size() {
        return values.size();
    }
    

    bool empty() {
        return values.empty();
    }
};
/*Logic :After the required number of pops, the code checks whether the stack is empty. If not, it ensures that the stack remains in a state where the top element is the maximum possible value among the elements involved in the num. Finally, it prints the maximum value (mx) after all num are completed.*/

int main() {

    ll mx = -1e9;


    int N, K;
    cin >> N >> K;

 
    Stack st;
    vector<ll> input(N);

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

   
    for (int i = N - 1; i >= 0; --i) {
        st.push(input[i]);
    }

    if (K == 0) {
        print(st.top());
        return 0;
    }

    int elem_1=-1;
    int num = 0;
    
    while(!st.empty() && num<K-1)
    {
        elem_1=st.pop();

        num++;
    }
    
    if(st.empty())
        mx= -1;
    else
    {
        if(st.top()<=elem_1)
            st.push(elem_1);
        else
        {
            ll elem_2=st.pop();
            
          
            if(elem_1>st.top())
            {
                st.push(elem_2);
                st.push(elem_1);
            }
        }
        
        mx=st.top();
    }
    
    print(mx);
    return 0;
}