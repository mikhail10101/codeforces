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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[0] / 2;
        return;
    }

    // bHalf gets filled first -->
    // tHalf gets filled next <--
    vector<int> bHalf;
    vector<int> tHalf;

    vector<int> res;
    res.push_back(a[0] / 2);
    int sec = a[1] - a[0]/2;
    res.push_back(sec);
    bHalf.push_back(min(a[0] / 2, sec));
    tHalf.push_back(max(a[0] / 2, sec));
    
    int MIN_REP = -1000000000;
    int MAX_REP = 1000000000;

    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] / 2 == bHalf.back()) {
                if (!bHalf.empty()) bHalf.pop_back();
                res.push_back(MIN_REP);
            } else if (a[i] / 2 == tHalf.back()) { 
                if (!tHalf.empty()) tHalf.pop_back();
                res.push_back(MAX_REP);
            } else {
                res.push_back(a[i] / 2);
            }
        } else {
            if (a[i] < a[i - 1]) {
                tHalf.push_back(a[i - 1] / 2);
                int missing = a[i] - tHalf.back();
                if (!bHalf.empty()) {
                    if (bHalf.back() == missing) {
                        res.push_back(MIN_REP);
                    } else {
                        bHalf.push_back(missing);
                        res.push_back(missing);
                    }
                } else {
                    bHalf.push_back(missing);
                    res.push_back(missing);
                }
            } else {
                bHalf.push_back(a[i - 1] / 2);
                int missing = a[i] - bHalf.back();
                if (!tHalf.empty()) {
                    if (tHalf.back() == missing) {
                        res.push_back(MAX_REP);
                    } else {
                        tHalf.push_back(missing);
                        res.push_back(missing);
                    }
                } else {
                    tHalf.push_back(missing);
                    res.push_back(missing);
                }
            }
        }
    }

    int lower = -1000000000;
    int upper = 1000000000;
    for (int i = 0; i < n; i++) {
        if (res[i] == MIN_REP) res[i] = lower--;
        if (res[i] == MAX_REP) res[i] = upper++;
    }

    printVec(res);
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