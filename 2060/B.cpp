#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> idx(n);
    for (int j = 0; j < n; j++) {
        vector<int> cow = a[j];
        sort(cow.begin(), cow.end());
        for (int i = 1; i < m; i++) {
            if (cow[i] != cow[i - 1] + n) {
                cout << -1; return;
            }
        }
        idx[cow[0]] = j;
    }

    for (int i = 0; i < n; i++) {
        cout << idx[i] + 1 << " ";
    }
}

bool multiple = true;

int main() {
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}