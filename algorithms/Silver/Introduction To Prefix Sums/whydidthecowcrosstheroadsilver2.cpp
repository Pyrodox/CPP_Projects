#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");
    ll n, k, b;
    cin >> n >> k >> b;
    vector<ll> v(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    for (ll i = 1; i <= b; ++i) {
        ll a;
        cin >> a;
        v[a]++;
    }
    ll ans = 1e5;
    for (ll i = 1; i <= n; ++i) {
        if (v[i]) {
            dp[i][0]++;
        }
        else {
            dp[i][1]++;
        }
        dp[i][0] += dp[i - 1][0];
        dp[i][1] += dp[i - 1][1];
    }
    for (ll i = k; i <= n; ++i) {
        ans = min(ans, dp[i][0] - dp[i - k][0]);
    }
    cout << ans;
}