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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 2;
    int prev2 = a[0];
    int prev1 = a[1];
    int right = n - 1;

    vector<char> q = {'L', 'L'};

    while (left < right) {
        if (prev2 > prev1) {
            if (a[left] < a[right]) {
                q.push_back('L');
                q.push_back('R');
                prev2 = a[left];
                prev1 = a[right];
            } else {
                q.push_back('R');
                q.push_back('L');
                prev2 = a[right];
                prev1 = a[left];
            }
        } else {
            if (a[left] > a[right]) {
                q.push_back('L');
                q.push_back('R');
                prev2 = a[left];
                prev1 = a[right];
            } else {
                q.push_back('R');
                q.push_back('L');
                prev2 = a[right];
                prev1 = a[left];
            }
        }
        left++;
        right--;
    }

    if (q.size() < n) {
        q.push_back('L');
    }
    
    for (char res: q) {
        cout << res;
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