#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    ll n, sum;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> sum;
    vector<ll> dp(sum + 1), coins(n);
    for (ll i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= sum; ++j) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[sum];
}