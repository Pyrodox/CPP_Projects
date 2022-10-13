#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

vector<ll> parent(mx), vis(mx);
ll n, q;

ll findparent(ll a)
{
    if (parent[a] != a) {
        parent[a] = findparent(parent[a]);
    }

    return parent[a];
}

ll find(ll u, ll v)
{
    return findparent(u) == findparent(v);
}


void unite(ll u, ll v)
{
    ll roota = findparent(u), rootb = findparent(v);
    if (rand() % 2) {
        parent[rootb] = roota;
    }
    else {
        parent[roota] = rootb;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    while (q--) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (!vis[u]) {
            parent[u] = u;
        }
        if (!vis[v]) {
            parent[v] = v;
        }
        if (t) {
            cout << find(u, v) << "\n";
        } 
        else {
            vis[u] = 1, vis[v] = 1;
            unite(u, v);
        }
    }
}