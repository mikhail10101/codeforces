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

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

int int_log(int n, int base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    int result = 0;
    while (n >= base) {
        n /= base;
        result++;
    }
    return result;
}

int find_conseq(int n) {
    int root = (int)sqrt(n * 2);
    while (root * (root + 1) > n * 2) root--;
    return root;
}

void solve() {
    ll n, m, l; cin >> n >> m >> l;
    vector<ll> s(l);
    for (int i = 0; i < l; i++) cin >> s[i];
    vector<vector<ll>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> mn(2, vector<ll>(n, INF));
    mn[0][0] = 0;
    // Parity, Node
    deque<pair<ll, ll>> q = {{0, 0}};
    while (!q.empty()) {
        auto [parity, node] = q.front(); q.pop_front();
        for (ll nei: adj[node]) {
            if (mn[1 - parity][nei] == INF) {
                mn[1 - parity][nei] = mn[parity][node] + 1;
                q.push_back({1 - parity, nei});
            }
        }
    }

    ll minOdd = INF;
    for (ll steps: s) if (steps % 2 == 1) minOdd = min(minOdd, steps);
    ll total = accumulate(s.begin(), s.end(), 0ll);
    ll bestEven, bestOdd;
    if (total % 2 == 0) {
        bestEven = total;
        bestOdd = minOdd == INF ? 0 : total - minOdd;
    } else {
        bestOdd = total;
        bestEven = total - minOdd;
    }

    // printVec(mn[0]);
    // printVec(mn[1]);
    // cout << bestEven << " " << bestOdd << endl;

    for (int i = 0; i < n; i++) {
        if (bestEven >= mn[0][i] || bestOdd >= mn[1][i]) cout << 1;
        else cout << 0;
    }
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