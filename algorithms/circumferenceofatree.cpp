#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 3e5 + 1;

ll n, endpoint = 1, mxcount = 0;
vector<vector<ll>> adj(mx);

ll dfs(ll node, ll e, ll cnt)
{
    for (ll a : adj[node]) {
        if (a == e) {
            continue;
        }
        if (cnt + 1 > mxcount) {
            endpoint = a;
            mxcount = cnt + 1;
        }
        dfs(a, node, cnt + 1);
    }

    return cnt;
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
    dfs(1, 0, 0);
    ll node1 = endpoint;
    endpoint = 1;
    dfs(node1, 0, 0);
    cout << 3 * mxcount;
}