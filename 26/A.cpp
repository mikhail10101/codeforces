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

void solve() {
    int n; cin >> n;
    int ssize = n / 2 + 1;
    
    vector<int> primes;
    vector<int> sieve(ssize, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i < ssize; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int next = i + i;
            while (next < ssize) {
                sieve[next] = 0;
                next += i;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < primes.size(); i++) {
        int a = primes[i];
        int posb = upper_bound(primes.begin(), primes.end(), n / a) - primes.begin();
        if (posb <= i + 1) break;
        for (int j = i + 1; j < posb; j++) {
            int b = primes[j];
            vector<int> arr = {1};
            int x = 0;
            int y = 0;
            while (arr.back() < n) {
                int mn = min(a * arr[x], b * arr[y]);
                arr.push_back(mn);
                if (a * arr[x] == mn) x++;
                if (b * arr[y] == mn) y++;
            }
            if (arr.back() > n) arr.pop_back();
            int pa = int_log(arr.back(), a);
            int pb = int_log(arr.back(), b);
            int add = arr.size() - 1 - pa - pb;
            res += add;
        }
    }

    cout << res;
}

bool multiple = false;;

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