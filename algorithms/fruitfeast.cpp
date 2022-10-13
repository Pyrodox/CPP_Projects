#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t, a, b;
    ifstream cin("feast.in");
    ofstream cout("feast.out");
    cin >> t >> a >> b;
    vector<ll> dp(t + 2), v;
    ll ans = 0;
    dp[0] = 1;
    v.push_back(0);
    for (ll i = min(a, b); i <= t; ++i) {
        if ((i >= a && dp[i - a]) || (i >= b && dp[i - b])) {
            ans = max(ans, i);
            dp[i] = 1;
            v.push_back(i);
        }
    }
    for (ll i = 0; i < v.size(); ++i) {
        ll l = 0, r = v.size();
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (v[mid] <= t - v[i] / 2) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        ans = max(ans, v[i] / 2 + v[max((ll)0, l - 1)]);
    }
    cout << ans;
}