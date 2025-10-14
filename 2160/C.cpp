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
    f(x) is the bits of x reversed excluding leading 0s
    determine whether an x exists such that x XOR f(x) = n for a given n

    11010   101110
    01011   011101

    Since the original is of the form 1..., we have two cases
    1...1 -> 0...0
    1...0 -> 1...1

    The behavior of bits inside ... must be symmetric
    Additionally, for an odd amount of bits, the middle bit can only be 0
    */
    int n; cin >> n;
    if (n == 0) {
        cout << "YES"; return;
    }

    vector<int> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    // First 1 and last 1
    int l = 0;
    int r = bin.size() - 1;
    while (bin[l] == 0) l++;

    if ((r - l + 1) % 2)  {
        if (bin[(r + l) / 2]) {
            cout << "NO"; return;
        }
    }

    for (int i = l; i <= (l + r) / 2; i++) {
        if (bin[i] != bin[r - (i - l)]) {
            cout << "NO"; return;
        }
    }

    cout << "YES";
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