#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll dist[2][mx];
vector<ll> adj[mx];

ll dfs(ll node, ll e, ll p, ll cnt)
{
    dist[p][node] = cnt;
    ll op = -1;
    for (ll a : adj[node]) {
        if (a != e) {
            ll b = dfs(a, node, p, cnt + 1);
            if (op < 0 || dist[p][b] > dist[p][op]) {
                op = b;
            }
        }
    }

    return op < 0 ? node : op; 
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll node1 = dfs(1, 0, 0, 0);
    ll node2 = dfs(node1, node1, 0, 0);
    dfs(node2, node2, 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << max(dist[0][i], dist[1][i]) << " ";
    }
}