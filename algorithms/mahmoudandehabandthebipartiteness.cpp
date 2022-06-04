#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, color0val = 0, color1val = 0, ans = 0;
vector<bool> vis(mx);
vector<vector<ll>> v(mx);

void dfs(ll node, ll color)
{
    vis[node] = true;
    //cout << node << "\n";
    if (color == 0) {
        color0val++;
        if (color1val >= 2) {
            ans += color1val - 1;
        }
    }
    else {
        color1val++;
        if (color0val >= 2) {
            ans += color0val - 1;
        }
    }
    for (ll i : v[node]) {
        if (!vis[i]) {
            dfs(i, !color);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    cout << ans;   
}