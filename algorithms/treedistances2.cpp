#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n;
vector<ll> adj[mx];
ll chl[mx], dist[mx], ans[mx];

ll dfs(ll s, ll e)
{
    for (ll a : adj[s]) {
        if (a != e) {
            ++chl[s];
            ++dist[s];
            chl[s] += dfs(a, s);
            dist[s] += dist[a] + chl[a];
        }
    }

    return chl[s];
}

void dfs2(ll s, ll e)
{
    if (s != 1) {
        ll amtnodes = chl[e] - chl[s];
        ll totdistofonlyparent = ans[e] - dist[s] - chl[s] - 1;
        ll othernodes = n - 1 - chl[e];
        //ans[s] += ans[e] + n - 2 * chl[s] - 2; <- simplified form
        ans[s] += dist[s] + totdistofonlyparent + amtnodes + othernodes;
    }
    for (ll a : adj[s]) {
        if (a != e) {
            dfs2(a, s);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    ans[1] = dist[1];
    dfs2(1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}