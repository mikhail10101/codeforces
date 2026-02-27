#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
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
    int n, s; cin >> n >> s;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int dirx, diry, x, y; cin >> dirx >> diry >> x >> y;
        if (dirx == 0 || diry == 0) continue;
        /*
        Think in reflections

        We have a ball bouncing on a wall
        If we extend the pool and keep the ball going straight, we see a reflection of the ball
        We see if the ball's trajectory ever lands on a coordinate with x and y values
        as multiples of s

        If the slope forms an integer ratio and doens't meet any point, its cooked
        Otherwise, should be chill
        */
        if (diry % dirx != 0 && x % dirx != 0) continue;
        int m = -(diry * x / dirx);
        if ((m + y) % s == 0) total++;
    }

    cout << total;
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