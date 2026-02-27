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
    The goal is to express the provided number as a sum of 3^x
    We want to minimize the amount of addends and minimize the sum of 3^(x+1) + x(3^(x-1)) for all addends

    We can shorten the above equation to (3 ^ (x - 1))(x + 9)

    If our goal is to minimize the amount of addends, then we push first for using the largest possible addends
    */
    long long res = 0;

    int n; cin >> n;
    int pos = 0;
    while (n > 0) {
        long long digit = n % 3;
        long long cost = digit * (pow(3, pos - 1)) * (pos + 9);
        res += cost;
        n /= 3;
        pos++;
    }

    cout << res;
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