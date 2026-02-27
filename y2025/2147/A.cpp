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
    /*
    1 2 3 4 5 6 7
    Even indexes contribute to x
    Odd indexes contribute to y
    
    Min y value is 2
    Afterwards, the value of y heavily depends on x

    Any x is achievable, but a y within that is the question

    If x > y, we can have steps 1, y, x - 1
    If x == y, its impossible
    If x < y, then simply have x come before y
    */
    int x, y; cin >> x >> y;
    if (x == y || x == y + 1 || y == 1) {
        cout << -1; return;
    }
    if (x > y) {
        cout << 3; return;
    } 
    cout << 2;
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