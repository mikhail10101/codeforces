#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
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
    int n; cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int& x: a) {
        cin >> x;
        ++cnt[x];
    }
    vector<int> pos;
    for (int x: cnt) {
        if (x > 0) pos.push_back(x);
    }

    sort(pos.begin(), pos.end());
    int res = 0;
    for (int i = 0; i < pos.size(); i++) {
        res = max(res, pos[i] * ((int)pos.size() - i));
    }

    cout << res;
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