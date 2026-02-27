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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> decStack;
    vector<int> leftLarger(n, -1);
    for (int i = 0; i < n; i++) {
        while (!decStack.empty() && decStack.back().first < a[i]) {
            decStack.pop_back();
        }
        if (!decStack.empty()) {
            leftLarger[i] = decStack.back().second;
        }
        decStack.push_back({a[i], i});
    }

    vector<pair<int, int>> incStack;
    vector<int> rightSmaller(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!incStack.empty() && incStack.back().first > a[i]) {
            incStack.pop_back();
        }
        if (!incStack.empty()) {
            rightSmaller[i] = incStack.back().second;
        }
        incStack.push_back({a[i], i});
    }

    vector<int> L(n, -1);
    for (int i = 1; i < n; i++) {
        if (leftLarger[i] >= 0 && rightSmaller[i] < n) {
            L[rightSmaller[i]] = max(L[rightSmaller[i]], leftLarger[i]);
        }
    }
    for (int i = 1; i < n; i++) {
        L[i] = max(L[i], L[i - 1]);
    }

    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r; l--; r--;
        if (l <= L[r]) {
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