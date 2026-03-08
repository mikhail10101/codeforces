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
    Optimal greedy solution

    First, we should try jumping as far as we can with each jump avoiding rollbacks
    Now that we've exhausted all options, find the optimal jump that can reach the
    furthest in a single rollback!
    */
    ll n, x; cin >> n >> x;
    ll d = 0;
    ll bestjump = 0;

    for (int i = 0; i < n; ++i) {
        vector<ll> tmp(3);
        for (int j = 0; j < 3; ++j) cin >> tmp[j];
        ll t = (tmp[1] - 1) * tmp[0];
        d += t;
        t += tmp[0] - tmp[2];
        bestjump = max(bestjump, t);
    }

    ll remain = max(x - d, 0ll);

    if (remain == 0) cout << 0;
    else {
        if (bestjump <= 0) cout << -1;
        else cout << (remain + bestjump - 1) / bestjump;
    }
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