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

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
void printVec2(vector<vector<T>> vec) {
    for (vector<T> v: vec) {
        printVec(v);
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // FIRST DP (i + 1, j + 1)
    vector<vector<ll>> dpT(n + 1, vector<ll>(m + 1));
    for (int i = 0; i < n; ++i) {
        dpT[i + 1][1] = grid[i][0] + dpT[i][1];
    }
    for (int j = 0; j < m; ++j) {
        dpT[1][j + 1] = grid[0][j] + dpT[1][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dpT[i + 1][j + 1] = max(dpT[i][j + 1], dpT[i + 1][j]) + grid[i][j];
        }
    }

    // SECOND DP
    vector<vector<ll>> dpS(n + 1, vector<ll>(m + 1));
    for (int i = n - 1; i >= 0; --i) {
        dpS[i][m - 1] = grid[i][m - 1] + dpS[i + 1][m - 1];
    }
    for (int j = m - 1; j >= 0; --j) {
        dpS[n - 1][j] = grid[n - 1][j] + dpS[n - 1][j + 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            dpS[i][j] = max(dpS[i][j + 1], dpS[i + 1][j]) + grid[i][j];
        }
    }

    vector<pair<int, int>> path;
    pair<int, int> curr = {n - 1, m - 1};
    while (curr.first != 0 && curr.second != 0) {
        path.push_back(curr);
        auto [r, c] = curr;
        if (dpT[r][c + 1] > dpT[r + 1][c]) {
            curr.first = curr.first - 1;
        } else {
            curr.second = curr.second - 1;
        }
    }

    while (curr.first != 0) {
        path.push_back(curr);
        curr.first = curr.first - 1;
    }

    while (curr.second != 0) {
        path.push_back(curr);
        curr.second = curr.second - 1;
    }

    path.push_back({0, 0});

    vector<vector<ll>> boundaries(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            boundaries[i][j] = dpT[i + 1][j + 1] + dpS[i][j] - grid[i][j];
        }
    }

    vector<vector<ll>> suffRow = boundaries;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            suffRow[i][j] = max(suffRow[i + 1][j], boundaries[i][j]);
        }
    }

    vector<vector<ll>> suffCol = boundaries;
    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j >= 0; --j) {
            suffCol[i][j] = max(suffCol[i][j + 1], boundaries[i][j]);
        }
    }

    ll ans = dpT[n][m];
    for (int i = 0; i < path.size(); ++i) {
        auto [r, c] = path[i];
        ll res = -INF;

        if (r - 1 >= 0 && c + 1 < m)
            res = max(res, suffCol[r - 1][c + 1]);
        if (c - 1 >= 0 && r + 1 < n)
            res = max(res, suffRow[r + 1][c - 1]);
        res = max(res, dpT[n][m] - 2 * grid[r][c]);

        ans = min(ans, res);
    }

    cout << ans;
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