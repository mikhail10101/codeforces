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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int curr = h[k - 1];

    sort(h.begin(), h.end());

    vector<int> uniques;
    for (int i = 0; i < n; i++) {
        if (h[i] <= curr) {
            continue;
        }
        if (uniques.empty() || h[i] != uniques[uniques.size() - 1]) {
            uniques.push_back(h[i]);
        }
    }

    int water = 1;
    for (int t: uniques) {
        if (t - curr > curr - water + 1) {
            cout << "NO";
            return;
        }
        water += t - curr;
        curr = t;
    }

    cout << "YES";
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