#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<vector<ll>>> dp = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2)));
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                ll a;
                cin >> a;
                if (i == 1) {
                    dp[i][j][0] += a + dp[i][j - 1][0];
                    dp[i][j][1] += a + dp[i][j - 1][1];
                }
                else if (j == 1) {
                    dp[i][j][0] += a + dp[i - 1][j][0];
                    dp[i][j][1] += a + dp[i - 1][j][1];
                }
                else {
                    dp[i][j][0] += a + min(dp[i][j - 1][0], dp[i - 1][j][0]);
                    dp[i][j][1] += a + max(dp[i][j - 1][1], dp[i - 1][j][1]);
                }
            }
        }
        if (dp[n][m][0] <= 0 && dp[n][m][1] >= 0 && (n + m) % 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}