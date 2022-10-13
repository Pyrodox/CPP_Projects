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
    vector<ll> dp(1000001), coins = {1, 2, 3, 4, 5, 6};
    for (ll i = 1; i <= 6; ++i) {
        dp[i] = 1;
    }
    dp[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j < 6; ++j) {
            if (i >= coins[j]) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
            else {
                break;
            }
        }
    }
    cout << dp[n];
}