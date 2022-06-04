#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n;
long double dist = 0;
vector<vector<ll>> adj(mx);

void dfs(ll node, ll e, ll cnt, long double based)
{
    ll tmp = 0;
    if (e) {
        ++cnt;
    }
    for (ll a : adj[node]) {
        if (a != e) {
            ++tmp;
            if (e) {
                dfs(a, node, cnt, based / (adj[node].size() - 1));
            }
            else {
                dfs(a, node, cnt, based / adj[node].size());
            }
        }
    }
    if (!tmp) {
        dist += cnt * based;
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
    dfs(1, 0, 0, 1);
    cout << setprecision(7) << (double) dist;
}