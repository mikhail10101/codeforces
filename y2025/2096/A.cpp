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
    int n; cin >> n;
    string s; cin >> s;
    int left = 1;
    int right = n;

    vector<int> res;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] == '<')
            res.push_back(left++);
        else
            res.push_back(right--);
    }
    res.push_back(left);

    reverse(res.begin(), res.end());

    printVec(res);
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