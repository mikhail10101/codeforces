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

void displayBoard(vector<vector<char>> board) {
    for (auto row: board) {
        for (char c: row) {
            cout << c;
        } cout << endl;
    } cout << endl;
}

vector<vector<char>> showEven(int n, int m, int a, int b, int c) {
    vector<vector<char>> board(n, vector<char>(m, 'v'));
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            char above = 'x', left = 'x', above2 = 'x', left2 = 'x';
            if (i > 0) above = board[i-1][j];
            if (j > 0) left = board[i][j-1];
            if (i > 0 && j + 1 < m) above2 = board[i-1][j+1];
            if (j > 0 && i + 1 < n) left2 = board[i+1][j-1];

            char v = 'a';
            while (v == above || v == left || v == above2 || v == left2) {
                v++;
            }
            char u = v + 1;
            while (u == above || u == left || u == above2 || u == left2) {
                u++;
            }

            if (c > 0) {
                board[i][j] = v;
                board[i][j+1] = v;
                board[i+1][j] = v;
                board[i+1][j+1] = v;
                c--;
            } else if (b > 1) {
                board[i][j] = u;
                board[i][j+1] = v;
                board[i+1][j] = u;
                board[i+1][j+1] = v;
                b -= 2;
            } else if (a > 1) {
                board[i][j] = u;
                board[i][j+1] = u;
                board[i+1][j] = v;
                board[i+1][j+1] = v;
                a -= 2;
            }
        }
    }

    return board;
}



void solve() {
    int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
    if (n % 2 == 1 && m % 2 == 1) {
        cout << "IMPOSSIBLE"; return;
    }
    if (n % 2 == 0 && m % 2 == 0) {
        if (n * m > 4 * (a/2) + 4 * (b/2) + 4 * c) cout << "IMPOSSIBLE";
        else {
            auto board = showEven(n, m, a, b, c);
            displayBoard(board);
        }
        return;
    } else {
        bool flip = false;
        if (n % 2 == 1) {
            swap(n, m);
            swap(a, b);
            flip = true;
        }

        // n is even, m is odd
        int breserve = n / 2;
        b -= breserve;
        if (b < 0 || n * (m - 1) > 4 * (a/2) + 4 * (b/2) + 4 * c) {
            cout << "IMPOSSIBLE"; return;
        }
        auto board = showEven(n, m - 1, a, b, c);

        for (int i = 0; i < n; i++) {
            if (i % 4 <= 1) board[i].push_back('g');
            else board[i].push_back('h');
        }

        if (flip) {
            vector<vector<char>> newboard(m, vector<char>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newboard[j][i] = board[i][j];
                }
            }
            board = newboard;
        }
        displayBoard(board);
    }
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