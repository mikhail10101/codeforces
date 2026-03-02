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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n + 1, 1000);
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());

    int m = a.size();
    for (int i = 0; i < m; i++) {
        dp[a[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1000) continue;
        for (int j = 0; j < m; j++) {
            ll multi = a[j];
            ll prod = i * multi;
            if (prod <= n) {
                dp[prod] = min(dp[prod], 1 + dp[i]);
            } else break;
        }
    }

    replace(dp.begin(), dp.end(), 1000, -1);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
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