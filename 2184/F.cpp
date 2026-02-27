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

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n, -1);
    vector<vector<bool>> dp(n, vector<bool>(3, false));
    
    for (int i = 0; i < n; i++) {
        dp[i][1] = true;
    }

    auto dfs = [&] (auto self, int node) -> void {
        int children = 0;
        for (int child: adj[node]) {
            if (child == parent[node]) continue;
            parent[child] = node;
            self(self, child);
            children++;
        }

        int zeroes = 0;
        int twos = 0;
        for (int child: adj[node]) {
            if (child == parent[node]) continue;
            if (dp[child][0]) zeroes++;
            if (dp[child][2]) twos++;
        }

        int k = children % 3;
        if (children != 0) dp[node][k] = true;
        if (zeroes >= 1) dp[node][(k - 1 + 3) % 3] = true;
        if (twos >= 1) dp[node][(k + 1) % 3] = true;
        if (zeroes >= 2) dp[node][(k + 1) % 3] = true;
        if (twos >= 2) dp[node][(k - 1 + 3) % 3] = true;

        // cout << "NODE " << node << endl;
        // cout << zeroes <<  " " << twos << endl;
        // for (int i = 0; i < 3; i++) {
        //     cout << "For k " << i << ", " << (dp[node][i] ? "True" : "False") << endl;
        // } cout << endl;
    };

    dfs(dfs, 0);

    if (dp[0][0]) cout << YES;
    else cout << NO;
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