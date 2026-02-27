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
    int x; cin >> x;

    // ai >= floor(aj / 2)
    // max aj is ai * 2 + 1
    
    /*
    the last operation looks like
        x x floor(x/2)
    the one before that
        floor(floor(x/2)/2) x floor(x/2)
    and before that
        floor(floor(x/2)/2) floor(floor(floor(x/2)/2) / 2) floor(x/2) 
    
    Given x, how many floor(x/2) operations happen before you reach 0?

    31 -> 15 -> 7 -> 3 -> 1 -> 0
    17 -> 8 -> 4 -> 2 -> 1 -> 0
    15 -> 7 -> 3 -> 1 -> 0

    0 0 0
    1 0 0
    1 0 2
    1 3 2
    4 3 2
    
    0 0 0
    1 0 0
    1 2 0 
    2 2 0
    2 2 2

        */
    int lvls = (int)(ceil)(log2(x + 1));
    cout << lvls * 2 + 1;
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