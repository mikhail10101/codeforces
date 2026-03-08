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
    Given a binary string, 
    we have a bunch of ones

    Count how many permutations exist such that

    Ones signify that some subsegment of the string exists s.t.
        the mex of the subsegment is i
    Zeroes signify that no subsegment can provide an mex of i

    0th idx should always be 1
    last idx should always be 1
    
    0s are an extremely limiting factor

    For instance, given a permutation of 5, how do we always prevent an MEX of 2?

    0 1 2 3 4
    That means between 0 and 1, 2 must exist to prevent 0 and 1 from being together

    To avoid an MEX of 3?
    Then, in between 0 and 2, 
        if 1 is between 0 and 2, 3 must as well
        if 1 is not between 0 and 2, 3 must still
    
    To avoid an MEX of x,
        Make sure that between 0 and x - 1, x exists

    Then, to ensure that MEX of x does exist,
        Make sure that between 0 and x - 1, x does not exist
    
    Then, the 0s and 1s boil down to a bunch of rules whether
        x should exist between 0 and x - 1

    For example, 111001
    Between 0 and 1, 2 should not exist
    Between 0 and 1 and 2, 3 should not exist
    Between 0 and 1 and 2 and 3, 4 should exist
    Between 0 and 1 and 2 and 3 and 4, 5 should exist

    Build from bottom up

    2 at the ends
    3 at the ends
    4 inside
    5 inside

    2 x 2 x 2 x 3 x 4 = 96

    What conditions make it impossible to form mex?
    */
    ll n, c; cin >> n >> c;
    string s; cin >> s;

    ll MOD = 1000000007;

    if (s[0] == '0' || s[n - 1] == '0') {
        cout << -1; return;
    }

    ll res = 2;
    if (c % 2 == 0) c /= 2;

    if (c == 1) {
        cout << -1;
        return;
    }

    vector<int> questions;
    for (ll i = 1; i < n - 1; ++i) {
        int div = 1;

        if (s[i] == '1' || (s[i] == '?' && i % 2 == 0)) {
            res *= 2;
            div = 2;
        } else if (s[i] == '0') {
            res *= (i % MOD);
            div = i;
        } else {
            if (i != 1)
            questions.push_back(i);
        }

        div = gcd(c, div);
        if (c % div == 0) {
            c /= div;
            if (c == 1) {
                cout << -1; return;
            }
        }    

        res %= MOD;
    }

    /*
    Remaining odd questions and remaining c
    Use: 2 or i

    If the remaining c has a factor that isn't 2, set all to 2
    Then, if the remaining c is a power of 2,
        set the k - 1 largest questions to be 2
    */

    // Power of 2
    if ((c & (c - 1)) == 0) {
        int k = __builtin_ctzll(c);
        for (int i = 0; i < min(k - 1, (int)questions.size()); ++i) {
            res = (res * 2) % MOD;
        }
        for (int i = 0; i < (ll)(questions.size()) - (k - 1); ++i) {
            res = (res * questions[i]) % MOD;
        }
    } else {
        for (int q: questions) {
            res = (res * 2) % MOD;
        }
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