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
    1 5 4 2 3
    1 2 3 4 5
    COST IS 4

    Why not place the largest unused integer at the front
    */
    int n; cin >> n;
    vector<int> a(n), v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]] = 1;
    }

    int x = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            while (v[x]) {
                x--;
            }
            a[i] = x--;
        }
    }
    // printVec(a);

    int front = 0;
    int tail = n - 1;
    while (front < n && a[front] == front + 1) front++;
    while (tail >= 0 && a[tail] == tail + 1) tail--;

    if (tail < front) {
        cout << 0; return;
    }
    
    cout << n - front - (n - tail - 1);

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