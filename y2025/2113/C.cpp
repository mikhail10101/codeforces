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

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;

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
    int n, m, k; cin >> n >> m >> k; k--;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> prefs(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefs[i+1][j+1] = prefs[i+1][j] + prefs[i][j+1] - prefs[i][j] + (grid[i][j] == 'g');
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total += (grid[i][j] == 'g');
        }
    }

    int mn = total;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int a = max(0, i - k);
                int b = min(n, i + k + 1);
                int c = max(0, j - k);
                int d = min(m, j + k + 1);
                // cout << "DEBUG " << i << " " << j << " " << a << " " << b << " " << c << " " << d << endl;
                int gold = prefs[b][d] - prefs[a][d] - prefs[b][c] + prefs[a][c];
                // cout << "GOLD " << gold << endl;
                mn = min(mn, gold);
            }
        }
    }

    cout << total - mn;
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