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

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    int n, h, l; cin >> n >> h >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int hcount = 0; int lcount = 0;
    for (int x: a) {
        if (x <= h) ++hcount;
        if (x <= l) ++lcount;
    }

    int excess = max(hcount, lcount) - min(hcount, lcount);
    if (excess > min(hcount, lcount)) {
        cout << min(excess, max(hcount, lcount) - excess);
    } else {
        cout << excess + (min(hcount, lcount) - excess) / 2;
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