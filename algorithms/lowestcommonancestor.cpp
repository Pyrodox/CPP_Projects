#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e4 + 1;
const ll LOG = 14;

vector<vector<ll>> adj(mx), up(mx, vector<ll>(LOG));
vector<ll> depth(mx);

void dfs(ll node, ll level)
{
    depth[node] = level;
    for (ll a : adj[node]) {
        up[a][0] = node;
         for (ll i = 1; i < LOG; ++i) {
            up[a][i] = up[up[a][i - 1]][i - 1];
         }
         dfs(a, level + 1);
    }
}

ll lca(ll a, ll b)
{
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    ll amt = depth[a] - depth[b];
    for (ll i = LOG - 1; i >= 0; --i) {
        if (amt & (1 << i)) {
            a = up[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (ll i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main()
{
    ll n, m, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> m;
        for (ll j = 0; j < m; ++j) {
            ll a;
            cin >> a;
            adj[i].push_back(a);
        }
    }
    dfs(0, 0);
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}