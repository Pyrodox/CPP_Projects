#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        ll c1, c2, tmpc1, tmpc2, movesc1 = 0, movesc2 = 0;
        cin >> c1 >> c2;
        tmpc1 = c1, tmpc2 = c2;
        ll potentialmoves = 1e18;
        if (c2 >= c1) {
            potentialmoves = c2 - c1;
        }
        while (tmpc1 != tmpc2) {
            if (tmpc1 >= 2 * tmpc2) {
                if (tmpc1 % 2 == 1) {
                    ++movesc1;
                    ++tmpc1;
                    if (tmpc1 == c1) {
                        movesc1 = 0;
                    }
                }
                tmpc1 /= 2;
                ++movesc1;
                if (tmpc1 == c1) {
                    movesc1 = 0;
                }
            }
            else if (tmpc1 > tmpc2 && tmpc1 < 2 * tmpc2) {
                if (tmpc1 % 2 == 1) {
                    ++movesc1;
                    ++tmpc1;
                    if (tmpc1 == c1) {
                        movesc1 = 0;
                    }
                }
                tmpc1 /= 2;
                ++movesc1;
                if (tmpc1 == c1) {
                    movesc1 = 0;
                }
                potentialmoves = min(potentialmoves, movesc1 + movesc2 + tmpc2 - tmpc1);
                if (tmpc2 % 2 == 1) {
                    --tmpc2;
                    ++movesc2;
                }
                tmpc2 /= 2;
                ++movesc2;
            }
            else if (2 * tmpc1 <= tmpc2) {
                tmpc1 *= 2;
                ++movesc1;
                if (tmpc1 == c1) {
                    movesc1 = 0;
                }
            }
            else if (tmpc1 < tmpc2) {
                potentialmoves = min(potentialmoves, movesc1 + movesc2 + tmpc2 - tmpc1);
                if (tmpc2 % 2 == 1) {
                    ++movesc2;
                    --tmpc2;
                }
                tmpc2 /= 2;
                ++movesc2;
                if (tmpc2 >= tmpc1) {
                    potentialmoves = min(potentialmoves, movesc1 + movesc2 + tmpc2 - tmpc1);
                }
            }
        }
        cout << potentialmoves << "\n";
    }
}