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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
T manual_log(T n, T base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    T result = 0;
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
    ll n, m, k; cin >> n >> m >> k;
    ll w; cin >> w;
    vector<ll> h(w);
    for (int i = 0; i < w; i++) cin >> h[i];

    ll maxn = min(n - k + 1, k);
    ll maxm = min(m - k + 1, k);
    vector<ll> a(maxn + 1, 2), b(maxm + 1, 2);
    a[0] = 0; b[0] = 0;
    a[maxn] = n - 2 * (maxn - 1);
    b[maxm] = m - 2 * (maxm - 1);

    vector<ll> values(k * k + 1);
    for (ll i = 1; i <= maxn; i++) {
        for (ll j = 1; j <= maxm; j++) {
            values[i * j] += a[i] * b[j];
        }
    }

    sort(h.begin(), h.end(), greater<ll>());
    int ptr = k * k;

    ll res = 0;
    for (auto gorilla: h) {
        while (values[ptr] == 0) ptr--;
        res += ptr * gorilla;
        values[ptr]--;
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