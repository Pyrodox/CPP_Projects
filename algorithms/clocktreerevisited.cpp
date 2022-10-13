#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2501;

ll color0 = 0, color1 = 0, color0amt = 0, color1amt = 0;
vector<ll> v(mx);
vector<ll> adj[mx];
vector<bool> vis(mx);

void dfs(ll node, bool iscolor0 = true)
{
    vis[node] = true;
    if (iscolor0) {
        color0 += v[node];
        ++color0amt;
    }
    else {
        color1 += v[node];
        ++color1amt;
    }
    for (ll a : adj[node]) {
        if (!vis[a]) {
            dfs(a, !iscolor0);
        }
    }
}

int main()
{
    ll n;
    ifstream cin("clocktree.in");
    ofstream cout("clocktree.out");
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i + 1]; 
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if (color0 % 12 == color1 % 12) {
        cout << n;
    }
    else if (color0 % 12 == (color1 % 12 + 1) % 12) {
        cout << color0amt;
    }
    else if (color1 % 12 == (color0 % 12 + 1) % 12) {
        cout << color1amt;
    }
    else {
        cout << 0;
    }
}