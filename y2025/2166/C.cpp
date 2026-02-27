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
#include <list>

using namespace std;

using ll = long long;

const int INTINF = 1e9 + 10;
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

int find_conseq(int n) {
    int root = (int)sqrt(n * 2);
    while (root * (root + 1) > n * 2) root--;
    return root;
}

ll op(list<ll> lis) {
    vector<list<ll>::iterator> its;
    
    // cout << "LIST ";
    for (auto iter = lis.begin(); iter != lis.end(); iter++) {
        its.push_back(iter); // cout << *iter << " ";
    }
    sort(its.begin(), its.end(), [&] (list<ll>::iterator a, list<ll>::iterator b) -> bool {
        return (*a < *b);
    });

    ll res = 0;
    for (ll i = 0; i < its.size() - 1; i++) {
        list<ll>::iterator it = its[i];
        ll maxi = INF;
        if (it != lis.begin()) maxi = min(maxi, *(prev(it)));
        if (it != prev(lis.end())) maxi = min(maxi, *(next(it)));
        res += maxi;
        lis.erase(it);
    }

    return res;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll maxi = *max_element(a.begin(), a.end());
    vector<ll> pos;
    for (ll i = 0; i < n; i++) if (maxi == a[i]) pos.push_back(i);

    ll res = 0;
    if (pos.size() == 1) {
        res += maxi;
        list<ll> lis;
        for (ll i = pos[0] + 1; i < n; i++) lis.push_back(a[i]);
        for (ll i = 0; i < pos[0]; i++) lis.push_back(a[i]);

        res += op(lis);
    } else {
        int nodes = 0;
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i - 1] + 1 == pos[i]) {
                nodes++;
                continue;
            }
            
            nodes += 2;
            list<ll> lis;
            for (int j = pos[i - 1] + 1; j < pos[i]; j++) {
                lis.push_back(a[j]);
            }

            res += op(lis);
        }

        nodes++;
        if (!(pos[0] == 0 && pos[pos.size() - 1] == n - 1)) {
            list<ll> lis;
            for (int i = pos[pos.size() - 1] + 1; i < n; i++) lis.push_back(a[i]);
            for (int i = 0; i < pos[0]; i++) lis.push_back(a[i]);
            res += op(lis);
            nodes++;
        }

        res += (nodes - 1) * maxi;
    }

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