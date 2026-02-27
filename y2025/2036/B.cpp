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
    int n, k; cin >> n >> k;
    vector<int> bcost(k + 1);
    for (int i = 0; i < k; i++) {
        int brand; cin >> brand;
        int cost; cin >> cost;
        bcost[brand] += cost;
    }
    sort(bcost.begin(), bcost.end(), greater<int>());
    cout << accumulate(bcost.begin(), bcost.begin() + min(n, k), 0);
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