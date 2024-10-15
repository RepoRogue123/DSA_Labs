#include <iostream>
#include <vector>
using namespace std;

// Class representing a Tree
class Tree {
private:
    int n;
    vector<vector<int>> ans;
    int maxRoutes;

    void dfs(int v, int parent, vector<int>& num_routes) {
        int sum = 0;
        for (int u : ans[v]) {
            if (u != parent) {
                dfs(u, v, num_routes);
                sum += num_routes[u];
            }
        }
        num_routes[v] = max(1, sum);
        maxRoutes += sum;
    }

public:
    Tree(int vertices) : n(vertices), ans(vertices + 1), maxRoutes(0) {}

    void addEdge(int u, int v) {
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
/*Loigc -->> The code uses depth-first search (DFS) to traverse the tree from bottom to top.
For each vertex, it calculates the maximum number of non-redundant routes that can be formed using its subtree, storing this value in a dynamic programming (DP) array.
As the DFS backtracks, it accumulates the total number of non-redundant routes by summing the contributions from each vertex's children, ensuring no route is a subset of another.*/

    int calculateMaxRoutes() {
        vector<int> num_routes(n + 1, 0);
        dfs(1, 0, num_routes);
        return maxRoutes;
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    cout << tree.calculateMaxRoutes() << endl;
    return 0;
}