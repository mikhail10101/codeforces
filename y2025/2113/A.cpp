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

const ll INF = 1e17 + 11;

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

int int_log(int n, int base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    int result = 0;
    while (n >= base) {
        n /= base;
        result++;
    }
    return result;
}

int find_conseq(int n) {
    int root = (int)sqrt(n * 2);
    while (root * (root + 1) > n * 2) root--;
    return root;
}

void solve() {
    int k, a, b, x, y; cin >> k >> a >> b >> x >> y;
    /*
    Steak 1 requires value above a and costs x
    Steak 2 requires value above b and costs y
    We should greedily choose the steak that costs less?
    As soon as we can't choose it anymore, try the other steak
    
    For ease, make a and x correspond to the cheaper steak
    */
    if (x > y) {
        swap(x, y);
        swap(a, b);
    }
    a--; b--;

    int res = 0;
    // Use steak 1 until temperature drops below a
    int diff = max(0, k - a);
    int s1 = diff / x;
    if (diff > s1 * x) s1++;
    res += s1;
    k -= s1 * x;
    // Use steak 2 until temperature drops below b
    diff = max(0, k - b);
    int s2 = diff / y;
    if (diff > s2 * y) s2++;
    res += s2;

    cout << res;
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