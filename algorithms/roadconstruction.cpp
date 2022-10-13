#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n, m, ans1, ans2 = 0, szval = 0;
vector<ll> parent(mx, -1), szv(mx, 1);

pair<ll, ll> findp(ll a, ll sz)
{
    if (a != parent[a]) {
        auto val = findp(parent[a], sz);
        parent[a] = val.first;
    }

    return {parent[a], 0};
}

void unite(ll u, ll v)
{
    ll roota = findp(u, 1).first, rootb = findp(v, 1).first;
    if (roota != rootb) {
        --ans1;
    }
    else {
        return;
    }
    if (rand() % 2) {
        swap(roota, rootb);
    }
    parent[rootb] = roota;
    szv[roota] += szv[rootb];
    ans2 = max(ans2, szv[roota]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ans1 = n;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        if (parent[u] < 0) {
            parent[u] = u;
        }
        if (parent[v] < 0) {
            parent[v] = v;
        }
        unite(u, v);
        cout << ans1 << " " << ans2 << "\n";
    }
}