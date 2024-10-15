#include <bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
/*Logic : We iterate through every element of infix, wherever we find an operand we store it in the postfix string, wherever we find open bracket, irrespective of the priority we push it to the stack,wherever we find a closed bracket we have to pop all the elements out of the stack untill an open bracket is located,and rest if we find an operator less than the priority of that at the top of the stack, then we replace the operator in the stack with that in the string and append the operator in the stack with the prefix string, and finally we empty all the stack by popping every element out*/

void infixToPostfix(const char* infix, char* postfix) {
    stack<char> st;
    int i = 0, k = 0;
    int n = strlen(infix);

    while(i < n) {
        if((infix[i]>='A' && infix[i]<='Z') || (infix[i]>='a' && infix[i]<='z') || (infix[i]>='0' && infix[i]<='9')){
            postfix[k++] = infix[i];
        }
        else if(infix[i] == '('){
            st.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!st.empty() && st.top() != '('){
                postfix[k++] = st.top();
                st.pop();
            }
            st.pop();  
        }
        else {
            while(!st.empty() && priority(infix[i]) <= priority(st.top())){
                postfix[k++] = st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        i++;
    }

    // Pop all the operators from the stack
    while(!st.empty()){
        postfix[k++] = st.top();
        st.pop();
    }
    postfix[k] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}
