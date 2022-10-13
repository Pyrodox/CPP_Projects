#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

vector<vector<pair<ll, ll>>> adj(mx);
vector<vector<ll>> descendants(mx);
vector<ll> vis(mx), edgevis(mx), parentused(mx), root(mx);
vector<vector<ll>> ans;

void dfs(ll node, ll parent)
{
    vis[node] = 1;
    for (auto val : adj[node]) {
        if (val.first != parent) {
            if (!vis[val.first]) {
                edgevis[val.second] = 1;
                dfs(val.first, node);
                descendants[node].push_back(val.first);
            }
            else if (!edgevis[val.second]) {
                edgevis[val.second] = 1;
                descendants[node].push_back(val.first);
            }
        }
    }
    vector<ll> viabledescendants;
    for (ll i = 0; i < descendants[node].size(); ++i) {
        if (!parentused[descendants[node][i]]) {
            viabledescendants.push_back(descendants[node][i]);
        }
    }
    if (viabledescendants.size() % 2 == 0 && viabledescendants.size() > 0) {
        for (ll i = 0; i < viabledescendants.size(); i += 2) {
            ans.push_back({viabledescendants[i], node, viabledescendants[i + 1]});
        }
    }
    else if (viabledescendants.size() > 0) {
        for (ll i = 0; i < viabledescendants.size() - 1; i += 2) {
            ans.push_back({viabledescendants[i], node, viabledescendants[i + 1]});
        }
        parentused[node] = 1;
        if (!root[node]) {
            ans.push_back({viabledescendants[viabledescendants.size() - 1], node, parent});
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    parentused[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            root[i] = 1;
            dfs(i, 0);
        }
    }
    cout << ans.size() << "\n";
    for (auto val : ans) {
        cout << val[0] << " " << val[1] << " " << val[2] << "\n";
    }
}