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
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sum of elements of b is even
    // If a has an odd sum, we cannot achieve 0

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    if (total % 2 == 1) { cout << -1; return; }

    long long running = 0;
    long long behind = 0;
    for (int i = 0; i < n; i++) {
        running += a[i];
        if (running == total / 2) {
            cout << 1 << endl;
            printVec(a);
            return;
        }

        if (running > total / 2) {
            if (i == 0 || i == n - 1) {
                cout << -1; return;
            }

            long long diff = 2 * running - total;
            long long change = diff / 2;

            if (behind < change) {
                cout << -1; 
                return;
            } else {
                cout << 2 << endl;
                vector<long long> b(n);
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        b[j] = diff / 2;
                    } else {
                        b[j] = min(a[j], change);
                        change -= b[j];
                    }
                    a[j] -= b[j];
                }
                printVec(b);
                printVec(a);
                return;
            }
        }

        behind += a[i];
    }

    cout << -1; return;
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