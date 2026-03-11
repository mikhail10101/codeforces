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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    bool found2025 = false;
    bool found2026 = false;
    for (int i = 3; i < n; ++i) {
        if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2') {
            if (s[i] == '5') found2025 = true;
            if (s[i] == '6') found2026 = true;
        }
    }

    if (found2026) {
        cout << 0; return;
    }

    if (found2025) {
        cout << 1; return;
    }

    cout << 0;
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