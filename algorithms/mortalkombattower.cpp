#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

vector<ll> v(mx);

ll skip(ll ind, ll amt)
{
    ll cnt = 0;
    for (ll i = ind; i < ind + amt; ++i) {
        if (v[i]) {
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        dp[0][0] = skip(0, 1), dp[0][1] = mx;
        dp[1][1] = dp[0][0], dp[1][0] = skip(0, 2);
        for (ll i = 2; i < n; ++i) {
            dp[i][1] = min(dp[i - 2][0], dp[i - 1][0]);
            dp[i][0] = min(dp[i - 2][1] + skip(i - 1, 2), dp[i - 1][1] + skip(i, 1));
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
}