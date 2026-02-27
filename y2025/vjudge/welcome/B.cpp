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
    string s; cin >> s;
    unordered_map<char, int> cnt;
    for (char c: s) cnt[c]++;

    int res = 0;
    for (int i = 0; i < 26; i++) {
        int lower = cnt['a' + i];
        int upper = cnt['A' + i];

        int paired = min(lower, upper);
        res += paired;

        int excess = lower + upper - paired * 2;
        int exPairs = excess / 2;
        int change = min(exPairs, k);
        k -= change;
        res += change;
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