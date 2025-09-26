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

using ll = long long;

const int INF = 1e9 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

void solve() {
    /*
    Given n, construct an array with two instances of each number
    distance between the two instances of x should be a multiple of x
    A SOLUTION ALWAYS EXISTS

    1 2 3 4 5 1 2 3 4 5
    
    Largest number has the most limitations, place first
    5 _ _ _ _ 5 _ _ _ _
    Afterwards, place 4

    5 _ _ _ 4 5 _ _ 4 _
    5 _ _ 3 4 5 3 _ 4 _
    5 _ _ 3 4 5 3 2 4 2
    5 1 1 3 4 5 3 2 4 2

    After placing the initial 5 5, we have a space of n-1 where the middle is
    occupied
    4 4 will then need to be placed crossing this middle area

    7 _ _ _ _ _ 1 7 1 _ _ _ _ _
    */
    int n; cin >> n;
    cout << n << " ";
    for (int i = n - 1; i >= 1; i--) {
        cout << i << " ";;
    }
    cout << n << " ";
    for (int i = 1; i <= n - 1; i++) {
        cout << i << " ";
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