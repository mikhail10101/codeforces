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
    Grid with
    - at least one black cell
    - all cells are orthogonally connected
    - no consecutive three balck cells aligned vertically or horizontally

    We just need to determine yes/no
    */
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int total = 0;
    vector<int> leftd(n * 2);
    vector<int> rightd(n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                total++;
                leftd[(i - j) + (n - 1)]++;
                rightd[i + j]++; 
            }
        }
    }

    // Make sure either only 2 leftd have elements and they're beside
    int lcnt = 0, rcnt = 0, l = -1, r = -1;
    for (int i = 0; i < n * 2; i++) {
        if (leftd[i] > 0) { lcnt++; l = i; }
        if (rightd[i] > 0) { rcnt++; r = i; }
    }

    if (lcnt == 0) {
        cout << YES; return;
    }
    if (lcnt == 1 || rcnt == 1) {
        cout << YES; return;
    }
    if (lcnt == 2 && leftd[l - 1] > 0) {
        cout << YES; return;
    }     
    if (rcnt == 2 && rightd[r - 1] > 0) {
        cout << YES; return;
    }
    if (lcnt == 3 && rcnt == 3 && total == 4) {
        // Check for 2x2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#') {
                    if (i + 1 < n && j + 1 < n) {
                        if (
                            grid[i][j + 1] == '#' &&
                            grid[i + 1][j + 1] == '#' &&
                            grid[i + 1][j] == '#'
                        ) {
                            cout << YES; return;
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << NO; return;
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