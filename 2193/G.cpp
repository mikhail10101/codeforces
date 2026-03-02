#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;
const string NO = "NO";
const string YES = "YES";

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

bool askAndAnswer(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int ans; cin >> ans;

    if (ans == 1) {
        cout << "? " << a + 1 << " " << a + 1 << endl;
        cin >> ans;
        if (ans == 1) {
            cout << "! " << a + 1 << endl;
        } else {
            cout << "! " << b + 1 << endl;
        }
        return true;
    } 
    return false;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n, -1);

    auto dfs = [&] (auto self, int node) -> void {
        for (int child: adj[node]) {
            if (child == par[node]) continue;
            par[child] = node;
            self(self, child);
        }
    };

    dfs(dfs, 0);
    
    deque<int> queue = {0};
    vector<int> leaves;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop_front();

        if (adj[node].size() == 1 && adj[node][0] == par[node])
            leaves.push_back(node);
        else {
            int i = 0;
            while (adj[node][i] == par[node]) ++i;

            bool success = askAndAnswer(node, adj[node][i]);
            if (success) return;

            for (int j = i + 1; j < adj[node].size(); ++j) {
                if (adj[node][j] == par[node]) continue;
                queue.push_back(adj[node][j]);
            }

            for (int child: adj[adj[node][i]]) {
                if (child == par[adj[node][i]]) continue;
                queue.push_back(child);
            }
        }
    }

    for (int i = 0; i < leaves.size() / 2; i++) {
        int a = leaves[2 * i];
        int b = leaves[2 * i + 1];
        bool success = askAndAnswer(a, b);
        if (success) return;
    }

    cout << "! " << leaves[leaves.size() - 1] + 1 << endl;
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