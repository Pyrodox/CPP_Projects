#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<ll>>& v, ll add, ll node, vector<bool>& visited, vector<vector<ll>>& adj)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    v[add].push_back(node);
    for (auto u : adj[node]) {
        dfs(v, add, u, visited, adj);
    }
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> bribes(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> bribes[i];
    }
    for (int i = 0; i < m; ++i) {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    vector<vector<ll>> v(n + 1);
    vector<bool> visited(n + 1);
    for (ll i = 1; i <= n; ++i) {
        dfs(v, i, i, visited, adj);
    }
    map<ll, ll> finaladd;
    for (auto val : v) {
        ll minv = 9999999999, minind = 0;
        for (auto u : val) {
            if (bribes[u] < minv) {
                minind = u; 
                minv = bribes[u];
            }
        }
        finaladd[minind]++;
    }
    ll ans = 0;
    for (auto val : finaladd) {
        ans += bribes[val.first];
    }
    cout << ans;
}