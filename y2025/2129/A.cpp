#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
void print(T a) { cout << a << endl; }
template <typename T>
void print(T a, T b) { cout << a << " " << b << endl; }
template <typename T>
void print(T a, T b, T c) { cout << a << " " << b << " " << c << endl; }
template <typename T>
void print(T a, T b, T c, T d) { cout << a << " " << b << " " << c << " " << d << endl; }
template <typename T>
void print(T a, T b, T c, T d, T e) { cout << a << " " << b << " " << c << " " << d << " " << e << endl; }

void solve() {
    int n; cin >> n;
    map<int, vector<pair<int, int>>> btree;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        btree[a].push_back({b, i + 1});
    }

    unordered_set<int> ends;
    vector<int> res;

    for (auto [key, value]: btree) {
        auto [maxi, index] = *(max_element(value.begin(), value.end()));
        if (ends.find(maxi) == ends.end()) {
            ends.insert(maxi);
            res.push_back(index);
        }
    }

    cout << res.size() << endl;
    for (int x: res) {
        cout << x << " ";
    }
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