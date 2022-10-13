#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, c;
    ifstream cin("time.in");
    ofstream cout("time.out");
    cin >> n >> m >> c;
    vector<ll> cities(n);
    for (ll i = 0; i < n; ++i) {
        cin >> cities[i];
    }
    vector<vector<ll>> dp(1001, vector<ll>(n, -1)); //> -1 if you traveled to that city at that day, -1 if you did not
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    dp[0][0] = 0;
    ll ans = 0;
    for (ll i = 0; i < 1000; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (dp[i][j] != -1) {
                for (ll u : adj[j]) {
                    dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + cities[u]);
                }
            }
        }
        ans = max(ans, dp[i][0] - c * i * i);
    }
    cout << ans;
}