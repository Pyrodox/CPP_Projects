#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n;
        vector<ll> v(4);
        for (ll i = 1; i <= 3; ++i) {
            cin >> v[i];
        }
        ll cnt = 1;
        ll door = 10, key = n;
        while (cnt != 3) {
            if (!v[key]) {
                break;
            }
            else {
                ++cnt;
                key = v[key];
            }
        }
        if (cnt >= 3) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}