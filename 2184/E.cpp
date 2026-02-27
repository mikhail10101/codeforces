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

vector<int> parent;
vector<int> sizes;

int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

void join(int a, int b) {
    int rootA = parent[a];
    int rootB = parent[b];

    if (sizes[rootA] > sizes[rootB]) {
        sizes[rootA] += sizes[rootB];
        parent[rootB] = rootA;
    } else {
        sizes[rootB] += sizes[rootA];
        parent[rootA] = rootB;
    }
}

ll size(int node) {
    ll s = sizes[find(node)];
    return (s) * (s - 1) / 2;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    parent.resize(n);
    sizes.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }

    vector<vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        edges[abs(a[i] - a[i - 1])].push_back(i);
    }

    vector<ll> res;
    ll curr = 0;
    for (int k = n - 1; k > 0; k--) {
        for (int idx: edges[k]) {
            curr -= size(idx);
            curr -= size(idx - 1);
            join(idx, idx - 1);
            curr += size(idx);
        }
        res.push_back(curr);
    }

    reverse(res.begin(), res.end());

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