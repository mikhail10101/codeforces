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

void solve() {
    /*
    If n is a power of 2,
        Spam n
    Else
        If k is odd,
    
    In general, if k is odd, we can simply spam n
    If k is even,
        Leave the last pair to contrast?

    Say we have
    1 0 0 1 0 1 1

    0 0 0 1 1 1 1
    1 0 0 0 0 0 0

    1 0 0 1 0
    1 0 0 0 1
    0 0 0 1 1

    1 0 1 1
    1 0 0 0
    0 0 1 1

    FIND MSB AND SECOND MSB
    WRONG
    */
    int n, k; cin >> n >> k;
    if (k % 2) {
        for (int i = 0; i < k; i++) cout << n << " ";
    } else {
        for (int i = 2; i < k; i++) cout << n << " ";

        int msb_pos = 31 - __builtin_clz(n);
        int first = pow(2, msb_pos);

        int remain = n - first;
        if (remain == 0) {
            cout << first << " " << remain;
        } else {
            int sec_msb_pos = 31 - __builtin_clz(remain);
            int sec = pow(2, sec_msb_pos + 1) - 1;
            int mix = (first + sec) ^ n;
            first += mix;
            cout << first << " " << sec;
        }
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