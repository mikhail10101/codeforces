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
    mex = max - min

    a a a

    if a 0 exists, mex = max which is impossible
    if no 0 exists, mex = 0 and max has to equal min
    */
   
    int n; cin >> n;
    vector<int> a(n);

    int first = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        first = max(first, a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = first;
        }
    }

    if (a[0] == 0) {
        cout << "NO";
        return;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0])
            count++;
    }

    if (count == n) {
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