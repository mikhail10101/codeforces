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

using ll = long long;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool valid = false;
    int q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 2) {
            valid = true;
            q = i;
            break;
        }
    }

    if (!valid) {
        cout << "NO"; return;
    } else {
        cout << "YES" << endl;;
    }

    // p -> q -> r
    int p = adj[q][0];
    int r = adj[q][1];
    cout << p + 1 << " " << q + 1 << endl;
    cout << q + 1 << " " << r + 1 << endl;

    auto dfs = [&] (auto self, int node, int par, bool away) -> void {
        for (int nei: adj[node]) {
            if (nei != par) {
                if (away) {
                    cout << node + 1 << " " << nei + 1 << endl;
                } else {
                    cout << nei + 1 << " " << node + 1 << endl;
                }
                self(self, nei, node, !away);
            }
        }
    };

    dfs(dfs, r, q, false);
    dfs(dfs, p, q, true);
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