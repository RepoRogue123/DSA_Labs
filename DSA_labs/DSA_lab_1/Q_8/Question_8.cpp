#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class solution {
public:
    vector<int> intersection;

    int solve(vi& a, vi& b) {
        int n = a.size(), m = b.size();

        // Find the intersection
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    // Check if the element is already in the intersection vector
                    int flag = 0;
                    for (int k = 0; k < intersection.size(); k++) {
                        if (intersection[k] == a[i]) {
                            flag=1;
                            break;
                        }
                    }
                    if (flag==0) {
                        intersection.push_back(a[i]);
                    }
                    break;
                }
            }
        }

        return intersection.size(); // Return the size of the intersection array
    }

    void Display() {
        for (auto it : intersection) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    vi b(m);

    // Fill the vectors with input
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Create solution object and solve
    solution S;
    int result = S.solve(a, b);

    // Display intersection and result
    cout << result << endl;

    return 0;
}
