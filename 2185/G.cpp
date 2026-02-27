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

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        a[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }

    int amt = 0;
    ll S = 0;
    for (auto x: a) {
        S += accumulate(x.begin(), x.end(), 0);
        amt += x.size();
    }

    vector<ll> currMex(n);
    vector<ll> potentialMex(n);

    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
        int m = a[i].size();
        
        int mex = 0;
        int j = 0;
        while (j < m && a[i][j] <= mex) {
            mex = a[i][j] + 1;
            j++;
        }

        currMex[i] = mex;

        mex++;
        while (j < m && a[i][j] <= mex) {
            mex = a[i][j] + 1;
            j++;
        }

        potentialMex[i] = mex;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        int m = a[i].size();

        int other = amt - m;
        
        // mex value of the array when it is unbothered
        int arrchoices = n - 2;
        res += currMex[i] * other * arrchoices;

        // mex value of the array when something is added to it
        res += cnt[currMex[i]] * potentialMex[i];
        res += (other - cnt[currMex[i]]) * currMex[i];

        // mex value of the array when something is removed from it
        int amtGreaterThanMex = a[i].end() - lower_bound(a[i].begin(), a[i].end(), currMex[i]);
        res += amtGreaterThanMex * currMex[i] * (n - 1);

        int track = 0;
        int trackcnt = 0;
        int j = 0;
        while (j < m && a[i][j] < currMex[i]) {
            if (a[i][j] == track) trackcnt++;
            else {
                if (trackcnt > 1) {
                    res += trackcnt * currMex[i] * (n - 1);
                } else {
                    res += track * (n - 1);
                }
                track = a[i][j];
                trackcnt = 1;
            }
            j++;
        }

        if (trackcnt > 1) {
            res += trackcnt * currMex[i] * (n - 1);
        } else {
            res += track * (n - 1);
        }
    }

    cout << res;
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