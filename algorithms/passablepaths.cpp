#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mx = 2e5 + 1;
 
vector<vector<ll>> adj(mx);
vector<ll> vis(mx), inset(mx), stagecnt(mx), dp(mx);
ll s, cnt = 0, flagstage = 1;
 
void dfs(ll node, ll parent, ll stage)
{
    vis[node] = stage;
    for (ll a : adj[node]) {
        if (a != parent && !vis[a]) {
            dfs(a, node, stage + 1);
        }
    }
}
 
void dfs2(ll node, ll parent, ll stage)
{
    if (stage < flagstage && parent) {
        return;
    }
    if (inset[node]) {
        stagecnt[stage]++;
        ++cnt;
    }
    dp[node] = stage;
    for (ll a : adj[node]) {
        if (adj[node].size() == 1 && a == parent && inset[node]) {
            flagstage = 10000000000000000;
            return;
        }
        if (inset[a] && !dp[a] && a != parent) {
            dfs2(a, node, stage + 1);
            flagstage = max(flagstage, dp[node] + 1);
            return;
        }
        else if (a != parent && !dp[a]) {
            dfs2(a, node, stage + 1);
        }
    }
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
    cin >> q;
    if (n == 1) {
        for (ll i = 0; i < q; ++i) {
            ll a, b;
            cin >> a >> b;
            cout << "YES\n";
        }
        return 0;
    }
    dfs(1, 0, 1);
    ll mxstage = 1;
    while (q--) {
        ll newroot;
        cin >> s;
        for (ll i = 0; i < s; ++i) {
            ll a;
            cin >> a;
            if (vis[a] > mxstage) {
                mxstage = vis[a];
                newroot = a;
            }
            inset[a] = 1;
        }
        dfs2(newroot, 0, 1);
        for (ll i = 1; i <= n; ++i) {
            if (stagecnt[i] > 1) {
                cnt = -1;
                break;
            }
        }
        if (cnt == s) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        dp = vector<ll>(mx), inset = vector<ll>(mx), stagecnt = vector<ll>(mx);
        cnt = 0, mxstage = 1, flagstage = 1;
    }
}