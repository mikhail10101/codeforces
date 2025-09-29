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
    // Constantly maintain where the first instance of 1100 is in the string
    string s; cin >> s;
    int n = s.size();

    auto check = [&] (int i) -> bool {
        return (
            s[i] == '1' && s[i + 1] == '1' &&
            s[i + 2] == '0' && s[i + 3] == '0'
        );
    };

    unordered_set<int> pool;
    for (int i = 0; i < n - 3; i++) {
        if (check(i)) pool.insert(i);
    }

    int q; cin >> q;
    for (int z = 0; z < q; z++) {
        int i, v; cin >> i >> v; i--;
        char c = '0' + v;
        if (s[i] != c) {
            s[i] = c;
            for (int offset = -3; offset < 4; offset++) {
                int start = i - offset;
                if (start < 0 || start + 3 >= n) continue;
                if (check(start)) pool.insert(start);
                else pool.erase(start);
            }
        }

        if (pool.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
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