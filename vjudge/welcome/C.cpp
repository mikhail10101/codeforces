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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    /*
    If we choose the middle between the min and the max
    we effectively cut the range of all numbers in half

    0 2 4 10 20
    10 8 6 0 10
    5 3 1 5 5
    3 1 1 3 3
    2 0 0 2 2
            1
            0 

    Can we keep repeating this until we can't?
    1 2 3 4 5
    2 1 0 1 2
    1 0 1 0 1

    If all numbers are the same parity, its alwasy possible
    1 3 1 3 1
    2 2 2 2 2
    0 0 0 0 0
    */
    if (n == 1) {
        cout << 1 << " " << a[0]; return;
    }

    int parity = a[0] % 2;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != parity) {
            cout << -1; return;
        }
    }

    ll mx = *max_element(a.begin(), a.end());
    vector<int> halves;
    while (mx > 0) {
        halves.push_back(mx);
        mx /= 2;
    } halves.push_back(0);

    cout << halves.size() - 1 << endl;
    for (int i = 1; i < halves.size(); i++) {
        cout << halves[i - 1] - halves[i] << endl;
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