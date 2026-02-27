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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = max(a[n - 1], 2 * a[i]) - a[i] - a[j];
            int k = upper_bound(a.begin(), a.begin() + j, x) - a.begin();
            res += j - k;
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