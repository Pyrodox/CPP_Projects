#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, t;
vector<ll> color0, color1;

void dfs(ll node, ll color, vector<vector<ll>>& v, vector<bool>& vis)
{
    vis[node] = true;
    if (color) {
        color1.push_back(node);
    }
    else {
        color0.push_back(node);
    }
    for (ll a : v[node]) {
        if (!vis[a]) {
            dfs(a, !color, v, vis);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<ll>> v(n + 1);
        vector<bool> vis(n + 1);
        for (ll i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1, 0, v, vis);
        if (color0.size() <= n / 2) {
            cout << color0.size() << "\n";
            for (ll i : color0) {
                cout << i << " ";
            }
        }
        else {
            cout << color1.size() << "\n";
            for (ll i : color1) {
                cout << i << " ";
            }
        }
        cout << "\n";
        color0.clear();
        color1.clear();
    }
}