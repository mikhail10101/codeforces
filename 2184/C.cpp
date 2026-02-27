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
#include <chrono>

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;
const string NO = "NO";
const string YES = "YES";

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    
    if (n == k) {
        cout << 0; return;
    }

    int time = 0;
    while (n > k && n > 1) {
        time++;
        if (n & 1) {
            n = (n >> 1);
            if (n == k || n + 1 == k) {
                cout << time; return;
            }
            n |= 1;
        } else {
            n >>= 1;
            if (n == k) {
                cout << time; return;
            }
        }
        // cout << "TIME: " << time << " " << n << endl;
    }

    cout << -1;
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