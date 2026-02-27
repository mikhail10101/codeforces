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

void solve() {
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n + 2);
    if (a[n - 1] > x) dp[n - 1] = 1;
    else dp[n - 1] = 0;

    ll total = a[n - 1];
    int right = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        total += a[i];
        while (total > x) {
            total -= a[right];
            right--;
        }
        if (right + 1 < n && total + a[right + 1] > x) {
            dp[i] = 1 + dp[right + 2];
        }
    }

    printVec(dp);
    ll S = accumulate(dp.begin(), dp.end(), 0ll);
    cout <<  n * (n - 1) / 2 + n - S;
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