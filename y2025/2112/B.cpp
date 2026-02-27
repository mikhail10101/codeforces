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
    // One position where bi and bi+1 hve a difference <= 1
    // Replace two adj elements with a number between the two elements
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) <= 1) {
            cout << 0; return;
        }
    }

    if (a[0] < a[1] + 1) {
        for (int i = 2; i < n; i++) {
            if (!(a[i - 1] < a[i] + 1)) {
                cout << 1; return;
            }
        }
    } else if (a[0] > a[1] + 1) {
        for (int i = 2; i < n; i++) {
            if (!(a[i - 1] > a[i] + 1)) {
                cout << 1; return;
            }
        }
    }

    cout << -1;
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