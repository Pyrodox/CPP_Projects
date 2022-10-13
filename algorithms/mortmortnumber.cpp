#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> dp(n + 1);
    dp[0] = 1 % m;
    for (ll i = 1; i <= n; ++i) {
        dp[i] = i % m * (dp[i - 1] % m) % m;
        if (i % 2 == 1) {
            dp[i] = (dp[i] - (1 % m)) % m;
        }
        else {
            dp[i] = (dp[i] + (1 % m)) % m;
        }
        if (dp[i] < 0) {
            dp[i] += m;
        }
        cout << dp[i] % m << " ";
    }
}