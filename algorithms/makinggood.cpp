#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        ll total = 0, xorsum = 0;
        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            total += a;
            xorsum ^= a;
        }
        if (total < 2 * xorsum) {
            if (total % 2 == 1) {
                ++total;
                xorsum ^= 1;
                if (total > 2 * xorsum) {
            cout << 3 << "\n";
            total += xorsum;
            cout << 1 << " " << xorsum << " " << total << "\n";
        }
                else {cout << 3 << "\n";
                cout << 1 << " " << (2 * xorsum - total) / 2 << " " << (2 * xorsum - total) / 2 << "\n";}
            }
            else {
                cout << 2 << "\n";
                cout << (2 * xorsum - total) / 2 << " " << (2 * xorsum - total) / 2 << "\n";
            }
        }
        else if (total > 2 * xorsum) {
            total += xorsum;
            cout << 2 << "\n";
            cout << xorsum << " " << total << "\n";
        }
        else if (total == 2 * xorsum) {
            cout << 0 << "\n\n";
        }
    }
}