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
    int ones = 0;
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            ones += grid[i][j];
        }
    }

    // To maximize the product, we want to try cutting the 1's in half
    // Is this always possible?
    int r = 0;
    int b = 0;
    while (b < ones / 2) {
        int rowsum = accumulate(grid[r].begin(), grid[r].end(), 0);
        b += rowsum;
        ++r;
    }

    // At this point, we have enough ones
    int excess = b - ones / 2;

    // Find the index of the excess #1
    int idx = 0;
    int cnt = 0;
    while (idx < m && cnt < excess) {
        cnt += grid[max(0, r - 1)][idx];
        ++idx;
    }

    // Rule
    // Go down to above r, move right until idx, go down 1, and move to the edge
    int down1 = max(0, r - 1);
    int right1 = idx;
    int down2 = 1;
    int right2 = m - right1;
    int down3 = n - down1 - down2;

    // cout << n << " " << down1 << " " << down2 << " " << down3 << endl;

    int half = ones / 2;
    cout << (ll)(half) * (ones - half) << endl;
    for (int i = 0; i < down1; i++) cout << "D";
    for (int i = 0; i < right1; i++) cout << "R";
    for (int i = 0; i < down2; i++) cout << "D";
    for (int i = 0; i < right2; i++) cout << "R";
    for (int i = 0; i < down3; i++) cout << "D";
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