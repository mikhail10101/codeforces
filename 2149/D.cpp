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
    int n; cin >> n;
    string s; cin >> s;

    /*
    Can we just calculate how difficult it would be to do it for
    both a and b and simply return the minimum?

    To move a letter n pos, you would need n swaps

    Its better to do inner swaps first as it pushes existing other letters
    backwards

    In other words, its always optimal to pick a middle letter and move everything
    towards that letter

    Given pos1, pos2... posn, find the pos that minimizes
    | posx - posn | for all n
    The middle? Yeah, it should always be the middle I think
    */
    vector<int> as, bs;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            as.push_back(i);
        } else {
            bs.push_back(i);
        }
    }

    auto calc = [&] (vector<int> x) -> ll {
        sort(x.begin(), x.end());
        int mid = x.size() / 2;
        ll ops = 0;
        for (int i = 0; i < x.size(); i++) {
            ops += abs(x[i] - x[mid]) - abs(i - mid);
        }
        return ops;
    };

    cout << min(calc(as), calc(bs));
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