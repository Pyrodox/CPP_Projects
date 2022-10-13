#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll dp[mx], vis[mx];
vector<ll> adj[mx];
vector<pair<ll, ll>> ans;

void dfs(ll node, ll parent, ll stage)
{
    vis[node] = stage;
    for (ll a : adj[node]) {
        if (a != parent) {
            if (!vis[a]) {
                dfs(a, node, stage + 1);
                dp[node] += dp[a];
                ans.push_back({node, a});
            }
            else {
                if (vis[a] < vis[node]) {
                    ++dp[node];
                    ans.push_back({node, a});
                }
                else {
                    --dp[node];
                }
            }
        }
    }
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 1);
    for (ll i = 2; i <= n; ++i) {
        if (!dp[i]) {
            cout << 0;
            return 0;
        }
    }
    for (auto val : ans) {
        cout << val.first << " " << val.second << "\n";
    }
}