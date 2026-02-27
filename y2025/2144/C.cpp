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
const ll MODULO = 998244353;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    /*
    Two arrays a and b
    GOOD means that after swapping a subset of indexes, both arrays
    are sorted in non-descending order
    How many good subsets?

    1 3 5 3 4
    2 4 9 3 6

    Run a dp of whether a swap was done or not?
    Loop starting the last index

    dp[i][0] is good subsets up to that point if no swap happened at i
    dp[i][1] is good subsets up to that point if a swap happened at i
    */
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[n - 1][0] = 1; dp[n - 1][1] = 1;
    
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1] && b[i] <= b[i + 1]) {
            dp[i][0] += dp[i + 1][0];
            dp[i][1] += dp[i + 1][1];
        }
        dp[i][0] %= MODULO;
        dp[i][1] %= MODULO;
        if (b[i] <= a[i + 1] && a[i] <= b[i + 1]) {
            dp[i][0] += dp[i + 1][1];
            dp[i][1] += dp[i + 1][0];
        }
        dp[i][0] %= MODULO;
        dp[i][1] %= MODULO;
    }

    cout << (dp[0][0] + dp[0][1]) % MODULO;
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