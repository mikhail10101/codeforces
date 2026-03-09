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
    /*
    x y
    1 6
    2 5
    3 4

    Each x is adjacent to every number except y

    Given a _ c, can we choose b such that it is adjacent to a and c?
    YES
    Simply choose any number from the pair not belonging to a and c
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1) {
        cout << 0;
        return;
    }

    vector<int> dp(n);
    dp[0] = 0;
    if (a[1] == a[0] || a[1] == 7 - a[0]) dp[1] = 1;

    for (int i = 2; i < n; ++i) {
        if (a[i] == a[i - 1] || a[i] == 7 - a[i - 1]) {
            dp[i] = min(
                dp[i - 1] + 1,
                dp[i - 2] + 1
            );
        } else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[n - 1];
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