#include <iostream>
using namespace std;

class Solution{
public:
    void to_binary(int n, int a[32]){
        for(int i = 0; i < 32; i++){
            a[i] = 0; 
        }
        for(int i = 0; n > 0 && i < 32; i++){
            a[31 - i] = n % 2;
            n /= 2;
        }
    }   
    int count_rows_with_at_least_5_ones(int nums[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int binary[32];
        to_binary(nums[i], binary);
        int one_count = 0;
        for(int j = 0; j < 32; j++) {
            if(binary[j] == 1) {
                one_count++;
            }
        }
        if(one_count >= 5) {
            count++;
        }
    }
    return count;
}

};

void to_binary(int n, int a[32]){
    for(int i = 0; i < 32; i++){
        a[i] = 0; 
    }
    for(int i = 0; n > 0 && i < 32; i++){
        a[31 - i] = n % 2;
        n /= 2;
    }
}


int count_rows_with_at_least_5_ones(int nums[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int binary[32];
        to_binary(nums[i], binary);
        int one_count = 0;
        for(int j = 0; j < 32; j++) {
            if(binary[j] == 1) {
                one_count++;
            }
        }
        if(one_count >= 5) {
            count++;
        }
    }
    return count;
}

int main() {
    Solution S1;
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int result = S1.count_rows_with_at_least_5_ones(nums, n);
    cout << result << endl;
    
    return 0;
}
