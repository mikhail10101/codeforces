#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int res = 0;

    int a0 = 0;
    int b0 = 0;
    for (int i = 0; i < n; i++) {
        int moves = a[i] - a0;
        if (b0 == b[i]) {
            res += moves / 2 * 2;
        } else {
            if (moves > 0) {
                moves--;
                res++;
                res += moves / 2 * 2;
            }
        }
        a0 = a[i];
        b0 = b[i];
    }

    res += m - a0;

    cout << res;
}

bool multiple = true;

int main() {
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}