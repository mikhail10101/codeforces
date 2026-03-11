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

int MOD = 998244353;

ll permute(int x) {
    ll res = 1;
    for (int i = 1; i <= x; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

void solve() {
    /*
    How many fair permutations of people
    p1 can take from box0 or from boxp1?

    Ultimately, box0 becomes a lifeline until all players can finish

    Counting the amount of permutations
    */
    int n; cin >> n;
    int box0; cin >> box0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    int maxDiff = a[n - 1] - a[0];

    // Best case scenario is doing it backwards to save the last cycle
    // Worst case scenario is doing it forwards
    int notMaxElements = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[n - 1]) ++notMaxElements;
    }

    // What does it look like when we reach the second to the last cycle?
    int necessaryBeforeLast = 0;
    for (int i = 0; i < n; ++i) {
        necessaryBeforeLast += max(0, a[n - 1] - 1 - a[i]);
    }

    box0 -= necessaryBeforeLast;
    if (box0 < 0) {
        cout << 0;
        return;
    }

    // At this point, box0 contains 0 or more
    // This is how many notMaxElements can go before our maxElements
    // The formula is then (how many ways to order notMaxElements) * (order maxElements)
    // We also multiply by box0's partition
    ll res = 1;

    // cout << "DEBUG " << notMaxElements << " " << min(box0, notMaxElements) << endl;

    res = (res * permute(notMaxElements)) % MOD;
    res = (res * permute(n - notMaxElements)) % MOD;

    // limit is the illegal amount of notMaxElement to appear
    // before all maxElements have already appeared
    // Then, within limit - 1 + maxElements, can we simply choose maxElements? YES
    int limit = min(box0, notMaxElements) + 1;
    ll reps = (nCr(limit - 1 + (n - notMaxElements), n - notMaxElements)) % MOD;

    res = (res * reps) % MOD;

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