#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 4e4 + 1;

ll b, e, p, n, m;

vector<vector<ll>> adj(mx);

vector<ll> bfs(ll start)
{
    vector<ll> dist(n + 1, -1);
    dist[start] = 0;
    queue<ll> que;
    que.push(start);
    while (que.size()) {
        ll u = que.front();
        que.pop();
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    return dist;
}

int main()
{
    ifstream cin("piggyback.in");
    ofstream cout("piggyback.out");
    cin >> b >> e >> p >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dista = bfs(1), distb = bfs(2);
    ll mxval = b * dista[n] + e * distb[n];
    auto distp = bfs(n);
    for (ll i = 1; i <= n; ++i) {
        mxval = min(mxval, p * distp[i] + b * dista[i] + e * distb[i]);
    }
    cout << mxval;
}