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

int int_log(int n, int base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    int result = 0;
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
    For all numbers that happen after the maximum,
    Even index should be set to the max
    Odd index are then automatically lower than the max (unless = max)

    If the max itself was on an odd number, this number should be decreased until it
    is less than both of its neighbors

    We can just set all even numbers and find the amount of subtracting needed to be done
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> prefMax(n);
    prefMax[0] = a[0];
    for (int i = 1; i < n; i++) prefMax[i] = max(a[i], prefMax[i - 1]);

    // printVec(a);
    // printVec(prefMax);

    int res = 0;
    for (int i = 0; i < n; i += 2) {
        int diffLeft = 0;
        int diffRight = 0;
        if (i > 0) diffLeft = max(0, a[i] - prefMax[i - 1] + 1);
        if (i < n - 1) diffRight = max(0, a[i] - prefMax[i + 1] + 1);
        // cout << i << " " << diffLeft << " " << diffRight << endl;
        res += max(diffLeft, diffRight);
    }

    cout << res;
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