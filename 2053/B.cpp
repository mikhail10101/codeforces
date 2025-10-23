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
    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    /*
    Biggest concern are intervals of gap size = 1
    Equivalent intervals of this type cancel each other out
    All other intervals are fine
    */
    int maxi = *max_element(r.begin(), r.end());
    vector<bool> multiple(maxi + 1);
    vector<int> blocked(maxi + 1);
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i]) {
            if (blocked[r[i]]) multiple[r[i]] = true;
            blocked[r[i]] = 1;
        }
    }

    vector<int> pref(maxi + 2);
    for (int i = 1; i < maxi + 2; i++) {
        pref[i] = pref[i - 1] + blocked[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (l[i] == r[i]) {
            if (multiple[r[i]]) cout << 0;
            else cout << 1;
            continue;
        }
        int fill = pref[r[i] + 1] - pref[l[i]];
        if (fill >= r[i] - l[i] + 1) cout << 0;
        else cout << 1; 
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