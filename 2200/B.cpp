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
    If non-decreasing game ends
    Otherwise, remove an element

    Minimum number of elements in the array by the end?
    Goal is to keep removing elements

    If the array is already non-decreasing, game won
    Otherwise, we should keep it away from being non-decreasing

    Look for two elements such at ai > ai+1
    We can then delete all elements besides those two
    If no such element exists, then the array was non-decreasing
    in the first place
    
    We then only have two answers: n or 1
    */
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            cout << 1;
            return;
        }
    }

    cout << n;
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