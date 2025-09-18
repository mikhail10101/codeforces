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
    /*
    Bob has x
    Find a y such that the combined digits of x and y
    are divisible by x + y

    x#y = x(10^z) + y = (x + y) * k and y has z digits
    Find k?

    x#y = x(10^z) + y = x(10^z - 1) + x + y
    So x(10^z - 1) has to be divisible by (x + y)
    If y = 2x,
    x(10^z - 1) has to be divisble by 3x
    The second factor will always be of the form 99....9, and will always
    be divisible by 3

    */
    long long x; cin >> x;
    cout << 2*x;
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