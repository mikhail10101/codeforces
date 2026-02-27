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
    int n; cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];

    vector<int> prefMin(n), prefMax(n), suffMin(n), suffMax(n);
    prefMin[0] = a[0][0];
    prefMax[0] = a[0][0];
    for (int i = 1; i < n; i++) {
        prefMin[i] = min(prefMin[i - 1], a[0][i]);
        prefMax[i] = max(prefMax[i - 1], a[0][i]);
    }
    suffMin[n - 1] = a[1][n - 1];
    suffMax[n - 1] = a[1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffMin[i] = min(suffMin[i + 1], a[1][i]);
        suffMax[i] = max(suffMax[i + 1], a[1][i]);
    }

    vector<pair<int, int>> gaps;
    for (int i = 0; i < n; i++) {
        int mini = min(prefMin[i], suffMin[i]);
        int maxi = max(prefMax[i], suffMax[i]);
        gaps.push_back({mini, maxi});
    }

    sort(gaps.begin(), gaps.end());

    ll res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        pair<int, int> search = {i, 0};
        auto it = lower_bound(gaps.begin(), gaps.end(), search);
        if (it != gaps.end()) {
            auto [a, b] = *it;
            res += (2 * n - b + 1);
        }
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