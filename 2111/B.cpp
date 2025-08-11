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

int fibonacci(int x) {
    if (x == 1 || x == 2)
        return x;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

void solve() {
    int n, m; cin >> n >> m;

    /*
        n = 5 means
        1 2 3 5 8
        everyhting can fit in 8 x 13 x 8
    */
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        int a = fibonacci(n);
        int b = fibonacci(n + 1);

        vector<int> dims;
        for (int i = 0; i < 3; i++) {
            int d; cin >> d;
            dims.push_back(d);
        }

        sort(dims.begin(), dims.end());

        if (a <= dims[0] && a <= dims[1] && b <= dims[2]) {
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }

    for (int r: res) {
        cout << r;
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