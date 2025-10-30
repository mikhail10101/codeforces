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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
T manual_log(T n, T base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    T result = 0;
    while (n >= base) {
        n /= base;
        result++;
    }
    return result;
}

int find_conseq(int n) {
    int root = (int)sqrt(n * 2);
    while (root * (root + 1) > n * 2) root--;
    return root;
}

void solve() {
    /*
    Items are at most worth as much as the loyalty factor
    Loyalty level in the store is defined as S/X lower bound
    This means that each item cannot increase the loyalty level
    by a score of more than one
    If you buy an item and your loyalty level increases, you earn p
    points
    */
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll flevel = total / x;
    sort(a.begin(), a.end(), greater<ll>());

    ll ans = accumulate(a.begin(), a.begin() + flevel, 0ll);

    vector<ll> order;
    int i = 0;
    int j = n - 1;
    ll curr = 0;
    while (i <= j) {
        ll threshold = (curr / x + 1) * x;
        while (j >= i && curr + a[i] < threshold) {
            order.push_back(a[j]);
            curr += a[j];
            j--;
        }
        if (i < n && i <= j) {
            order.push_back(a[i]);
            curr += a[i];
            i++;
        }
    }
    cout << ans << endl;
    printVec(order);
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