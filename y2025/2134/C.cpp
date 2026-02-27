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
    For an array to be good, sum of even indices >= sum of odd indices
    1 2 3 4 5 6 7

    When evaluating whether even indices 2 and 4 are good, we take indices 1 to 5

    Brute force check:
        1. Take a prefix sum
        2. Check all odd intervals (n^2)

    However, say 1 to 3 is good. If 3 to 5 is also good, can we prove that 1 to 5 is good?
    b >= a + c, d >= c + e
    b + d >= a + 2c + e
    YES

    Check 1 to 3, 3 to 5, 5 to 7, etc.
    If all of these are good, then the whole array is also good.

    We always want to reduce odd numbers, now the question is: how do we choose which odd number to reduce?

    We can perform this greedily.
    For all even numbers except the last, try reducing as much from the right side number before
    reducing the left.

    For the last, adjust accordingly.
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long res = 0;
    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            int odds = a[i - 1] + a[i + 1];
            int even = a[i];

            if (even < odds) {
                int diff = odds - even;
                res += diff;
                a[i + 1] = max(0, a[i + 1] - diff);
            }
        } else {
            int odds = a[i - 1];
            int even = a[i];

            if (even < odds) {
                res += odds - even;
            }
        }
    }

    cout << res << endl;
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