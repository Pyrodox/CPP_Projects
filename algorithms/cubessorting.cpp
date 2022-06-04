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
        vector<ll> v(n);
        for (ll& i : v) {
            cin >> i;
        }
        bool flag = false;
        for (ll i = 0; i < n - 1; ++ i) {
            if (v[i] <= v[i + 1]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}