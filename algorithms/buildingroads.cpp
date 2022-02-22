#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isempty(vector<ll>& v)
{
    return v.size() == 0;
}

void dfs(vector<vector<ll>>& adj, vector<bool>& visited, vector<vector<ll>>& paths, ll node, ll startnode)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    paths[startnode].push_back(node);
    for (auto u : adj[node]) {
        dfs(adj, visited, paths, u, startnode);
    }
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    vector<bool> visited(n + 1);
    vector<vector<ll>> paths(n + 1);
    for (ll i = 1; i <= n; ++i) {
        dfs(adj, visited, paths, i, i);
    }
    paths.erase(remove_if(paths.begin(), paths.end(), isempty), paths.end());
    cout << paths.size() - 1 << "\n";
    for (ll i = 0; i < paths.size() - 1; ++i) {
        cout << paths[i][0] << " " << paths[i + 1][0] << "\n"; 
    }
}