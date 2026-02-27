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
    int r, c; cin >> r >> c;
    vector<vector<ll>> vals(r, vector<ll>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> vals[i][j];
            if (vals[i][j] == -1) vals[i][j] = INF;
        }
    }

    vector<vector<ll>> grid = vals;
    vector<vector<ll>> prefMin(r + 1, vector<ll>(c + 1, INF));
    vector<vector<ll>> suffMin(r + 1, vector<ll>(c + 1, INF));
    auto pref = [&] (int x, int y) -> ll {return prefMin[x + 1][y + 1];};
    auto suff = [&] (int x, int y) -> ll {return suffMin[x][y + 1];};

    auto process = [&] () -> void {
        for (int i = 0; i < r + 1; i++) {
            for (int j = 0; j < c + 1; j++) {
                prefMin[i][j] = INF;
                suffMin[i][j] = INF;
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                prefMin[i][j] = min({
                    prefMin[i - 1][j],
                    prefMin[i][j - 1],
                    grid[i - 1][j - 1]
                });
            }
        }
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 1; j <= c; j++) {
                suffMin[i][j] = min({
                    suffMin[i + 1][j],
                    suffMin[i][j - 1],
                    grid[i][j - 1]
                });
            }
        }
    };
   
    for (int k = 0; k < 4; k++) {
        process();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (k % 2 == 0) {
                    if (i > 0 && j > k) {
                        grid[i][j] = min(
                            pref(i - 1, j - 1) + vals[i][j],
                            INF
                        );
                    } else {
                        grid[i][j] = INF;
                    }
                } else {
                    if (i + 1 < r && j > k) {
                        grid[i][j] = min(
                            suff(i + 1, j - 1) + vals[i][j],
                            INF
                        );
                    } else {
                        grid[i][j] = INF;
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = min(ans, grid[i][j]);
        }
    }

    cout << (ans >= INF ? -1 : ans);
}

bool multiple = false;

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