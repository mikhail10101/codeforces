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

void solve() {
    int n; cin >> n;
    vector<int> par(n);
    vector<pair<int, int>> children(n, {-1, -1});
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        if (a == -1) continue;
        par[a] = i;
        par[b] = i;
        children[i].first = a;
        children[i].second = b;
    }

    // At leaf, always go up
    // Search left if left is not searched
    // Search right if right is not searched
    // Go up

    /*
    So if Bob moves up from a leaf, no mark is left behind
    This means the leaf is inevitably visited again

    More so, when R moves up from searching, he erases the mark previously left
    This means that he is always traversing the whole tree at each point in time
    */
    ll MOD = 1000000007;
    vector<ll> dp(n);
    
    auto dfs = [&] (auto self, int node) -> void {
        if (children[node].first == -1) {
            dp[node] = 0; return;
        }

        self(self, children[node].first);
        self(self, children[node].second);

        dp[node] = (dp[children[node].first] + dp[children[node].second] + 4) % MOD;
    };

    dfs(dfs, 0);
    
    auto dfs2 = [&] (auto self, int node) -> void {
        if (children[node].first == -1) {
            return;
        }

        dp[children[node].first] += dp[node] + 1;
        dp[children[node].second] += dp[node] + 1;

        dp[children[node].first] %= MOD;
        dp[children[node].second] %= MOD;

        self(self, children[node].first);
        self(self, children[node].second);
    };

    dfs2(dfs2, 0);
    for (ll& x: dp) x = (x + 1) % MOD;

    printVec(dp);
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