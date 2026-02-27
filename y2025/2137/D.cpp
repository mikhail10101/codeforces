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
    int n; cin >> n;
    unordered_map<int, int> hmap;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[i] = x;
        hmap[x]++;
    }

    /*
    Key: f(x)
    Value: the amount of times f(x) appeared

    If Key < Value, then its impossible
    Key == Value means that the f(x) appeared f(x) times
    Key > Value can only happen if Value % Key == 0, suggesting 2 x and y both appeared f(x) times
    */    
    unordered_map<int, vector<int>> akey;
    int counter = 1;
    for (auto [key, value]: hmap) {
        if (value < key) {
            cout << -1; return;
        }
        if (value > key && value % key != 0) {
            cout << -1; return;
        }
        akey[key] = {counter, 0, value/key};
        counter += value / key;
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = akey[b[i]][0] + akey[b[i]][1];
        akey[b[i]][1] = (akey[b[i]][1] + 1) % akey[b[i]][2];
    }

    printVec(res);
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