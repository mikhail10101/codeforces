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
    Let the mex of array a be m

    1.
    All numbers that appear only once below m stay the same
    All numbers that appear twice below m become m
    All numbers greater than m become m

    At this point, every number has a count of exactly one except maybe m
    2.
    If there was a duplicate earlier that became m, all numbers greater
    than the duplicate become that duplicate

    At this point, the array looks like 0, 1, 2... d, d, d, d, d
    3. d becomes e
    4. e becomes d
    */
    int n, k; cin >> n >> k;
    vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    auto res = [&] () -> long long {
        long long total = 0;
        for (int i = 0; i <= n + 1; i++) {
            total += (long long)cnt[i] * (long long)i;
        }
        return total;
    };

    auto getmex = [&] () -> int {
        int m = 0;
        while (cnt[m] > 0) {
            m++;
        }
        return m;
    };


    // First
    int mex = getmex();
    int firstDuplicate = -1;
    for (int i = 0; i < mex; i++) {
        if (cnt[i] > 1) {
            if (firstDuplicate == -1) {
                firstDuplicate = i;
            }
            cnt[mex] += cnt[i];
            cnt[i] = 0;
        }
    }
    for (int i = mex + 1; i <= n + 1; i++) {
        cnt[mex] += cnt[i];
        cnt[i] = 0;
    }


    // printVec(cnt);
    if (k == 1) {
        cout << res(); return;
    }

    // Second
    int c;
    if (firstDuplicate == -1) {
        if (cnt[mex] == 1) {
            cout << res(); return;
        }

        cnt[mex + 1] = cnt[mex];
        cnt[mex] = 0;
        c = 0;
        // 0 1 2 3 4 5 5 5 => 0 1 2 3 4 6 6 6
    } else {
        for (int i = firstDuplicate + 1; i <= n + 1; i++) {
            cnt[firstDuplicate] += cnt[i];
            cnt[i] = 0;
        }
        c = 1;
        // 0 1 3 4 5 5 5 => 0 1 2 2 2 2 2
    }

    // printVec(cnt);
    if (k % 2 == 0) {
        cout << res(); return;
    }

    // cout << "CASE " << c << endl;
    int thirdMex = getmex();
    if (c == 0) {
        cnt[thirdMex] = cnt[thirdMex + 1];
        cnt[thirdMex + 1] = 0;
    } else {
        cnt[thirdMex] = cnt[thirdMex - 1];
        cnt[thirdMex - 1] = 0;
    }

    // printVec(cnt);
    cout << res();
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