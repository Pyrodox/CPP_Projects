#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<vector<ll>> adj(501), rev(501), sccs;

void dfs1(ll node, vector<bool>& vis, stack<ll>& stc)
{
    vis[node] = true;
    for (ll a : adj[node]) {
        if (!vis[a]) {
            dfs1(a, vis, stc);
        }
    }
    stc.push(node);
}

void reverse()
{
    for (ll i = 1; i <= n; ++i) {
        for (ll j : adj[i]) {
            rev[j].push_back(i);
        }
    }
}

void dfs2(ll node, vector<bool>& vis)
{
    sccs[sccs.size() - 1].push_back(node);
    vis[node] = true;
    for (ll a : rev[node]) {
        if (!vis[a]) {
            dfs2(a, vis);
        }
    }
}

void findsccs()
{
    stack<ll> stck;
    vector<bool> vis(n + 1);
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i, vis, stck);
        }
    }
    reverse();
    for (ll i = 1; i <= n; ++i) {
        vis[i] = false;
    }
    while (!stck.empty()) {
        ll curr = stck.top();
        stck.pop();
        if (!vis[curr]) {
            sccs.push_back({});
            dfs2(curr, vis);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<map<ll, ll>> priocheck(n + 1);
    for (ll i = 1; i <= n; ++i) {
        vector<ll> tmpvec(n + 1);
        for (ll j = 1; j <= n; ++j) {
            cin >> tmpvec[j];
        }
        for (ll j = 1; j <= n; ++j) {
            priocheck[i][tmpvec[j]] = j;
            adj[i].push_back(tmpvec[j]);
            if (tmpvec[j] == i) {
                break;
            }
        }
    }
    findsccs();
    vector<ll> ans(n + 1);
    for (auto val : sccs) {
        for (ll i = 0; i < val.size(); ++i) {
            ll minval = adj[val[i]].size();
            for (ll j = 0; j < val.size(); ++j) {
                ll a = priocheck[val[i]][val[j]];
                if (a <= minval && a != 0) {
                    minval = a;
                }
            }
            ans[val[i]] = minval;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << adj[i][ans[i] - 1] << "\n";
    }
}