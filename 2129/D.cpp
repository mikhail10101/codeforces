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
    5 3 1 2 7 4 6

    0 0 0 0 1 0 0
    0 0 0 0 0 0 0

    0 0 1 0 1 0 0
    0 0 0 0 1 0 0

    1 0 1 0 1 0 0
    0 0 1 0 1 0 0

    1 1 1 0 1 0 0
    1 0 1 0 1 0 0

    1 1 1 0 1 0 1
    1 0 1 0 2 0 1

    1 1 1 1 1 0 1
    1 0 2 0 2 0 1

    1 1 1 1 1 1 1
    1 0 2 0 3 0 1

    sum(S) = n
    What makes an S invalid?
        
    */
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