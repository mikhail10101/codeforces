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
    int n; cin >> n;

    int winners = n;
    int losers = 0;
    int res = 0;

    while (true) {
        if (losers == 1 && winners == 1) {
            cout << res + 1; return;
        }

        int winMatches = winners / 2;
        winners -= winMatches;
        res += winMatches;
        losers += winMatches;

        int loseMatches = losers / 2;
        losers -= loseMatches;
        res += loseMatches;
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