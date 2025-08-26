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
    int n; cin >> n;
    long long a, b, x, y; cin >> a >> b >> x >> y;
    long long total = 0;

    vector<long long> step(n);
    for (int i = 0; i < n; i++) {
        cin >> step[i];
        total += step[i];
    }

    long long distSquared = (x - a) * (x - a) + (y - b) * (y - b);

    if (distSquared > total * total) {
        cout << "NO"; return;
    }

    sort(step.begin(), step.end(), greater<int>());

    long long least = step[0];
    
    for (int i = 1; i < n; i++) {
        least -= step[i];
    }

    if (least <= 0 || least * least <= distSquared) {
        cout << "YES"; return;
    }

    cout << "NO";
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