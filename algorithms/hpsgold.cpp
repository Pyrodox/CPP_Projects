#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "P") {
            v[i] = 1;
        }
        else if (s == "S") {
            v[i] = 2;
        }
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(3, vector<ll>(21)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            for (ll l = 0; l <= min(i, k); ++l) {
                if (j == v[i]) {
                    dp[i][j][l]++;
                }
                else if (l < k) {
                    if (v[i] > j) {
                        dp[i][v[i]][l + 1] = max(dp[i][v[i]][l + 1], dp[i][j][l]);
                    }
                    else {
                        dp[i][v[i]][l + 1] = max(dp[i][v[i]][l + 1], dp[i][j][l] + 1);
                    }
                }
                if (i < n - 1) {
                    dp[i + 1][v[i]][l] = dp[i][v[i]][l];
                }
                if (i < n - 1) {
                    dp[i + 1][j][l] = dp[i][j][l];
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= k; ++i) {
        ans = max(ans, dp[n - 1][0][i]);
        ans = max(ans, dp[n - 1][1][i]);
        ans = max(ans, dp[n - 1][2][i]);
    }
    cout << ans;
}