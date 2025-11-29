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

int query(string s) {
    cout << "? " + s << endl;
    int x; cin >> x;
    return x;
}

void answer(string s) {
    cout << "! " + s << endl;
}

void solve() {
    int n; cin >> n;

    /*
    Guess T (If not T, the answer is all false)

    Guess T... + T/F
    If one of them work, keep going
    If both of them fail, reverse and append to the front
    */
    bool addToRight = true;

    int firstT = query("1");
    string ans = "";
    if (firstT == 0) {
        for (int i = 0; i < n; i++) {ans += "0";}
        answer(ans);
        return;
    }

    ans = "1";
    for (int i = 1; i < n; i++) {
        if (addToRight) {
            for (int j = 0; j <= 1; j++) {
                char c = '0' + j;
                int q = query(ans + c);
                if (q == 1) {
                    ans += c;
                    break;
                }
            }
            
            if (ans.size() != i + 1) addToRight = false;
        }

        if (!addToRight) {
            for (int j = 0; j <= 1; j++) {
                char c = '0' + j;
                int q = query(c + ans);
                if (q  == 1) {
                    ans = c + ans;
                    break;
                }
            }
        }
    }

    answer(ans);
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