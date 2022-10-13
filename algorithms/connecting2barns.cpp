#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

vector<vector<ll>> adj(mx), ccs(2);
vector<ll> vis(mx), ccofnode(mx);

void dfs(ll node, ll ccnum)
{
    //cout << "vis: " << node << "\n";
    vis[node] = 1;
    ccofnode[node] = ccnum;
    ccs[ccnum].push_back(node);
    for (ll a : adj[node]) {
        if (!vis[a]) {
            dfs(a, ccnum);
        }
    }
}

int main()
{
    ll n, t, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj = vector<vector<ll>>(mx), ccs = vector<vector<ll>>(2);
        vis = vector<ll>(mx), ccofnode = vector<ll>(mx);
        for (ll i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll ccnum = 2;
        dfs(1, 0);
        if (!vis[n]) {
            dfs(n, 1);
        }
        for (ll i = 2; i <= n; ++i) {
            if (!vis[i]) {
                ccs.push_back({});
                dfs(i, ccnum++);
            }
        }
        if (ccofnode[1] == ccofnode[n]) {
            cout << 0 << "\n";
            continue;
        }
        sort(ccs[0].begin(), ccs[0].end());
        sort(ccs[1].begin(), ccs[1].end());
        /*for (ll a : ccs[0]) {
            cout << a << ", ";
        }
        cout << "\n";
        for (ll a : ccs[1]) {
            cout << a << ", ";
        }
        cout << "\n";*/
        ll ans = 1e18;
        for (ll i = 2; i < ccs.size(); ++i) {
            ll minccs1 = 1e18, minccsn = 1e18; 
            for (ll a : ccs[i]) {
                auto it1 = lower_bound(ccs[0].begin(), ccs[0].end(), a);
                if (it1 == ccs[0].end()) {
                    minccs1 = min(minccs1, abs(a - ccs[0][it1 - ccs[0].begin() - 1]));
                }
                else {
                    ll minval = min(abs(a - ccs[0][it1 - ccs[0].begin() - 1]), abs(a - ccs[0][it1 - ccs[0].begin()]));
                    minccs1 = min(minccs1, minval);
                }
                auto it2 = lower_bound(ccs[1].begin(), ccs[1].end(), a);
                if (it2 == ccs[1].begin()) {
                    minccsn = min(minccsn, abs(a - ccs[1][0]));
                }
                else {
                    ll minval = min(abs(a - ccs[1][it2 - ccs[1].begin() - 1]), abs(a - ccs[1][it2 - ccs[1].begin()]));
                    minccsn = min(minccsn, minval);
                }
            }
            ans = min(ans, minccs1 * minccs1 + minccsn * minccsn);
        }
        for (ll a : ccs[1]) {
            auto it = lower_bound(ccs[0].begin(), ccs[0].end(), a);
            if (it == ccs[0].end()) {
                ans = min(ans, (a - ccs[0][it - ccs[0].begin() - 1]) * (a - ccs[0][it - ccs[0].begin() - 1]));
            }
            else {
                ll minval = min((a - ccs[0][it - ccs[0].begin() - 1]) * (a - ccs[0][it - ccs[0].begin() - 1]), (a - ccs[0][it - ccs[0].begin()]) * (a - ccs[0][it - ccs[0].begin()]));
                ans = min(ans, minval);
            }
        } 
        cout << ans << "\n";
    }
}