#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n;
vector<vector<ll>> adj(mx);
vector<ll> mx1(mx), dir(mx), mx2(mx), parent(mx), ansv(mx);

ll dfs(ll s, ll e)
{
    ll cnt = 0;
    parent[s] = e;
    for (ll a : adj[s]) {
        if (a != e) {
            ll b = dfs(a, s);
            if (b > cnt) {
                cnt = b;
                dir[s] = a;
            }
        }
    }
    mx1[s] = cnt;

    return ++cnt;
}

void dfs2(ll s, ll e)
{
    for (ll a : adj[s]) {
        if (a != e) {
            if (a != dir[s]) {
                mx2[s] = max(mx2[s], mx1[a] + 1);
            }
            dfs2(a, s);
        }
    }
}

void allocate(ll s, vector<ll>& v)
{
    if (v[parent[s]] + 1 >= mx1[s]) {
        ansv[s] = v[parent[s]] + 1;
        dir[s] = parent[s];
        mx2[s] = mx1[s];
    }
    else {
        ansv[s] = mx1[s];
        mx2[s] = max(mx2[s], v[parent[s]] + 1);
    }
}

void dfs3(ll s, ll e)
{
    if (s == 1) {
        ansv[1] = mx1[1];
    }
    else {
        if (dir[parent[s]] == s) {
            allocate(s, mx2);
        }
        else {
            allocate(s, mx1);
        }
        mx1[s] = ansv[s];
    }
    for (ll a : adj[s]) {
        if (a != e) {
            dfs3(a, s);
        }
    }
}

int main()
{
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
    dfs2(1, 0);
    dfs3(1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << ansv[i] << " ";
    }
}