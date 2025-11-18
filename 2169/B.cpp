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
    /*
    Monocarp can sail infinitely if
    ><
    *<
    >*
    **

    Otheriwse, he's forced to stop at some point
    Either we've found
    <*> or <>
    Search for this spot and find the longest distance possible
    */
    vector<vector<char>> infinite = {
        {'>', '<'},
        {'*', '<'},
        {'>', '*'},
        {'*', '*'},
    };

    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        for (vector<char> pat: infinite) {
            if (pat[0] == s[i - 1] && pat[1] == s[i]) {
                cout << -1; return;
            }
        }
    }

    int l = 0;
    while (l < n && s[l] == '<') l++;
    int r = n - 1;
    while (r >= 0 && s[r] == '>') r--;

    int rcnt = (n - 1) - r;

    if (l <= r) cout << max(l, rcnt) + (r - l + 1);
    else cout << max(l, rcnt);
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