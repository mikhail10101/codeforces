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
    int n, k; cin >> n >> k;

    vector<vector<bool>> letters(n, vector<bool>(26));
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            letters[j][s[j] - 'a'] = true;
        }
    }

    int res = 1000000;
    string sres = "LMAO";
    for (int i = 0; i < 26; ++i) {
        // cout << "DBEUG " << i << endl;

        if (!letters[0][i]) continue;
        vector<int> idxs;
        for (int j = 0; j < n; ++j) {
            if (letters[j][i]) idxs.push_back(j);
        }

        int size = idxs.size();
        // Check if valid starting point
        for (int intervalCount = size; intervalCount >= 1; --intervalCount) {
            if (n % intervalCount != 0) continue;
            int gap = n / intervalCount;

            vector<vector<int>> candidates(gap);
            for (int p = 0; p < gap; ++p) {
                for (int q = 0; q < 26; ++q) {
                    if (letters[p][q]) candidates[p].push_back(q);
                }
            }

            bool fail = false;
            for (int p = gap; p < n; p += gap) {
                vector<vector<int>> newCandidates(gap);
                for (int q = 0; q < gap; q++) {
                    // Narrow down candidates
                    for (int x: candidates[q]) {
                        if (letters[p + q][x]) {
                            newCandidates[q].push_back(x);
                        }
                    }

                    if (newCandidates[q].empty()) {
                        fail = true;
                        break;
                    }
                }

                if (fail) {
                    fail = true;
                    break;
                }

                candidates = newCandidates;
            }

            if (!fail) {
                if (gap < res) {
                    res = gap;  
                    string repeat = "";
                    for (auto& v: candidates) {
                        repeat += (char) ('a' + v[0]);
                    }

                    
                    sres = "";
                    for (int j = 0; j < n / gap; ++j) {
                        sres += repeat;
                    }
                    // cout << "SETTING " << repeat << endl;
                }
            }
        }
    }

    cout << sres;
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