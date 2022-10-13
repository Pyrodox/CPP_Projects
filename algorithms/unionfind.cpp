#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n, q;
vector<ll> check(mx, -1);
vector<vector<ll>> dsu;

int main()
{
    cin >> n >> q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (q--) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << (u == v || check[u] >= 0 && check[u] == check[v]) << "\n";
        }
        else {
            if (check[u] == -1 && check[v] == -1) {
                check[u] = dsu.size();
                check[v] = dsu.size();
                if (u == v) {
                    dsu.push_back({u});
                }
                else {
                    dsu.push_back({u, v});
                }
            }
            else if (check[u] == -1) {
                dsu[check[v]].push_back(u);
                check[u] = check[v];
            }
            else if (check[v] == -1) {
                dsu[check[u]].push_back(v);
                check[v] = check[u];
            }
            else if (check[u] != check[v]) {
                if (check[u] > check[v]) {
                    ll tmpv = v;
                    v = u;
                    u = tmpv;
                }
                ll tmp = dsu[check[v]].size();
                ll tmpcheck = check[v];
                for (ll i = 0; i < tmp; ++i) {
                    dsu[check[u]].push_back(dsu[tmpcheck][i]);
                    check[dsu[tmpcheck][i]] = check[u];
                }
                dsu[tmpcheck] = {};
            }
        }
    }
}