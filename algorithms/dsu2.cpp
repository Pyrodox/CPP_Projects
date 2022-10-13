#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 3e5 + 1;

ll n, m, mxval = 0, mnval = mx;
vector<ll> parent(mx), szv(mx, 1), minv(mx), maxv(mx);

ll findroot(ll x)
{
    mxval = max(mxval, x);
    mnval = min(mnval, x);
    if (parent[x] != x) {
        parent[x] = findroot(parent[x]);
    }
    minv[parent[x]] = min(minv[parent[x]], mnval);
    maxv[parent[x]] = max(maxv[parent[x]], mxval);

    return parent[x];
}

void unite(ll u, ll v)
{
    ll roota = findroot(u), rootb = findroot(v);
    if (rand() % 2) {
        swap(roota, rootb);
    }
    parent[rootb] = roota;
    //cout << "root: " << roota << " " << minv[rootb] << " " << minv[roota] << "\n";
    minv[roota] = min(minv[rootb], minv[roota]);
    maxv[roota] = max(maxv[rootb], maxv[roota]);
    szv[roota] += szv[rootb];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        string s;
        ll u, v;
        mxval = 0, mnval = mx;
        cin >> s >> u;
        if (s == "union") {
            cin >> v;
            if (!parent[u]) {
                parent[u] = u;
            }
            if (!parent[v]) {
                parent[v] = v;
            }
            if (!minv[u]) {
                minv[u] = u;
            }
            if (!maxv[u]) {
                maxv[u] = u;
            }
            if (!minv[v]) {
                minv[v] = v;
            }
            if (!maxv[v]) {
                maxv[v] = v;
            }
            if (findroot(parent[u]) != findroot(parent[v]))
            unite(u, v);
        }
        else {
            if (!minv[u]) {
                minv[u] = u;
            }
            if (!maxv[u]) {
                maxv[u] = u;
            }
            if (!parent[u]) {
                parent[u] = u;
            }
            ll par = findroot(u);
            //cout << par << " p\n";
            cout << minv[par] << " " << maxv[par] << " " << szv[par] << "\n";
        }
    }
}