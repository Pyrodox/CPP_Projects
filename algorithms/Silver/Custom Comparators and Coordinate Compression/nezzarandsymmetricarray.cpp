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
        vector<ll> v(2 * n);
        for (ll i = 0; i < 2 * n; ++i) {
            cin >> v[i];
        }
        bool flag = false;
        sort(v.begin(), v.end());
        for (ll i = 1; i < 2 * n; i += 2) {
            if (v[i] == v[i + 1] || v[i] != v[i - 1] || v[i] % 2 == 1) {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ll sum = 0;
        for (ll i = n - 1; i >= 0; --i) {
            long double a = (v[2 * i + 1] - sum) / (2 * i + 2.0);
            ll b = (v[2 * i + 1] - sum) / (2 * i + 2);
            if (a <= 0 || a != b) {
                cout << "NO\n";
                flag = true;
                break;
            }
            sum += 2 * a;
        }
        if (flag) {
            continue;
        }
        cout << "YES\n";
    }
}