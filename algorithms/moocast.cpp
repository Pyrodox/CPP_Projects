#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(ll x1, ll x2, ll y1, ll y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void dfs(vector<vector<ll>>& adj, vector<vector<ll>>& v, vector<vector<ll>>& paths, vector<bool>& visited, ll node, ll startnode)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    paths[startnode].push_back(node);
    for (auto u : adj[node]) {
        dfs(adj, v, paths, visited, u, startnode);
    }
}

int main()
{
    ll n;
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    vector<vector<ll>> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        ll tmp1, tmp2, tmp3;
        fin >> tmp1 >> tmp2 >> tmp3;
        v[i] = {tmp1, tmp2, tmp3};
    }
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (i != j && dist(v[i][0], v[j][0], v[i][1], v[j][1]) <= v[i][2]) {
                adj[i].push_back(j);
            }
        }
    }
    vector<vector<ll>> paths(n + 1);
    for (ll i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1);
        dfs(adj, v, paths, visited, i, i);
    }
    ll ans = 0;
    for (auto val : paths) {
        if (val.size() > ans) {
            ans = val.size();
        }
    }
    fout << ans;
}