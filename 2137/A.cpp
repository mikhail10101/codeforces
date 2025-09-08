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
    long long k, x; cin >> k >> x;
    /*
    Collatz Conjecture
    if x is even, x/2
    if x is odd, 3 * x + 1

    Can we just keep multiplying by 2?
    YES
    */
    cout << x * (long long)pow(2, k);
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