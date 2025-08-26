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
    /*
    Either add one, or flip parity
    */
    int a, b, x, y; cin >> a >> b >> x >> y;

    if (a == b) {
        cout << 0; return;
    }

    if (a > b) {
        if (a % 2 == 1 && b == a - 1) {
            cout << y; return;
        }
        cout << -1; return;
    }

    int cost = 0;
    if (a % 2 == 1) {
        a++;
        cost += x;
    }

    int diff = b - a;
    cost += (diff / 2) * (min(x, y) + x);
    cost += (diff % 2) * min(x, y);

    cout << cost;
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