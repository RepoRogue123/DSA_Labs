#include <bits/stdc++.h>
using namespace std;  
int main() {
   //code
   int n, m;
   cin >> n >> m;

   vector<vector<int>> arr(n, vector<int>(m, 0));
   vector<vector<int>> final_arr(n, vector<int>(m, 0));

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           cin >> arr[i][j];
       }
   }

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           int sum = 0;
           for (int k = j + 1; k < m; k++) {
               sum += arr[i][k];
           }
           final_arr[i][j] = sum;
       }
   }

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           cout << final_arr[i][j] << " ";
       }
       cout << "\n";
   }

   return 0;
}
