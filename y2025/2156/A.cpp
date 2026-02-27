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
    At each round, Hao can eat just as much as Alex
    However, when there are only 2 slices left, Alex eats all of them
    The remaining partition should also be equal or than Hao + Alex for the round
    
    Lets let Hao = Alex
    m = 2(Hao) + m3, m3 >= Hao
    
    In the case where we have 4:
        Hao eats 1
        Alex eats 1
        Remain 2
        Alex eats the remaining 2

    In the case of 6:
        Hao eats 2
        Alex eats 2
        Remain 2
        Alex eats the remaining 2

    For even numbers, it seems we can approach it as having Alex eat 2 more
    than Hao

    For odd numebrs, however,
    Alex only eats one more cookie than Hao
    */
    int n; cin >> n;
    if (n % 2) cout << (n - 1) / 2;
    else cout << n / 2 - 1;
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