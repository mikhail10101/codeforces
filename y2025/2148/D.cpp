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
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> odd;
    vector<long long> even;
    for (long long d: a) {
        if (d % 2 == 0) {
            even.push_back(d);
        } else {
            odd.push_back(d);
        }
    }

    sort(odd.begin(), odd.end(), greater<long long>());

    if (odd.size() == 0) {
        cout << 0; return;
    }

    long long res = accumulate(even.begin(), even.end(), 0ll);
    for (int i = 0; i < (odd.size() + 1) / 2; i++) {
        res += odd[i];
    }

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