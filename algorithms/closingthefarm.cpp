#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    ll n, m, tmp1, tmp2;
    ifstream fin("closing.in");
    ofstream fout("closing.out");
    fin >> n >> m;
    vector<ll> order(n + 1);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; ++i) {
        fin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    for (ll i = 1; i <= n; ++i) {
        fin >> order[i];
    }
    unordered_map<ll, ll> mp;
    for (ll i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1);
        vector<vector<ll>> paths(n + 1);
        for (ll j = 1; j <= n; ++j) {
            if (mp[j] == 0) {
                dfs(adj, visited, paths, j, j);
            }
        }
        ll cnt = 0;
        for (ll j = 1; j <= n; ++j) {
            if (paths[j].size() != 0) {
                ++cnt;
            }
        }
        for (auto& u : adj) {
            u.erase(remove(u.begin(), u.end(), order[i]), u.end());
        }
        mp[order[i]]++;
        if (cnt > 1) {
            fout << "NO\n";
        }
        else {
            fout << "YES\n";
        }
    }
}