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
        map<ll, ll> mp;
        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            while (a % 2 == 0) {
                a /= 2;
            }
            ++mp[a];
        }
        ll cnt = 0;
        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            while (a != 0) {
                if (mp[a]) {
                    --mp[a];
                    ++cnt;
                    break;
                }
                a /= 2;
            }
        }
        if (cnt == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}