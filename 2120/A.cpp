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
    /*
    3 rectangles to form a square

    b1 is always the largest rectangle
    */
    int l1, l2, l3, b1, b2, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 == l2 && l2 == l3) {
        if (b1 + b2 + b3 == l1) { 
            cout << "YES";
            return;
        }
    }
    if (b1 == b2 && b2 == b3) {
        if (l1 + l2 + l3 == b1) {
            cout << "YES";
            return;
        }
    }
    if (l1 == l2 + l3) {
        if (b2 == b3 && b1 + b2 == l1) {
            cout << "YES";
            return;
        }
    }
    if (b1 == b2 + b3) {
        if (l2 == l3 && l1 + l2 == b1) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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