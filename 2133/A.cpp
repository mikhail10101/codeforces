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
    x = number of teeth
    y = number of teeth of left gear
    z = speed of left gear

    z2 = (y / x) * z1
    z3 = (y / x) * z2 = (y / x) * (y / x) * z1

    If the gears were 2 4 5 7 5 7
    2 / 4 * 4 / 5 ...
    */
    int n; cin >> n;
    bool found = false;
    unordered_map<int, int> hmap;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        hmap[x]++;

        if (hmap[x] == 2) {
           found = true;
        }
    }

    if (found) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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