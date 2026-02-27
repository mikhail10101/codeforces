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
    ll n, L, R; cin >> n >> L >> R;
    ll res = 0;
    vector<ll> bounds(n);
    for (int i = 0; i < n; i++) cin >> bounds[i];
    sort(bounds.begin(), bounds.end());

    // Inclusive l, Exclusive r
    ll l = upper_bound(bounds.begin(), bounds.end(), L) - bounds.begin();
    ll r = lower_bound(bounds.begin(), bounds.end(), R) - bounds.begin();

    printVec(bounds);
    cout << "DEBUG " << l << " " << r << endl;


    if (l != r) {
        int x = l;
        int y = r - 1;
        while (x < y) {
            cout << "DEBUG " << x << " " << y << endl;
            res += (bounds[y] - L) - (bounds[x] - L);
            x++; y--;
        }
    }

    cout << "DEBUG " << res << endl;

    int lefts = l;
    int rights = n - r;
    cout << "DEBUG " << lefts << " " << rights << endl;

    res += max(lefts, rights) * (R - L);

    cout << "DEBUG " << res << endl;


    for (int i = 0; i < l; i++) {
        cout << "RANK " << endl;
        res += L - bounds[i];
    }
    for (int i = r; i < n; i++) {
        res += bounds[i] - R;
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