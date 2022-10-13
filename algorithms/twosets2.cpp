#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= sum; ++j) {
            dp[i][j] += dp[i - 1][j];
            if (j - i >= 0) {
                dp[i][j] += dp[i - 1][j - i];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n - 1][sum];
}