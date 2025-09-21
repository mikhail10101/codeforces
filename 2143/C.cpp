#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    /*
    We have a tree vertices 1 to n
    Each edge has an x and y value

    Case: u < v
    if p[u] > p[v], x, else, y

    Max total contribution of all edges
    We can assign p as a permutation

    If we start with the leaves, we can easily
    determine the optimal value of these edges

    We can assign the leaves values at the end at all times
    */
    int n; cin >> n;
    vector<vector<vector<int>>> adj(n);
    for (int i = 0, u, v, x, y; i < n-1; i++) {
        cin >> u >> v >> x >> y;
        u--; v--;
        adj[u].push_back({v, x, y});
        adj[v].push_back({u, x, y});
    }

    vector<vector<int>> par(n, {-1, -1, -1});
    vector<int> res(n);

    int low = 1;
    int high = n;

    auto dfs = [&] (auto self, int node) -> void {
        for (vector<int> nbrVec: adj[node]) {
            int nbr = nbrVec[0];
            if (nbr != par[node][0]) {
                par[nbr][0] = node;
                par[nbr][1] = nbrVec[1];
                par[nbr][2] = nbrVec[2];
                self(self, nbr);
            }
        }
 
        if (par[node][0] == -1) {
            res[node] = high;
            return;
        }

        int u = min(node, par[node][0]);
        int v = max(node, par[node][0]);
        int x = par[node][1];
        int y = par[node][2];

        if (x > y) {
            res[node] = u == node ? high-- : low++; 
        } else {
            res[node] = v == node ? high-- : low++;
        }
    };

    dfs(dfs, 0);
    printVec(res);
}

bool multiple = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}