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
    int n; cin >> n;
    string s; cin >> s;
    /*
    0 1 2 
    Provided i and j,
    i, j, and k are all different

    Either form 0 1 2
    Or they for 0 0 0, 1 1 1, 2 2 2
    Adding all of these add up to modulo 3 always

    Provided an i and j,
    The last ball can be found with
    (3 - i - j) mod 3

    Let f(a, b) = (3-a-b)%3
    Provided
    a, b, c, d, e
    The next row is
    f(a, b) f(b, c) f(c, d) f(d, e)
    The balls are added again and again

    Note, however, that the sign changes for each
    Say the bottom row starts with i...
    On the 1st row, i contributes -i
    On the 2nd row, i contributes +i
    On the 3rd row, i contributes -i once again
    This happens as i is carried through until the top
    
    However, if the second element was i...
    On the first row, i contributes -i * 2
    On the second row, i contributes i * 3
    On the third row, i contributes -i * 4
    It keeps going up until the triangle starts squishing

    +21
    -15 -6
    +10 +5 +1
    -6 -4 -1 x
    +3 +3 +1 x x
    -1 -2 -1 x x x
    x +1 +1 x x x x
    x x -1 x x x x x

    Provided that the max n is 10^6, we need to find
    a way to query this sum in O(1) after a preprocessing
    of at most O(n)?

    Use the combinatorial identity
    Sum of kCr iterating k from r to n = (n + 1)C(r + 1)
    We also know that a row in pascal's is equal to a power of 2

    We can now solve for each ball's index in O(1) by combining
    above with the formula for solving consecutive powers of 2
    
    Problem: the top end?
    */
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