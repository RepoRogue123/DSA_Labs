#include <iostream>
#include <vector>
#include <sstream>

using namespace std;




int main() {
    string input;
    getline(cin, input);

    int count =0;
    vector<int>len;

    for(int i=0;i<input.size();i++){

        if(input[i]==' '){
            len.push_back(count);
            count =0;
            continue;

        }

        count ++;
        
    }
    len.push_back(count);

    for(int i=0;i<len.size();i++){
        cout<<len[i]<<" ";
    }
}