#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*
We have w and b pins
Rows consist of the same color
Largest frame?

w = 2, b = 5
b
ww
bbb

w = 6, b = 6
w
bb
www
bbbb

What if the answer was always just combining w and b together?
Find a split of n(n+1)/2 that doesn't work?

since w + b = n(n+1)/2,
splitting w into rows means we can split b into rows
can we split an integer into distinct number sums sqrt n/4?
*/
int main() {
    int t; cin >> t;
    while (t--) {
        long long w, b; cin >> w >> b;
        long long square = 2 * (w + b);

        /*
        n(n+1) fastest way to find n?
        */ 
        long long root = sqrt(square);
        while (root * (root + 1) > square) {
            root--;
        }

        cout << root << endl;
    }
}