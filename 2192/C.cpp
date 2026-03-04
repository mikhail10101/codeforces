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
    ll n, h, k; cin >> n >> h >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll full = h / total;
    ll lastHealth = h % total;

    if (lastHealth == 0) {
        cout << n * full + (full - 1) * k;
        return;
    }

    int idx = -1;
    ll curr = 0;
    while (curr < lastHealth) {
        curr += a[++idx];
    }

    // cout << "DEBUG " << lastHealth << " " << curr << " " << idx << endl;

    // idx is the last bullet shot
    // bound is where we start taking the max of the right side
    int bound = idx;
    if (curr == lastHealth) bound = idx + 1;

    // PERFORM SWAP HERE
    vector<ll> prefMin(n + 1, INF);
    vector<ll> suffMax(n + 1, 0);
    for (int i = 0; i < n; ++i) prefMin[i + 1] = min(prefMin[i], a[i]);
    for (int i = n - 1; i >= 0; --i) suffMax[i] = max(suffMax[i + 1], a[i]);

    curr = 0;
    for (int i = 0; i < bound; ++i) {
        curr += a[i];
        ll maxAfter = suffMax[i + 1];
        ll minBefore = prefMin[i + 1];
        if (maxAfter > minBefore) {
            ll best = curr - minBefore + maxAfter;
            if (best >= lastHealth) {
                auto minIdx = find(a.begin(), a.begin() + i + 1, minBefore);
                auto maxIdx = find(a.begin() + i + 1, a.end(), maxAfter);
                iter_swap(minIdx, maxIdx);
                break;
            }
        }
    }

    // cout << "DEBUG " << bound << endl;
    // printVec(a);

    idx = 0;
    curr = 0;
    while (curr < lastHealth) {
        curr += a[idx];
        ++idx;
    }

    cout << (n + k) * full + idx;
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