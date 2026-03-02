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
    /*
    We want to maximize threshold * levels completed
    Is the invariant true: higher threshold means less/equal levels completed
    YES
    */
    int n; cin >> n;
    map<int, int> cnt;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int sword; cin >> sword;
        cnt[sword]++;
    }
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    ll res = 0;
    ll cur = 0;
    for (auto& [k, v]: cnt) {
        int x = n - cur; // Swords available when the threshold is k
        ll lvl = upper_bound(pref.begin(), pref.end(), x) - pref.begin() - 1; // amt of levels passed
        // cout << k << " " << lvl << " " << x << endl;
        res = max(res, k * lvl);
        cur += v; 
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