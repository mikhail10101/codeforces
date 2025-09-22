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
    /*
    Start with binary string s and empty string t
    Operation:
        Remove a suffix from one string and append it to the other string
    Minimum number of moves to have s only 0s and t only 1s

    00110
    _

    00
    110

    000
    11

    When we're in s and we see a 1, transfer everything after
    When we're in t and we see a 0, transfer everything after
    */
    int n; cin >> n;
    string s; cin >> s;
    int find = 1;
    ll res = 0;
    for (char c: s) {
        if (c - '0' == find) {
            res++;
            find ^= 1;
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