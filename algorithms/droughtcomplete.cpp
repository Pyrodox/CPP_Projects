#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        ll n, ans = 0;
        cin >> n;
        vector<ll> v(n);
        for (ll& val : v) {
            cin >> val;
        }
        if (n == 2 && v[0] != v[1]) {
            cout << -1 << "\n";
        }
        else if (n == 2) {
            cout << 0 << "\n";
        }
        else if (n > 1) {
            bool flag = true;
            for (ll j : {1, 2}) {
                for (ll i = 1; i < n - 1; ++i) {
                    if (v[i] > v[i - 1]) {
                        ll dif = v[i] - v[i - 1];
                        ans += 2 * dif;
                        v[i + 1] -= dif;
                        v[i] = v[i - 1];
                    }
                }
                if (v[n - 1] > v[n - 2]) {
                    cout << -1 << "\n";
                    flag = false;
                    break;
                }
                reverse(v.begin(), v.end());
            }
            if (v[0] < 0 && flag) {
                cout << -1 << "\n";
            }
            else if (flag) {
                cout << ans << "\n";
            }
        }
        else {
            cout << 0 << "\n";
        }
    }
}