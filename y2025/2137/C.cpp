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

void solve() {
    long long a, b; cin >> a >> b;
    /*
    Perform a *= k and b /= k where b is divisible by k
    Greatest possible even value of a+b?

    This means a and b have the same parity after the procedure

    If a and b both start odd, 
        check endpoints

    If a and b both start even,
        check endpoints
        if endpoint is even, divide endpoint by 2

    If a start odd and b start even,
        check endpoints
        if endpoint is even, divide endpoint by 2

    If a start even and b start odd,
        Impossible
    */
    if (a % 2 == 0 && b % 2 == 1) {
        cout << -1; return;
    }

    if (a % 2 == 1 && b % 2 == 0) {
        int x = b / 2;
        if (x % 2 != 0) {
            cout << -1; return;
        }
    }

    long long res = a + b;
    if (res % 2 == 1) {
        res = a * 2 + b / 2;
    }

    long long x = b; if (b % 2 == 0) x /= 2;
    res = max(res, a * x + b / x);

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