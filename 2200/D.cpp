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

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    /*
    The portals act as a divider
    Its like we have two arrays
    One outside the portal and one inside the portal

    The outer array cannot change their order
    The inside array can loop around

    What's the smallest permutation achievable?

    1 2 3 4 5 6

    if x = 3 and y = 5,
    1 2 3 P 4 5 P 6
    0 1 2   3 4   5
    */
    int n, x, y; cin >> n >> x >> y;
    vector<int> outer(n - (y - x));
    vector<int> inner(y - x);

    for (int i = 0; i < x; ++i) cin >> outer[i];
    for (int i = x; i < y; ++i) cin >> inner[i - x];
    for (int i = y; i < n; ++i) cin >> outer[i - (y - x)];
    
    auto innerMin = min_element(inner.begin(), inner.end());
    int shift = innerMin - inner.begin();
    vector<int> newInner(y - x);
    
    for (int i = 0; i < y - x; ++i) {
        newInner[i] = inner[(i + shift) % (y - x)];
    }

    if (newInner.size() == 0) {
        printVec(outer);
        return;
    }

    for (int i = 0; i < outer.size(); ++i) {
        if (outer[i] > newInner[0]) {
            for (int j = 0; j < i; ++j) {
                cout << outer[j] << " ";
            }
            for (int x: newInner) {
                cout << x << " ";
            }
            for (int j = i; j < outer.size(); ++j) {
                cout << outer[j] << " ";
            }
            return;
        }
    }

    printVec(outer);
    printVec(newInner);
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