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
    We are given an array filled with 1s and -1s
    One element is replaced with an arbitrary integer

    Find all possible sums of subarrays

    !! What does most of the array being filled with 1s and -1s do?
    Biggest thing is that this bounds the result of the array
    After every index, the number can only either increase by 1 or decrease by 1
    That means that if we find the max subarray sum and min subarray sum,
    we can simply define all possible subarrays as the range of numbers from left to right

    However, we need to consider the arbitrary integer
    We can divide the kinds of subarrays into three

    1) To the left of x
    2) To the right of x
    The above types would be counted the same way
    3) Including x

    This means combining all possible arrays that end at x
    With all possible subarrays that start after x
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int idx = 0;
    while (idx < n && (a[idx] == 1 || a[idx] == -1)) idx++;

    auto calc = [&] (int l, int r) -> pair<int, int> {
        // Run Kadane's algorithm twice
        
    };
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