#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e4 + 1;

vector<vector<pair<ll, ll>>> adj(mx);
vector<ll> vis(mx), color(mx), dp(mx), dpnon(mx), visedge(mx);
ll multicolorind = 0, flag = 1, amt = 0;

void dfs(ll node, ll parent, ll stage)
{
    vis[node] = stage;
    color[node] = !color[parent];
    for (auto val : adj[node]) {
        if (val.first != parent) {
            if (!vis[val.first]) {
                dfs(val.first, node, stage + 1);
                dp[val.second] += dp[val.second];
                dpnon[val.second] += dpnon[val.second];
            }
            else {
                if (vis[node] > vis[val.first]) {
                    if (color[node] == color[val.first]) {
                        ++dp[val.second];
                        ++amt;
                        multicolorind = val.second;
                    }
                    else {
                        ++dpnon[val.second];
                    }
                }
                else {
                     if (color[node] == color[val.first]) {
                        --dp[val.second];
                        ++amt;
                        multicolorind = val.second;
                    }
                    else {
                        --dpnon[val.second];
                    }
                }
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back({b, i + 1});
        adj[b].push_back({a, i + 1});
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            multicolorind = 0;
            dfs(i, 0, 1);
        }
    }
    ll ans = 0;
    vector<ll> vecans;
    if (amt == 2) {
        cout << 1 << "\n" << multicolorind;
    }
    else {
        for (ll i = 1; i <= m; ++i) {
            if (dp[i] == amt / 2 && !dpnon[i]) {
                ++ans;
                vecans.push_back(i);
            }
        }
        cout << ans << "\n";
        for (ll a : vecans) {
            cout << a << " ";
        }
    }
}