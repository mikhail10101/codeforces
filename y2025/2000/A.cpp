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
    string s; cin >> s;
    if (s.size() < 3) {
        cout << "NO"; return;
    }
    if (!(s[0] == '1' && s[1] == '0')) {
        cout << "NO"; return;
    }
    // From index 2 to the end
    if (s[2] == '0') {
        cout << "NO";
    } else {
        if (s.size() == 3) {
            if (s[2] == '1' || s[2] == '0') {
                cout << "NO";
            } else {
                cout << "YES";
            }
        } else {
            cout << "YES";
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