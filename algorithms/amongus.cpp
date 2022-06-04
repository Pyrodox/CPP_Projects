#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<ll, ll>>> adj;
vector<pair<ll, ll>> potentials;
vector<bool> vis;
vector<ll> nodecolors;
ll unused, c0, c1, cur;
bool flag;

void dfs(ll node, ll color)
{
    --unused;
    vis[node] = true;
    nodecolors[node] = color;
    if (color == 1) {
        potentials[cur].second++;
    }
    else {
        potentials[cur].first++;
    }
    
    for (auto a : adj[node]) {
        if (!vis[a.first] && flag) {
            if (a.second == 1) {
                dfs(a.first, (color + 1) % 2);
            }
            else {
                dfs(a.first, color);
            }
        }
        else if (a.second == 1 && nodecolors[node] == nodecolors[a.first] && flag) {
            cout << -1 << "\n";
            flag = false;
            return;
        }
        else if (a.second == 2 && nodecolors[node] != nodecolors[a.first] && flag) {
            cout << -1 << "\n";
            flag = false;
            return;
        }
    }
}

int main()
{
    ll n, q, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> q;

        vector<bool> connected(n + 1);
        unused = n;
        c0 = 0;
        c1 = 0;
        cur = 0;
        flag = true;
        nodecolors = vector<ll>(n + 1);
        vis = vector<bool>(n + 1);
        adj = vector<vector<pair<ll, ll>>>(n + 1);
        potentials = vector<pair<ll, ll>>(n); 

        for (ll i = 0; i < q; ++i) {
            ll type, i2, j;
            cin >> type >> i2 >> j;
            connected[i2] = true;
            connected[j] = true;
            adj[i2].push_back({j, type});
            adj[j].push_back({i2, type});
        }
        for (ll i = 1; i <= n & flag; ++i) {
            if (!vis[i] && connected[i]) {
                dfs(i, 0);
                ++cur;
            }
        }
        if (!flag) {
            continue;
        }
        ll ans = 0;
        for (ll i = 0; i < cur; ++i) {
            ans += max(potentials[i].first, potentials[i].second);
        }
        cout << ans + unused << "\n";
    }
}