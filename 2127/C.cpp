#include <iostream>
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
    a1, a2, a3.. an
    b1, b2, b3.. bn

    Ali selects i and j
    Bahamin rearranges 4 integers ai, aj, bi, and bj arbitrarily

    v = sum of abs(ai - bi)

    Ali wants to minimize v
    Bahamin wants to maximize v

    Given numbers 1 2 3 4,
    - Ali wants to keep 1 and 2 paired and 3 and 4 paired
    - Bahamin wants to separate 1 from 2 and 3 from 4

    We can think of these pairs as intervals.

    When intervals don't cross, its good for Ali
    When intervals cross, its good for Bahamin

    Since Bahamin does the swapping, he can't uncross intervals. He can only prevent intervals
    from being crossed.

    Since Ali has to pick at least 1 interval, he should pick intervals that are crossed.
    If no intervals are crossed, Ali should pick two intervals with the minimum difference.
    */
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long total = 0;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        intervals[i].first = min(a[i], b[i]);
        intervals[i].second = max(a[i], b[i]);
        total += intervals[i].second - intervals[i].first;
    }
    sort(intervals.begin(), intervals.end());

    int mini = INF;
    for (int i = 0; i < n - 1; i++) {
        if (intervals[i].second > intervals[i + 1].first) {
            cout << total; return;
        } else {
            mini = min(mini, intervals[i + 1].first - intervals[i].second);
        }
    }

    cout << total + 2 * mini;
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