#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> cycle(100000);

void dfs(vector<vector<ll>>& adj, vector<bool>& visited, ll startnode, ll node)
{
    visited[node] = true;
    if (node == startnode) {
        cycle[startnode] = true;
        return;
    }
    for (auto u : adj[node]) {
        if (!visited[u]) {
            dfs(adj, visited, startnode, u);
        }
    }
}

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < k; ++i) {
        ll p1, p2, s1, s2;
        cin >> p1 >> p2 >> s1 >> s2;
        if (s1 > s2) {
            adj[p1].push_back(p2);
        }
        else {
            adj[p2].push_back(p1);
        }
    }
    for (ll i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1);
        for (ll u : adj[i]) {
            dfs(adj, visited, i, u);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if (cycle[i]) {
            ++ans;
        }
    }
    cout << ans;
}