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
    Alice tries to mazimize cost
    Bob tries to minimize cost

    They can end the game at any point in time

    f(a) = cost + sum of odd - sum of even

    Switching al and ar adds (r - l) to the cost
    
    Looking at it, Alice has no limit
    Bob, however, will try ending the game as soon as he knows
    there is nothing beneificial left for him

    Anything Bob does can be reversed by Alice right after and incur cost

    Because anything Bob does is reversible by Alice, it seems
    like Alice only has one turn before Bob ends the game.

    Alice can either choose to use this to make a larger score
    or she can simply end the game.

    Answer: Alice makes one move or Alice makes no moves
    */
    long long n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) ans -= a[i];
        else ans += a[i];
    }

    long long init = ans;

    // Swap same parity
    for (int i = 0; i < n; i++) {
        ans = max(ans, init + i - (i % 2));
    }

    long long min_even = LLONG_MAX / 2, min_odd = LLONG_MAX / 2;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            ans = max(init + i + a[i] + a[i] - min_even, ans);
            min_odd = min(min_odd, i - a[i] - a[i]);
        } else {
            ans = max(init + i - a[i] - a[i] - min_odd, ans);
            min_even = min(min_even, i + a[i] + a[i]);
        }
    }

    cout << ans;
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