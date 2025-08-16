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
    int n, x; cin >> n >> x;
    x--;
    string s; cin >> s;

    /*
        _ _ _ _ _ -> 0 tries

        _ _ X # _

        _ # X # _
        _ X _ # _

        # X _ # _
        X _ _ # _

        X # _ # _
        FREE
        
        If there are walls on both sides, Hamid tries running to the wall closer to the edge
        In response, Mani will keep attempting to wall Hamid off at the nearest place possible

        It ends up with Hamid repeatedly breaking walls Manu places down
    */

    if (x == 0 || x == n - 1) {
        cout << 1;
        return;
    }

    int leftWallIndex = -1;
    int rightWallIndex = -1;

    for (int i = x - 1; i >= 0; i--) {
        if (s[i] == '#') {
            leftWallIndex = i;
            break;
        }
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i] == '#') {
            rightWallIndex = i;
            break;
        }
    }

    if (leftWallIndex == -1 && rightWallIndex == -1) {
        cout << 1;
        return;
    } 
    
    if (leftWallIndex != -1 && rightWallIndex != -1) {
        if (leftWallIndex < n - 1 - rightWallIndex) {
            leftWallIndex = x - 1;
        } else {
            rightWallIndex = x + 1;
        }
    } else {
        if (leftWallIndex == -1) {
            leftWallIndex = x - 1;
        }
    
        if (rightWallIndex == -1) {
            rightWallIndex = x + 1;
        }
    }

    if (leftWallIndex < n - 1 - rightWallIndex) {
        cout << leftWallIndex + 2;
    } else {
        cout << n - rightWallIndex + 1;
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