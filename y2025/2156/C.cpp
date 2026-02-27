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
    K erases, split

    For split, we'd only split to try extracting a gcd
    If that number was g, we'd do a split of
    g <= ? <= 2g
    At least 2g, at most anything
    But we'd have to express a number as 3g + ?
    Given that question mark is g + some variable x,
    A number would need to be at least 4g + x for us to extract g from it

    Actually, this knowledge allows us to see the max g we can take from
    any number

    For any a, a/4 is the max g that can extract

    Now for every number a, we can either:
        - Erase it
        - Use a
        - Take any g from [1, a/4]

    How do we solve for the max gcd of all numbers?

    Solving the lowerbound for the gcd is trivial:
        - Take out the lowest k numbers
        - Calculate a/4

    Moving upwards, however, forces us to consider other factors
    A possible solution is taking all divisors, sorting them from
    largest to smallest, and then testing the viability

    Given that ai < n, # of divisors scales O(n)

    Checking each divisor is an O(n) task right now.
    How can we fix this?

    For each divisor, run a binary search for all factors that we can
    use split to achieve it instead.

    Afterwards, begin checking all the numbers that we can't use split on.
    If the divisor isn't divisible, erase it. If we're out of erases, its
    impossible.

    We can do this in O(1) by checking for g, 2g, and 3g as these are the only
    numbers below 4g that have a common factor with g.
    */
    int n, k; cin >> n >> k;
    vector<int> freq(n + 1), pref(n + 2);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ++freq[x];
    }
    for (int i = 1; i <= n + 1; i++) {
        pref[i] = pref[i - 1] + freq[i - 1];
    }

    int res = 1;
    for (int i = 2; i < n + 1; i++) {
        int ge4 = i * 4 < n + 1 ? pref[n + 1] - pref[i * 4] : 0;
        int g3 = i * 3 < n + 1 ? freq[i * 3] : 0;
        int g2 = i * 2 < n + 1 ? freq[i * 2] : 0;
        int g1 = i * 1 < n + 1 ? freq[i] : 0;
        if (g1 + g2 + g3 + ge4 + k >= n) res = i;
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