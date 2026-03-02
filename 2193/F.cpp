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
#include <chrono>

using namespace std;

using ll = long long;

const ll INF = 1e17 + 11;
const string NO = "NO";
const string YES = "YES";

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    /*
    We go left, visit every house, then go left again
    As soon as we visit the last house, move left

    We can then calculate the minimum time it takes to leave each house
    
    Formula for calculating house traversal?

    Either left then right or right then left
    */
    map<int, vector<int>> mp;
    int n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    for (int i = 0; i < n; i++) mp[x[i]].push_back(y[i]);

    int lastKey = ax;
    vector<pair<int, ll>> prevdp(2, {ay, 0});
    vector<pair<int, ll>> newdp(2);

    for (auto& [key, houses]: mp) {
        int m = houses.size();
        int mini = *min_element(houses.begin(), houses.end());
        int maxi = *max_element(houses.begin(), houses.end());

        int hor = key - lastKey;

        // Evaluate ending at the current mini
        newdp[0] = {mini, INF};
        for (int i = 0; i < 2; i++) {
            auto [start, cost] = prevdp[i];
            newdp[0].second = min(
                newdp[0].second,
                cost + abs(start - maxi) + (maxi - mini) + hor
            );
        }

        // Evalute ending at the current maxi
        newdp[1] = {maxi, INF};
        for (int i = 0; i < 2; i++) {
            auto [start, cost] = prevdp[i];
            newdp[1].second = min(
                newdp[1].second,
                cost + abs(start - mini) + (maxi - mini) + hor
            );
        }

        // cout << "DEBUG " << newdp[0].second << " " << newdp[1].second << endl;

        lastKey = key;
        prevdp = newdp;
    }

    ll first = prevdp[0].second + abs(by - prevdp[0].first) + (bx - lastKey);
    ll second = prevdp[1].second + abs(by - prevdp[1].first) + (bx - lastKey);

    cout << min(first, second);
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