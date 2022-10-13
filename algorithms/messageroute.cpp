#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, m;
vector<vector<ll>> adj(mx);
vector<ll> vis(mx), ansvec;
vector<ll> parent(mx);
ll ans = mx;

void bfs(ll node)
{
    queue<ll> neq;
    neq.push(node);
    while (neq.size()) {
        vis[neq.front()] = parent[neq.front()] + 1;
        for (ll a : adj[neq.front()]) {
            if (!vis[a]) {
                neq.push(a);
                vis[a] = 1;
                parent[a] = neq.front();
            }
        }
        neq.pop();
    }
    if (!vis[n]) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<ll> ans = {n};
        ll a = n;
        while (parent[a]) {
            ans.push_back(parent[a]);
            a = parent[a];
        }
        cout << ans.size() << "\n";
        for (ll i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
}