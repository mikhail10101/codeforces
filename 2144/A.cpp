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
    /*
    Split the array into pref, mid, and suff where the summations mod 3
    are either all unique or all the same.

    Take a prefix modulo
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = (pref[i] + a[i]) % 3;
    }

    for (int r = 1; r < n; r++) {
        for (int l = 1; l < r; l++) {
            // Check for 0 to j, j+1 to i, i+1 to n
            if (
            (
                pref[l] != (pref[r] - pref[l] + 3) % 3 && 
                (pref[r] - pref[l] + 3) % 3 != (pref[n] - pref[r] + 3) % 3 &&
                (pref[n] - pref[r] + 3) % 3 != pref[l]
            ) || (
                pref[l] == (pref[r] - pref[l] + 3) % 3 &&
                pref[l] == (pref[n] - pref[r] + 3) % 3
            )
            ) {
                cout << l << " " << r;
                return;
            }
        }
    }

    cout << "0 0";
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