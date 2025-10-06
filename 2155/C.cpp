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
    A wizard and the one right after it can only
    differ by at most 1
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool same = true;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) >= 2) {
            cout << 0; return;
        }
        if (a[i] != a[i + 1]) same = false;
    }
        
    if (same) {
        if (n % 2 == 0) {
            if (a[0] == n / 2 || a[0] == n / 2 + 1) {
                cout << 2; return;
            } else {
                cout << 0; return;
            }
        } else {
            if (a[0] == n / 2 + 1) {
                cout << 2; return;
            } else {
                cout << 0; return;
            }
        }
    }

    /*
    The difference between two adj positions
    are defined by those two wizards alone

    if a[i] = a[i+1]
        both must not be able to see each other
        OR
        both must be able to see each other
    if a[i] + 1 = a[i+1]
        left can see right but right can't see left
    if a[i] = a[i+1] + 1
        right can see left but left can't see right

    Only a[i] = a[i+1] opens room for a difference

    When the whole array is identical, then there are
    two possible arrangements:
    1. L R L R...
    2. R L R L...

    L R L R yields 3
    R L R L yields 2
    if n is even, n / 2 or n / 2 + 1

    L R L R L yields 3
    R L R L R yields 3
    if n is odd, n / 2 + 1

    Otherwise, its deterministic
    1. Find a[i] != a[i+1]
    2. Determine L L or R R
    3. Solve for the rest of the sequence
    */
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