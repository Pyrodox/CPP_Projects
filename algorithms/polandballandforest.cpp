#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e4 + 1;

ll n;
vector<bool> vis(mx);
vector<vector<ll>> adj(mx);

void dfs(ll s, ll e)
{
    vis[s] = true;
    for (ll a : adj[s]) {
        if (a != e) {
            dfs(a, s);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 0);
            ++ans;
        }
    }
    cout << ans;
}