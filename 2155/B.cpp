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

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n, k; cin >> n >> k;

    if (k == n * n - 1) {
        cout << "NO"; return;
    }
    // SINGLE PATH TO ESCAPE THE GRID
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            grid[i][j] = 'R';
    }

    for (int i = 0; i < n; i++) {
        if ((n - 1) % 2 == 0) {
            grid[i][n-1] = 'D';
            grid[n-1][n-1] = 'U';
        } else {
            grid[i][n-1] = 'U';
            grid[0][n-1] = 'D';
        }
    }

    int energy = k;
    int col = 0;
    while (energy > 0) {
        if (col % 2 == 0) {
            int row = 0;
            while (row < n && energy > 0) {
                grid[row][col] = row == 0 ? 'L' : 'U';
                row++;
                energy--;
            }
        } else {
            int row = n - 1;
            while (row >= 0 && energy > 0) {
                grid[row][col] = row == n - 1 ? 'L' : 'D';
                row--;
                energy--;
            }
        }
        col++;
    }
    
    cout << "YES" << endl;
    for (auto row: grid) {
        for (auto c: row) {
            cout << c;
        } cout << endl;
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