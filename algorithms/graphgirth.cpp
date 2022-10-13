#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2501;

ll n, m;

vector<vector<ll>> adj(mx);

ll ans = 1e9;

void bfs(ll start)
{
    vector<ll> dist(n + 1, -1);
    dist[start] = 0;
    queue<ll> que;
    que.push(start);
    vector<ll> parent(n + 1);
    vector<pair<ll, ll>> cycles;
    while (que.size()) {
        ll u = que.front();
        que.pop();
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                que.push(v);
            }
            else if (dist[v] >= 0 && parent[u] != v) {
                cycles.push_back({u, v});
            }
        }
    }
    for (ll i = 0; i < cycles.size(); ++i) {
        ll x = cycles[i].first, y = cycles[i].second;
        ll a = x;
        ll camt = 0;
        bool flag = 0;
        while (a != start) {
            camt++;
            if (camt >= ans) {
                flag = 1;
                break;
            }
            a = parent[a];
        }
        if (flag) {
            continue;
        }
        ll b = y;
        while (b != start) {
            camt++;
            if (camt >= ans) {
                break;
            }
            b = parent[b];
        }
        ans = min(ans, camt + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i) {
        bfs(i);
    }
    if (ans == 1e9) {
        cout << -1;
        return 0;
    }
    cout << ans;
}