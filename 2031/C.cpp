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
    Provided with n slots
    Label slots such that all pairs of slots of the same label
    have a perfect square difference

    Question: Is it sufficient to use 2 of each pair?
    Introducing 3 of the same label would require pythagorean squares like
    9 16 25 and it would be easier to avoid them

    Lets try avoiding them for now

    Squares: 1, 4, 9, 16, 25, 36, 49...
    I was under the assumption that squares couldn't be reused but they most definitely
    can be reused

    Why can't we just do:
    1 2 3 4 1 2 3 4?

    For even numbers, 
    In fact, 1 1 2 2 3 3 4 4... because 1 is a perfect square

    It's a bit trickier for odd numbers because one triple will have to be introduced
    Can we solve a 9-16-25 problem properly?

    x (8) x (15) x

    Fill first 8
    Remaining (7) x
    Pair
    _ _ _ _ y _ _ x y

    27 IS SOLVABLE
    */
    int n; cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << i + 1 << " " << i + 1 << " ";
        } return;
    }
    
    if (n < 27) {
        cout << -1;
        return;
    }

    cout << 9 << " ";
    for (int i = 1; i <= 8; i++) cout << i << " ";
    cout << 9 << " ";
    for (int i = 1; i <= 8; i++) cout << i << " ";
    cout << 10 << " " << 10 << " " << 11 << " " << 11 << " ";
    cout << 12 << " ";
    cout << 13 << " " << 13 << " ";
    cout << 9 << " ";
    cout << 12 << " ";

    int remain = n - 27;
    for (int i = 0; i < remain / 2; i++) {
        cout << 15 + i << " " << 15 + i << " ";
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