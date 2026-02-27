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
    n = x + x * 10^y where y > 0
    n = x(1 + 10^y)

    Find all possible x

    Above formula shows that 10^y + 1 has to be a factor of x
    */
    long long n; cin >> n;
    vector<long long> res;
    for (int y = 17; y > 0; y--) {
        long long divisor = (long long) pow(10, y) + 1;
        if (n % divisor == 0) {
            res.push_back(n / divisor);
        }
    }

    cout << res.size() << endl;
    for (long long ans: res) {
        cout << ans << " ";
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