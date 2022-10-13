#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n), dp(n + 2, 1e9 + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0] = -(1e9 + 1);
    
    for (int i = 0; i < n; i++) {
        ll j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (dp[j-1] < v[i] && v[i] < dp[j])
            dp[j] = v[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] < 1e9 + 1)
            ans = i;
    }
    cout << ans;
}