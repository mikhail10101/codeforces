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
    vector<int> a(n);
    for (int i =0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> singles;
    ll pairSum = 0;

    int i = 0;
    int pairsFound = 0;
    while (i < n) {
        if (i + 1 < n && a[i] == a[i+1]) {
            pairSum += a[i] * 2;
            pairsFound++;
            i += 2;
        } else {
            singles.push_back(a[i]);
            i++;
        }
    }

    if (pairsFound == 0) {
        cout << 0; return;
    }

    ll res = pairSum;
    for (int edge: singles) {
        if (edge < pairSum) {
            res = max(res, pairSum + edge);
        }
    }

    for (int i = 1; i < singles.size(); i++) {
        int diff = singles[i] - singles[i - 1];
        if (diff < pairSum) {
            res = max(res, pairSum + singles[i] + singles[i - 1]);
        }
    }

    if (pairsFound == 1 && res == pairSum) {
        cout << 0; 
    } else {
        cout << res;
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