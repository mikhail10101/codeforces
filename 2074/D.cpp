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
    int n, m; cin >> n >> m;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    unordered_map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        ll c = x[i]; ll rad = r[i];
        for (ll pos = c - rad; pos <= c + rad; pos++) {
            cnt[pos] = max(cnt[pos], 2 * (ll)sqrt(
                rad * rad - abs(pos - c) * abs(pos - c)
            ) + 1);
        }
    }

    ll res = 0;
    for (auto [x, c]: cnt) {
        res += c;
    }

    cout << res;
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