#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
void print(T a) { cout << a << endl; }
template <typename T>
void print(T a, T b) { cout << a << " " << b << endl; }
template <typename T>
void print(T a, T b, T c) { cout << a << " " << b << " " << c << endl; }
template <typename T>
void print(T a, T b, T c, T d) { cout << a << " " << b << " " << c << " " << d << endl; }
template <typename T>
void print(T a, T b, T c, T d, T e) { cout << a << " " << b << " " << c << " " << d << " " << e << endl; }

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> casinos(n);
    for (int i = 0; i < n; i++) {
        int l, r, real; cin >> l >> r >> real;
        vector<int> entry = {l, r, real};
        casinos[i] = entry;
    }

    sort(casinos.begin(), casinos.end());

    for (int i = 0; i < n; i++) {
        int l = casinos[i][0];
        int r = casinos[i][1];
        int real = casinos[i][2];
        if (l <= k && k <= r && real > k) {
            k = real;
        }
    }

    cout << k;
}

bool multiple = true;

int main() {
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}