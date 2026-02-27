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
    int n, m, k; cin >> n >> m >> k;
    vector<int> robots(n), spikes(m);
    for (int i = 0; i < n; i++) cin >> robots[i];
    for (int i = 0; i < m; i++) cin >> spikes[i];

    sort(spikes.begin(), spikes.end());

    // Keep track of whenever we get a new min distance and max distance
    int currMin = 0;
    int currMax = 0;
    vector<int> forward, backward;

    int run = 0;
    string s; cin >> s;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'L') run--;
        else run++;

        if (run > currMax) {
            forward.push_back(i);
            currMax = run;
        }

        if (run < currMin) {
            backward.push_back(i);
            currMin = run;
        }
    }

    vector<int> deaths(n, k);
    for (int i = 0; i < n; i++) {
        int pos = robots[i];
        int rightSpikeIdx = lower_bound(spikes.begin(), spikes.end(), pos) - spikes.begin();
        int leftSpikeIdx = rightSpikeIdx - 1;

        int leftSpikePos, rightSpikePos;
        if (leftSpikeIdx < 0) leftSpikePos = -1000000;
        else leftSpikePos = spikes[leftSpikeIdx];
        if (rightSpikeIdx >= m) rightSpikePos = 1000000;
        else rightSpikePos = spikes[rightSpikeIdx];

        // cout << "IDXS " << leftSpikeIdx << " " << rightSpikeIdx << endl;
        // cout << "ROBOT " << i << " " << leftSpikePos << " " << rightSpikePos << endl;

        int leftDist = pos - leftSpikePos;
        int rightDist = rightSpikePos - pos;

        if (leftDist <= backward.size()) deaths[i] = backward[leftDist - 1];
        if (rightDist <= forward.size()) deaths[i] = min(deaths[i], forward[rightDist - 1]);
    }

    // cout << "DEBUG " ;
    // printVec(deaths);

    vector<int> turns(k);
    for (int d: deaths) {
        if (d < k) turns[d]++;
    }

    int alive = n;
    for (int i = 0; i < k; i++) {
        alive -= turns[i];
        cout << alive << " ";
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