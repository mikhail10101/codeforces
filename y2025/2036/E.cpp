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
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[j][i];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            a[j][i] |= a[j][i-1];
        }
    }

    for (int z = 0; z < q; z++) {
        int m; cin >> m;
        int left = 0;
        int right = n;
        for (int y = 0; y < m; y++) {
            int region, value;
            char compr;
            cin >> region >> compr >> value;
            vector<int>& regVec = a[region-1];
            if (compr == '>') {
                int idx = upper_bound(regVec.begin(), regVec.end(), value) - regVec.begin();
                left = max(left, idx);
            } else {
                // <
                int idx = lower_bound(regVec.begin(), regVec.end(), value) - regVec.begin();
                right = min(right, idx);
            }
        }

        if (left >= right) {
            cout << -1;
        } else {
            cout << left + 1;
        } cout << endl;
    }
}

bool multiple = false;

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