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
    Score of b is length - distincts

    You can remove a subarray from a at most once
    Output an operation such that the score is maximized
    If multiple, output one that minimises the final length of a
    
    Maximizing the score means
    - maximize length
    - minimize distincts

    Score can never increase.
    */
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> len(n + 1);
    len[0] = cnt[a[0]] == 1;
    for (int i = 1; i < n; i++) {
        if (cnt[a[i]] == 1) {
            len[i] = len[i - 1] + 1;
        }
    }

    int maxi = *max_element(len.begin(), len.end());
    if (maxi == 0) {
        cout << 0; return;
    }

    for (int i = 0; i < n; i++) {
        if (len[i] == maxi) {
            cout << i - len[i] + 2 << " " << i + 1;
            return;
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