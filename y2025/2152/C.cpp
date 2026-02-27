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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    
    vector<int> diff(n + 1);
    for (int i = 1; i < n; i++) diff[i] = diff[i - 1] + (a[i] == a[i - 1] ? 1 : 0);

    for (int q0 = 0; q0 < q; q0++) {
        int l, r; cin >> l >> r; l--; r--;
        int length = (r - l + 1);
        if (length % 3 != 0) {
            cout << "-1" << endl; continue;
        }
        int ones = pref[r + 1] - pref[l];
        if (ones % 3 != 0) {
            cout << "-1" << endl; continue;
        }
        int adjs = diff[r] - diff[l];
        if (adjs > 0) {
            cout << length / 3 << endl;
        } else {
            cout << length / 3 + 1 << endl;
        }
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