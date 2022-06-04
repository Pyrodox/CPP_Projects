#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n, max1 = 0, mxnode1;
vector<vector<ll>> adj(mx);

void dfs(ll node, ll e, ll cnt)
{
    if (cnt > max1) {
        mxnode1 = node;
        max1 = cnt;
    }
    for (ll a : adj[node]) {
        if (a != e) {
            dfs(a, node, cnt + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfs(mxnode1, 0, 0);
    cout << max1;
}