#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5;

ll mid, iter;
vector<vector<ll>> mustconnect;
vector<vector<pair<ll, ll>>> adj(mx + 1);

void dfs(ll node, vector<ll>& connectedcomponentnum, vector<bool>& vis)
{
    vis[node] = true;
    connectedcomponentnum[node] = iter;
    for (auto a : adj[node]) {
        if (a.second >= mid && !vis[a.first]) {
            dfs(a.first, connectedcomponentnum, vis);
        }
    }
}

int main()
{
    ll n, m;
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin >> n >> m;
    vector<ll> incorrectindices;
    for (ll i = 1; i <= n; ++i) {
        ll a;
        fin >> a;
        if (a != i) {
            mustconnect.push_back({a, i});
            incorrectindices.push_back(i);
        }
    }
    if (mustconnect.empty()) {
        fout << -1;
        return 0;
    }
    ll l = 1e9, r = 1;
    for (ll i = 0; i < m; ++i) {
        ll a, b, w;
        fin >> a >> b >> w;
        l = min(l, w);
        r = max(r, w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        iter = 1;
        vector<ll> connectedcomponentnum(n + 1);
        vector<bool> vis(n + 1);
        bool check = true;
        for (ll i = 0; i < incorrectindices.size(); ++i) {
            if (!vis[incorrectindices[i]]) {
                dfs(incorrectindices[i], connectedcomponentnum, vis);
            }
            ++iter;
        }
        for (auto val : mustconnect) {
            if (connectedcomponentnum[val[0]] != connectedcomponentnum[val[1]]) {
                check = false;
                break;
            }
        }
        if (check) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    fout << l;
}