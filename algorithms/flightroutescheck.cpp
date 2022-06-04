#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5;

ll n, m, vis1 = 0, vis2 = 0;
vector<vector<ll>> adj(mx + 1), adj2(mx + 1);
vector<bool> vis1v(mx + 1), vis2v(mx + 1);

void dfs(ll node, ll visval, vector<vector<ll>>& g, vector<bool>& vis)
{
    vis[node] = true;
    if (visval == 1) {
        ++vis1;
    }
    else {
        ++vis2;
    }
    for (ll a : g[node]) {
        if (!vis[a]) {
            dfs(a, visval, g, vis);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs(1, 1, adj, vis1v);
    dfs(1, 2, adj2, vis2v);
    if (vis1 < n) {
        cout << "NO\n";
        for (ll i = 1; i <= n; ++i) {
            if (!vis1v[i]) {
                cout << 1 << " " << i;
                break;
            }
        }
    }
    else if (vis2 < n) {
        cout << "NO\n";
        for (ll i = 1; i <= n; ++i) {
            if (!vis2v[i]) {
                cout << i << " " << 1;
                break;
            }
        }
    }
    else {
        cout << "YES";
    }
}