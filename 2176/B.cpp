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
    Cyclic left shifts

    Whats the answer when only one 1 exists?
    either 1 + 2 + 4 + 8... + (n - 2^k)

    We can track a string as an alternating series of
    1s and 0s

    To be optimal, the nearest 1 to the right of 0 should
    be the 1 responsible for conversion

    If a number starts and ends with 0, group the 0s at the start
    If a number starts and ends with 1, group the 1s at the end
    If a number starts with 1 and ends with 0, shift all the 0s to the start

    The field that takes the longest to fill out is the bottleneck
    Calculate how many coins it will take to fill this field
    */
    int n; cin >> n;
    string s; cin >> s;

    s += '2';
    deque<int> a;
    int lastHead = 0;
    for (int i = 1; i < n + 1; i++) {
        if (s[i] != s[lastHead]) {
            a.push_back(i - lastHead);
            lastHead = i;
        }
    }

    if (a.size() == 1) {
        cout << 0; return;
    }

    if (s[0] == '0' && s[n - 1] == '0') {
        a[0] += a.back();
        a.pop_back();
    } else if (s[0] == '1' && s[n - 1] == '1') {
        a.back() += a[0];
        a.pop_front();
    } else if (s[0] == '1' && s[n - 1] == '0') {
        a.push_back(a.front());
        a.pop_front();
    }

    int res = 0;
    for (int i = 0; i < a.size(); i += 2) {
        int zero = a[i];
        int ones = a[i + 1];
        res = max(res, zero);
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