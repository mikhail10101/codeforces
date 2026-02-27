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
    /*
    Given a and b
    At least one factor of each a must be in b
    All multiples of each element in b <= k must appear in a
    
    Split a into groups (multiples of numbers)
    See if any multiples are missing

    Numbers larger than k/2 can exist on their own
    Numbers <= k/2 must make sure all multiples above
    them exist

    For instance, it k=16 and 5 exists, then 10 15 must
    also exist

    Construct a sieve? No, k's bound is 10^9
    We can iterate thorugh the sorted array storing heads
    We update heads as we go through the array
    When we find that a head is missing a multiple, we say
    its impossible
    Otherwise we continue iterating until the whole
    array has been finished
    */
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    n = a.size();

    vector<int> head, step;
    for (int i = 0; i < n; i++) {
        bool assigned = false;
        for (int j = 0; j < head.size(); j++) {
            if (a[i] - head[j] < step[j]) { continue; }
            else if (a[i] - head[j] == step[j]) {
                head[j] = a[i];
                assigned = true;
            } else {
                cout << -1; return;
            }
        }
        if (!assigned) {
            head.push_back(a[i]);
            step.push_back(a[i]);
        }
    }

    for (int j = 0; j < head.size(); j++) {
        if (head[j] + step[j] <= k) {
            cout << -1; return;
        }
    }

    cout << step.size() << endl;
    printVec(step);
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