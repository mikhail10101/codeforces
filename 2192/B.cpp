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
    For all chars to be 0, one bit has to be a 0 and all other bits are 1s
    011111

    Hold 1 steady and flip all other bits
    Question: given the amount of 0 bits, is it always possible to increase this

    How the op works
    x
    n - x

    operation on 1
    n - x - 1
    x + 1

    operation on 0
    n - x + 1
    x - 1

    op 0 then op 1
    x - 2
    n - x + 2

    We can always increase the number of zeroes by 2 if we run op on a 1 and an op on a 0
    Repeated ops do not change the value

    Win conditions:
        - even number of ones
        - odd number of zeroes
    */
    int n; cin >> n;
    string s; cin >> s;

    int zeroCnt = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeroCnt++;
            x = i;
        }
    }

    vector<int> res;
    if (zeroCnt % 2 == 1) {
        res.push_back(x + 1);
        for (int i = 0; i < n; i++) {
            if (x != i) {
                s[i] = '0' + ('1' - s[i]);
            }
        }
    }

    int oneCnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            oneCnt++;
            res.push_back(i + 1);
        }
    }

    if (oneCnt % 2 == 1) {
        cout << -1;
        return;
    }

    cout << res.size() << endl;
    printVec(res);
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