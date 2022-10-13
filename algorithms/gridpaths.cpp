#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll mx = 1e3 + 1;

ll n;
vector<vector<ll>> dp(mx, vector<ll>(mx)), grid(mx, vector<ll>(mx));

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 1;
            }
        }
    }
    if (!grid[n][n] || !grid[1][1]) {
        cout << 0;
        return 0;
    }
    for (ll i = 1; i <= n; ++i) {
        if (grid[1][i]) {
            dp[1][i] = 1;
        }
        else {
            break;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        if (grid[i][1]) {
            dp[i][1] = 1;
        }
        else {
            break;
        }
    }
    for (ll i = 2; i <= n; ++i) {
        for (ll j = 2; j <= n; ++j) {
            if (grid[i][j]) {
                if (dp[i - 1][j]) {
                    dp[i][j] += dp[i - 1][j] % MOD;
                }
                if (dp[i][j - 1]) {
                    dp[i][j] += dp[i][j - 1] % MOD;
                }
            }
        }
    }
    cout << dp[n][n] % MOD;
}