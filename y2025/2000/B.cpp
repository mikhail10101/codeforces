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
    int n; cin >> n;
    vector<int> a(n);
    for (int i =0 ; i < n; i++) cin >> a[i];

    int l = a[0];
    int r = a[0];

    for (int i =1 ; i < n; i++) {
        if (a[i] == l - 1) {
            l--;
        } else if (a[i] == r + 1) {
            r++;
        } else {
            cout << "NO"; return;
        }
    }

    cout << "YES";
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