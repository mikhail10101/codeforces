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

using namespace std;

using ll = long long;

const int INF = 1e9 + 11;

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
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 2) {
        if (a[0] == a[1]) {
            cout << "YES"; return;
        }
    }
    
    int total = accumulate(a.begin(), a.end(), 0);
    if (total == n) { cout << "YES"; return; }

    /*
    How do we tell if a series is valid?
    Every player plays the person after them and results come from two matches
    (except edge cases)
    If the person before me didn't win and the person after me didn't win, I'm forced
    to have one at least 1.
    If exactly one of them won, then I'm still forced to be 1.

    If both of them one, then I can be 0 or 1.
    Say A beats B and B beats C and C beats D, then they form a series of 1s.
    But, it could also mean that A beat B and C beat B and so both have a 1.

    1 0 1 1 1 0
    */
    for (int i = 1; i < n - 1; i++) {
        int cnt = a[i - 1] + a[i + 1];
        if (cnt == 0) { if (a[i] != 1) { cout << "YES"; return; }}
        if (cnt == 1) { if (a[i] != 1) { cout << "YES"; return; }}
    }
    cout << "NO";
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