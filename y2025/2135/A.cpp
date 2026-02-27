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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<deque<int>> blocks(n);
    vector<int> dp(n + 1);

    for (int i = 0; i < n; i++) {
        blocks[a[i]].push_back(i);
        if (blocks[a[i]].size() == a[i] + 1) {
            int start = blocks[a[i]].front();
            dp[i + 1] = max(dp[start] + a[i] + 1, dp[i]);
            blocks[a[i]].pop_front();
        } else {
            dp[i + 1] = dp[i];
        }
    }

    cout << *(max_element(dp.begin(), dp.end()));
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