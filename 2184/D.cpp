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

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

/*
Provided n and k, find the amount of numbers < k such that moves <= k
Find where moves > k

We can model move as a sum of leading zero + unit bits

Given k, we can solve for how many numbers are caused by such a combination as stated above
leading zero C unit bits

when leading zero is > k, that means unit bits of 0 to amount leading zero are allowed
this contributes 2 ^ leading zero

when the leading zero is <= k, we manually add all such combinations
this will be O(n^2)

*/
void solve() {
    int n, k; cin >> n >> k;
    int bits = 31 - __builtin_clz(n);

    int complement = 0;
    for (int bitcount = 0; bitcount < bits; bitcount++) {
        if (bitcount + 1 > k) {
            complement += pow(2, bitcount);
        } else {
            for (int excess = (k + 1) - (bitcount + 1); excess <= bitcount; excess++) {
                complement += nCr(bitcount, excess);
            }
        }
    }

    if (bits + 1 > k) complement++;

    cout << complement;
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