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

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;

    /*
    Provided certain numbers as left endpoints and right endpoints
    After a number is used as an endpoint, it cannot be used anymore

    Try to maximize the sum
    
    Insight: Using the lowest L point and the highest R point greedily is
    always beneficial

    How can we prove this?
    Possibly contradiction is LRLLLR

    But we see here that taking the leftmost and the rightmost is the same
    as breaking it up
    For bounded LLLRRR, it doesn't matter what order we choose.
    */
    vector<ll> prefSum(n + 1);
    for (int i = 1; i <= n; i++) prefSum[i] = prefSum[i - 1] + a[i - 1];

    ll res = 0;

    int r = n - 1;
    for (int l = 0; l < n; l++) {
        if (s[l] == 'R') continue;
        while (r >= 0 && s[r] == 'L') r--;
        if (l < r) {
            res += prefSum[r + 1] - prefSum[l];
        } else {
            break;
        }
        r--;
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