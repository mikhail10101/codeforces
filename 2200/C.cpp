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
    Most important thing to note is that
    s[i] == s[j] for the function to work

    When I think about it, our first pair should be
    beside one another

    Otherwise, you get a case
    abc *b*
    Argument, abcd then *bc*
    However, in that case, you should have simply
    chosen to do it from the center

    Then, one character needs another of the same character
    to complement it
    An odd count of a character means its impossible to
    win the game

    Then, we can try adding to a stack and popping from the top
    */
    int n; cin >> n;
    string s; cin >> s;

    vector<char> stack;
    for (char c: s) {
        if (stack.empty() || stack.back() != c)
            stack.push_back(c);
        else 
            stack.pop_back();
    }

    cout << (stack.empty() ? YES : NO);
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