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
    /*
    Items can be bought on their own
    Or they can be bought in groups where the cheapest item is free
    We want to maximize our use of vouchers
    */
    int n, k; cin >> n >> k;
    vector<long long> a(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    long long total = accumulate(a.begin(), a.end(), 0ll);

    int idx = 0;
    for (int x: b) {
        if (idx + x - 1 < n) {
            total -= a[idx + x - 1];
            idx += x;
        } else {
            break;
        }
    }

    cout << total;
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