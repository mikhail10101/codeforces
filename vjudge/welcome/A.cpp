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
    /*
    How many subarrays of array b are equal to a1 to am?
    */
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    /*
    Two types of subarrays:
    1. Strictly increasing
    2. Looping

    For strictly increasing subarrays,
    we count how many 1 to n contain the subarray

    For looping, only 1 subarray will contain it
    if it exists
    */
    bool inc = true;
    for (int i = 1; i < m; i++) {
        if (a[i] != a[i - 1] + 1) {
            inc = false; break;
        }
    }

    if (inc) {
        int last = a.back();
        cout << n - last + 1;
    } else {
        cout << 1;
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