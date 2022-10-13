#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<ll> dp(1000001), coins(n);
    for (ll i = 0; i < n; ++i) {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (ll i = 1; i <= x; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i >= coins[j]) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
            else {
                break;
            }
        }
    }
    cout << dp[x];
}