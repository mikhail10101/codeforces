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
    ll n; cin >> n;
    ll upper = llround(cbrt(n) * cbrt(6));
    for (ll b = upper; b >= 1; b--) {
        ll bside = b * (b + 1) * (2*b + 1) / 6ll;
        if (bside > n) continue;
        if (n % bside == 0) {
            ll aside = n / bside;
            ll root = llround(sqrt(aside));
            if (root * root == aside) {
                cout << "YES" << endl << root << " " << b; return;
            }
        }
    }
    cout << "NO";
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