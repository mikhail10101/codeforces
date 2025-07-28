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

bool verify(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] % arr[i] != 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    reverse(s.begin(), s.end());
    if ((!verify(p)) || (!verify(s))) {
        cout << "NO";
        return;
    }

    if (p[n - 1] != s[n - 1]) {
        cout << "NO";
        return;
    }

    int fgcd = p[n - 1];

    for (int i = 0; i < n - 1; i++) {
        if (gcd(p[i], s[n - i - 2]) != fgcd) {
            cout << "NO";
            return;
        }
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