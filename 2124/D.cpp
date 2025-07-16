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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    int buff = k - 1;
    int index = 1;
    while (buff > 0) {
        if (buff >= count[index]) {
            buff -= count[index];
            index++;
        } else {
            break;
        }
    }

    int save = buff;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        while (i < n && a[i] > index) {
            i++;
        }
        while (j >= 0 && a[j] > index) {
            j--;
        }

        if (i >= j) { break; }

        if (a[i] == a[j]) {
            if (a[i] == index) {
                save -= 2;
            }
            i++;
            j--;
        } else {
            if (a[i] == index) {
                i++;
            } else if (a[j] == index) {
                j--;
            } else {
                cout << "NO";
                return;
            }
        }
    }

    if (i == j && a[i] == index) {
        save -= 1;
    }

    if (save <= 0) {
        cout << "YES";
    } else {
        cout << "NO";
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