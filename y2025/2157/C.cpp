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
    Take the common interval among all type 2 intervals
    This common interval should contain the numbers 0 to k - 1

    Take the complement of the union of all type 2 intervals
    k exists within this area

    Take the common interval of all type 1 intervals
    k should exist in this area

    Take the union of all type 1 intervals
    k to n should exist in this area
    
    STEPS
    1. Place k
    2. Place k + 1 to n
    3. Place 0 to k - 1
    */
    int n, k, q; cin >> n >> k >> q;
    vector<int> union1(n + 1), union2(n + 1), a(n), b(n);

    for (int i = 0; i < q; i++) {
        int c, l, r; cin >> c >> l >> r;
        l--; r--;
        if (c == 1) {
            union1[l] = 1;
            union1[r + 1] = -1;
        } else {
            union2[l] = 1;
            union2[r + 1] = -1;
        }
    }

    a[0] = union1[0];
    b[0] = union2[0];
    for (int i = 1; i < n; i++) {
        a[i] = union1[i] + a[i - 1];
        b[i] = union2[i] + b[i - 1];
    }

    int maxi1 = *max_element(a.begin(), a.end());
    int maxi2 = *max_element(b.begin(), b.end());

    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] == maxi1 && b[i] == 0) {
            res[i] = k;
            break;
        }
    }

    if (maxi2 > 0) {
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (res[i] == k) continue;
            if (b[i] == maxi2) {
                if (ptr == k) ptr++;
                res[i] = ptr++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (b[i] > 0 && res[i] == -1) res[i] = k + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == -1) res[i] = k;
    }

    printVec(res);
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