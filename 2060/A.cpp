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
    int a, b, d, e; cin >> a >> b >> d >> e;
    vector<int> cs;
    cs.push_back(a + b);
    cs.push_back(e - d);
    cs.push_back(d - b);

    int res = 1;
    for (int c: cs) {
        int cnt = 0;
        if (a + b == c) cnt++;
        if (b + c == d) cnt++;
        if (c + d == e) cnt++;
        res = max(res, cnt);
    }

    cout << res;
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