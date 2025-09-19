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

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    
    vector<long long> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    /*
    We simply simulate the worst case scenario
    Instead of l and r, we have a and b where a >= b

    1) Choose all a and no pairs are formed
    2) Choose all the largest bs
    */

    for (int i = 0; i < n; i++) {
        if (l[i] < r[i]) {
            long long temp = l[i];
            l[i] = r[i];
            r[i] = temp;
        }
    }

    long long res = accumulate(l.begin(), l.end(), 0ll);
    sort(r.begin(), r.end(), greater<long long>());
    res += accumulate(r.begin(), r.begin() + k - 1, 0ll);
    res += 1;

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