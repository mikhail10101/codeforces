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

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    long long k, x; cin >> k >> x;
    long long a = x; k++;

    vector<int> res;
    while (a != 1ll << (k - 1)) {
        if (a < 1ll << (k - 1)) {
            a *= 2;
            res.push_back(1);
        } else {
            a -= ((1ll << k) - a);
            res.push_back(2);
        }
    }

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    printVec(res);
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