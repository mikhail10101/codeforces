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

vector<bool> isPrime(1000001, true);
vector<int> primes;

void derivePrimes() {
    isPrime[1] = false;
    isPrime[0] = false;     
    for (int i = 2; i <= 1000000; ++i) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 1000000; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    /*
    Replace x with y, z such that x = yz
    Decomposition

    This operation cannot be performed with prime factors
    4 -> 2, 2 -> 1, 1, 2 -> 1, 1, 1, 1
    4 -> 1, 3 -> 1, 1, 2 -> 1, 1, 1, 1

    Once the game ends, if a is non-decreasing, Bob wins
    Otherwise, Alice wins

    Alice goes first

    Eventually, all numbers get broken down into their primes
    We need to check two things:
    First, is it even possible for all primes to be in non-decreasing
    Second, can this be guaranteed to be true or false?

    If Bob reaches a non-decomposed number before Alice does,
    he can always place the larger number before the smaller one

    Therefore, the only way Alice wins is if
    1. All numbers are powers and in increasing order of primes
    2. Alice wins in one move

    The moment Bob gets a move, Alice can no longer win

    How do we test whether a number is a power?

    We can first derive all primes <= 10^3
    Then, we simply iterate through all of them for each element
    */
    int nonPowers = 0;
    int nonPowerIdx = -1;

    bool alreadyNonDecreasing = true;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            alreadyNonDecreasing = false;
            break;
        }
    }

    if (alreadyNonDecreasing) {
        cout << "Bob";
        return;
    }

    vector<int> powers;
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        if (x == 1) {
            powers.push_back(1);
            continue;
        }

        auto it = lower_bound(primes.begin(), primes.end(), x);
        if (it != primes.end() && *it == x) {
            powers.push_back(x);
            continue;
        }

        for (int p: primes) {
            if (x % p == 0) {
                // Check if x is a power of p
                while (x % p == 0) {
                    x /= p;
                }
                if (x != 1) {
                    cout << "Alice";
                    return;
                } else {
                    powers.push_back(p);
                }

                break;
            }
        }
    }

    // Check if powers are in order
    for (int i = 1; i < powers.size(); ++i) {
        if (powers[i - 1] > powers[i]) {
            cout << "Alice";
            return;
        }
    }

    cout << "Bob";
}

bool multiple = true;

int main() {
    derivePrimes();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple) cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}