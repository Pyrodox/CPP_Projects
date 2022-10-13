#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1, LOG = 18;  

vector<vector<ll>> adj(mx), up(mx, vector<ll>(LOG + 1));
vector<ll> depth(mx);

void dfs(ll node, ll parent)
{
    depth[node] = depth[parent] + 1;
    up[node][0] = parent;
    for (ll i = 1; i <= LOG; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (ll a : adj[node]) {
        if (a != parent) {
            dfs(a, node);
        }
    }
}

bool cmp(const ll a, const ll b)
{
    return depth[a] > depth[b];
}

ll lca(ll a, ll b)
{
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    ll dist = depth[a] - depth[b];
    for (ll i = 0; i <= LOG; ++i) {
        if ((1 << i) & dist) {
            a = up[a][i];
        }
    }
    for (ll i = LOG; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return a == b ? a : up[a][0];
}

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cin >> q;
    while (q--) {
        ll s;
        cin >> s;
        vector<ll> v(s);
        for (ll& a : v) {
            cin >> a;
        }
        sort(v.begin(), v.end(), cmp);
        vector<ll> mark(s);
        for (ll i = 0; i < v.size(); ++i) {
            if (lca(v[0], v[i]) == v[i]) {
                mark[i] = 1;
            }
        }
        ll f = 0;
        while (f < s && mark[f]) {
            ++f;
        }
        if (f == s) {
            cout << "YES\n";
            continue;
        }
        ll ans = 1;
        for (ll i = f; i < s; ++i) {
            if (lca(v[f], v[i]) == v[i]) {
                mark[i] = 1;
            }
        }
        for (ll a : mark) {
            ans &= a;
        }
        ans &= depth[lca(v[0], v[f])] <= depth[v[s - 1]];
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}