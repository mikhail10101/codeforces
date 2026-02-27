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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
void printVec(vector<T> vec) {
    for (T v: vec) {
        cout << v << " ";
    } cout << endl;
}

template <typename T>
T manual_log(T n, T base) {
    if (base < 2) throw invalid_argument("Base must be >= 2");
    if (n < 1)    throw invalid_argument("n must be >= 1");
    T result = 0;
    while (n >= base) {
        n /= base;
        result++;
    }
    return result;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    vector<vector<ll>> split(2);
    for (ll x: a) split[x % 2].push_back(x);

    /*
    Max achievable always happens with
    Largest odd number + (k - 1) largest even numbers

    Triggering a toss requires:
        - 1 even number
        - 2 odd numbers

    If we have 3+ odd numbers, cases are simply for
        all k = 1 to n - 2
        For k = n - 1, 
            prioritize the fact that we can take an even number
        
    Ultimately, each query boils down to how many odd numbers
    we are forced to accept
        To maximize, we should always be trying to take
        an odd amount of odd numbers
        We should also be trying to minimize the amount of odd
        numbers we are taking
    */
    
    vector<ll> prefSum(split[0].size() + 1);
    if (split[0].size() > 0) {
        for (int i = 1; i <= split[0].size(); i++) prefSum[i] = prefSum[i - 1] + split[0][i - 1];
    }

    for (int k = 1; k < n; k++) {
        if (split[1].size() == 0) { cout << 0 << " "; continue; }
        if (split[0].size() == 0) {
            if (k % 2) {
                cout << split[1].front() << " ";
            } else {
                cout << 0 << " ";
            }
            continue;
        }
        int evens = min((int)split[0].size(), k - 1);
        int odds = k - evens;
        if (odds % 2) {
            cout << split[1].front() + prefSum[evens] << " ";
        } else {
            cout << split[1].front() + prefSum[evens - 1] << " ";
        }
    }

    if (split[1].size() % 2) {
        cout << split[1].front() + (prefSum.size() > 0 ? prefSum.back() : 0) << " ";
    } else {
        cout << 0;
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