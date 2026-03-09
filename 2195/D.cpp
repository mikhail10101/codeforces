#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;
const string NO = "NO";
const string YES = "YES";

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    /*
    Given, f(1), f(2), f(3)..., find a1...an

a   1 2 3 4 5 6

1   0 1 2 3 4 5     s
2   1 0 1 2 3 4     s
3   2 1 0 1 2 3     s
4   3 2 1 0 1 2     s
5   4 3 2 1 0 1     s    
6   5 4 3 2 1 0     s

    1 1 1 1 1 1

    f(1) + f(n) is the sum of all a

    4 3 2 1 0 1
    1 0 1 2 3 4
    ___________
    5 3 3 3 3 5

    2 1 0 1 2 3
    3 2 1 0 1 2
    ___________
    5 3 1 1 3 5

    Once we know the sum of pairs,
    how do we solve for individual numbers?

    0 1 2 3 4 5
    1 0 1 2 3 4
    ___________
   -1 1 1 1 1 1

    1 0 1 2 3 4
    2 1 0 1 2 3
    ___________
  -1 -1 1 1 1 1

    We can then solve for
    1 -1 1 1 1 1

    So afterwards, subtracting adjacent pairs helps us solve for individual numbers?
    Oh, we can skip to this method instantly
    */
    int n; cin >> n;
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];

    vector<ll> res;
    int S = (f[0] + f[n - 1]) / (n - 1);
    ll total = 0;

    for (int i = 1; i < n; ++i) {
        ll diff = f[i - 1] - f[i];
        ll isolated = diff + total * 2;
        ll twice = S - isolated;
        res.push_back(twice / 2);
        total += twice / 2;
    }

    res.push_back(S - accumulate(res.begin(), res.end(), 0ll));
    printVec(res);
}

bool multiple = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}