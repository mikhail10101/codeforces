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
    int n, q; cin >> n >> q;
    n = pow(2, n);
    vector<int> a(n);
    for (int i =0 ; i < n; i++) cin >> a[i];

    vector<int> xorarr(n + 1);
    for (int i = 0; i < n; i++) {
        xorarr[i + 1] = xorarr[i] ^ a[i];
    }

    // left inclusive, right exclusive
    auto xorc = [&] (int left, int right, int cow, int value) -> int {
        int normal = xorarr[right] ^ xorarr[left];
        if (left <= cow && cow < right) {
            normal ^= a[cow];
            normal ^= value;
        }
        return normal;
    };

    auto rec = [&] (auto self, int left, int right, int cow, int value) -> int {
        if (left == cow && right == left + 1) return 0;

        int halfsize = (right - left) / 2;
        int mid = (left + right) / 2;

        int leftxor = xorc(left, mid, cow, value);
        int rightxor = xorc(mid, right, cow, value);
        if (cow < mid) {
            if (leftxor >= rightxor) {
                return self(self, left, mid, cow, value);
            } else {
                return self(self, left, mid, cow, value) + halfsize;
            }
        } else {
            if (leftxor >= rightxor) {
                return self(self, mid, right, cow, value) + halfsize;
            } else {
                return self(self, mid, right, cow, value);
            }
        }
    };

    for (int q0 = 0; q0 < q; q0++) {
        int cow, skill; cin >> cow >> skill; cow--;
        cout << rec(rec, 0, n, cow, skill) << " ";
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