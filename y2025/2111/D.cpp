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
    int n, m; cin >> n >> m;
    vector<int> classrooms(m);
    for (int i = 0; i < m; i++) {
        cin >> classrooms[i];
    }

    sort(classrooms.begin(), classrooms.end());

    vector<vector<int>> res(n);

    // 6 classes
    // n groups means n rooms are used at a single point in time
    // Can we swap same rooms?
    for (int a0 = 0; a0 < 3; a0++) {
        for (int p = 0; p < 2; p++) {
            for (int i = 0; i < (n + 1) / 2; i++) {
                if (i != n - i - 1) {
                    if (p == 0) {
                        res[i].push_back(classrooms[i]);
                        res[n - i - 1].push_back(classrooms[m - i - 1]);
                    } else {
                        res[n - i - 1].push_back(classrooms[i]);
                        res[i].push_back(classrooms[m - i - 1]);
                    }
                } else {
                    if (p == 0) {
                        res[i].push_back(classrooms[i]);
                    } else {
                        res[i].push_back(classrooms[m - i - 1]);
                    }
                }
            }
        }
    }

    for (vector<int> a: res) {
        printVec(a);
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