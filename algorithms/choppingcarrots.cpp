#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
        }
        ll l = 0, r = v[n - 1] - v[0] + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2, flag = 0;
            for (ll start = v[0] / k; start <= v[0] && !flag; ++start) {
                for (ll i = 0; i < n; ++i) {
                    flag = 0;
                    for (ll m = 1; m <= k; ++m) {
                        if (v[i] / m >= start && v[i] / m <= start + mid) {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            if (flag) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }
}