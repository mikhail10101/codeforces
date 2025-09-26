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
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[0][0] = true;
    dp[0][1] = true;

    for (int i = 1; i < n; i++) {
        // 0 RIGHT 1 LEFT
        for (int left = 0; left <= 1; left++) {
            if (s[i] == '1') {
                // IF FLOWER
                // CARRY ON THE SUCCESS OF THE LAST PLACED LEFT FACING RABBIT
                dp[i][left] = dp[i - 1][1];
                continue;
            }

            // TRYING TO PLACE A RIGHT RABBIT OR PREVIOUS WAS A RABBIT
            if (!left || s[i - 1] == '0') {
                dp[i][left] = dp[i - 1][1] || dp[i - 1][0];
            }
            // TRYING TO PLACE A LEFT RABBIT AND CHECKING FOR >_< PATTERN
            else if (i >= 2 && s[i - 2] == '0') {
                dp[i][left] = dp[i - 2][0];
            } else {
                dp[i][left] = false;
            }
        }
    }

    cout << ((dp[n-1][0] || dp[n-1][1]) ? "YES" : "NO") << endl;
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