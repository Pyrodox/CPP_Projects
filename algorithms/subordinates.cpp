#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<vector<ll>> adj(200001);
vector<ll> cnts(200001);

void dfs(ll s, ll e)
{
    ++cnts[e];
    for (ll a : adj[s]) {
        if (a != e) {
            dfs(a, s);
            cnts[s] += cnts[a];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll a;
        cin >> a;
        adj[a].push_back(i + 2);
    }
    dfs(1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << cnts[i] << " ";
    }
}