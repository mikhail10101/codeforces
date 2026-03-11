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
#include <chrono>

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;
const string NO = "NO";
const string YES = "YES";

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

ll miniSolve(vector<int> a, vector<int> b) {
    int n = a.size();
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        // cout << "LINE " << endl;
        bool success = true;
        for (int j = 0; j < n; ++j) {
            // cout << a[(i + j) % n] << " " << b[j] << endl;
            if (a[(i + j) % n] >= b[j]) {
                success = false; 
                break;
            }
        }
        if (success) ++ res;
        // cout << "END  " << endl;
    }

    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    ll x = miniSolve(a, b);
    ll y = miniSolve(b, c);

    cout << x * y * n;
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