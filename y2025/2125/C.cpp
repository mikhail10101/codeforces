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
    How many digits from l to r inclusive have a prime factorization compromised only of primes with 2+ digits

    ALL MULTIPLES OF 2, 3, 5, and 7 are gone
*/

    long long l, r; cin >> l >> r;

    auto countMultiples = [&](long long k) -> long long {
        long long first = l + (k - (l % k)) % k;
        long long last = r - r % k;

        if (l <= first && first <= r && l <= last && last <= r) {
            return (last - first) / k + 1;
        }

        if ((l <= first && first <= r) || (l <= last && last <= r)) {
            return 1;
        }

        return 0;
    };

    cout << r - l + 1 - countMultiples(2) - countMultiples(3) - countMultiples(5) - countMultiples(7)
    + countMultiples(6) + countMultiples(10) + countMultiples(14) + countMultiples(15) + countMultiples(21) + countMultiples(35) 
    - countMultiples(30) - countMultiples(42) - countMultiples(70) - countMultiples(105)
    + countMultiples(210);
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