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
    /*
    Permutation p of length n
    Perform one operation for each integer k from 1 to n
        Choose a subarray length k and subtract 1 from each element
    After all operations, all elements should equal 0
    Is this possible?

    1 1 1 1 1
      1 1 1 1
      1 1 1
          1 1
    1
    2 3 3 4 4
    PROVIDED IS A PERMUTATION

    First, notice with 1 2 3 4 5
    If we instead have 1 2 3 5 4, nothing changes

    5
    5 4 have to be next to each other
    5 4 3 have to next to each other
    5 4 3 2 have to be next to each other

    We can start at 5
    Go left see 4, good.
    Check if 3 is nearby.
    Check if 2 is nearby.
    */
    int n; cin >> n;
    vector<int> a(n);

    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) {
            l = i - 1;
            r = i + 1;
        }
    }

    int search = n - 1;
    while (search > 0) {
        if (l >= 0 && a[l] == search) {
            l--; search--;
        } else if (r < n && a[r] == search) {
            r++; search--;
        } else {
            cout << "NO"; return;
        }
    }

    cout << "YES";
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