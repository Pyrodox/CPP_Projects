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
        vector<vector<ll>> v(n);
        for (ll i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            v[i] = {a, b};
        }
        ll l = 1, r = n;
        while (l < r) {
            ll mid = l + (r - l + 1) / 2, minricher, cnt = 1;
            for (ll i = 0; i < n; ++i) {
                if (v[i][0] + 1 >= mid) {
                    minricher = v[i][0];
                    ll iter = i + 1;
                    while (minricher > 0 && cnt < mid && iter < n) {
                        if (mid - cnt - 1 <= v[iter][0] && v[iter][1] >= cnt) {
                            ++cnt;
                            minricher = min(minricher - 1, v[iter][0]);
                        }
                        ++iter;
                    }
                    break;
                }
            }
            if (cnt == mid) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
}