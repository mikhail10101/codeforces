#include <iostream>
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

template <typename T>
void print(T a) { cout << a << endl; }
template <typename T>
void print(T a, T b) { cout << a << " " << b << endl; }
template <typename T>
void print(T a, T b, T c) { cout << a << " " << b << " " << c << endl; }
template <typename T>
void print(T a, T b, T c, T d) { cout << a << " " << b << " " << c << " " << d << endl; }
template <typename T>
void print(T a, T b, T c, T d, T e) { cout << a << " " << b << " " << c << " " << d << " " << e << endl; }

void solve() {
    int n, q; cin >> n >> q;

    long long total = 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<vector<long long>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

        if (a[u] != a[v]) {
            total += c;
        }
    }

    vector<bool> visited(n);
    vector<int> parent(n); parent[0] == -1;
    vector<long long> parent_cost(n);
    vector<unordered_map<int, long long>> colcount(n);

    auto dfs = [&] (auto self, int node) -> void {
        visited[node] = true;
        for (vector<long long> nei: adj[node]) { 
            int child = nei[0];

            if (visited[child]) {
                continue;
            }

            int color = a[child];

            parent[child] = node;
            parent_cost[child] = nei[1];

            if (colcount[node].find(color) == colcount[node].end()) {
                colcount[node][color] = nei[1];
            } else {
                colcount[node][color] += nei[1];
            }

            self(self, child);
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < q; i++) {
        int v, x; cin >> v >> x;
        v--;

        if (a[v] == x) {
            cout << total << endl;
            continue;
        }

        long long costx;
        long long costv;
        if (colcount[v].find(x) == colcount[v].end()) {
            costx = 0;
        } else {
            costx = colcount[v][x];
        }
        if (colcount[v].find(a[v]) == colcount[v].end()) {
            costv = 0;
        } else {
            costv = colcount[v][a[v]];
        }

        total -= costx;
        total += costv;

        if (v != 0) {
            if (a[v] != a[parent[v]]) {
                total -= parent_cost[v];
            }
            if (x != a[parent[v]]) {
                total += parent_cost[v];
            }
    
            colcount[parent[v]][a[v]] -= parent_cost[v];
            colcount[parent[v]][x] += parent_cost[v];
        }

        a[v] = x;

        cout << total << endl;
    }
}

bool multiple = true;

int main() {
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}