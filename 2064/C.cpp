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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // If ai is negative, gain ai coins and delete the suffix beginning with ai
    // If ai is positive, gain ai coins and delete the prefix ending with ai

    /*
    Negative numbers at the end should be greedily added
    Positive numbers at the start should be greedily added

    When the array starts with a negative number and ends with a positive number
        -10 -3 -17 1 19 20
        We choose either the first positive number from left to right
        Or we choose the first negative number from right to left
    */

    vector<ll> pref(n), suff(n);
    pref[0] = a[0] > 0 ? a[0] : 0;
    suff[n - 1] = a[n - 1] < 0 ? -a[n - 1] : 0;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        if (a[i] > 0) {
            pref[i] += a[i];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1];
        if (a[i] < 0) {
            suff[i] -= a[i];
        }
    }
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, pref[i] + suff[i]);
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