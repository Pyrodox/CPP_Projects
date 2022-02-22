#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj(100001);
vector<vector<ll>> paths(100001);
vector<bool> visited(100001);

void dfs(ll node, ll startnode)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    paths[startnode].push_back(node);
    for (auto u : adj[node]) {
        dfs(u, startnode);
    }
}

int main()
{
    ll n, m, tmp1, tmp2;
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    fin >> n >> m;
    vector<vector<ll>> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        fin >> tmp1 >> tmp2;
        v[i] = {tmp1, tmp2};
    }
    for (ll i = 1; i <= m; ++i) {
        fin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    for (ll i = 1; i <= n; ++i) {
        dfs(i, i);
    }
    ll ans = 2147483647;
    for (auto val : paths) {
        if (val.size() != 0) {
            ll minx = 100000000, maxx = 0, miny = 100000000, maxy = 0;
            for (ll i = 0; i < val.size(); ++i) {
                minx = min(minx, v[val[i]][0]);
                maxx = max(maxx, v[val[i]][0]);
                miny = min(miny, v[val[i]][1]);
                maxy = max(maxy, v[val[i]][1]);
            }
            ans = min(ans, 2 * (maxy - miny) + 2 * (maxx - minx));
        }
    }
    fout << ans;
}