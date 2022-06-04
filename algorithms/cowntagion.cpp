#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n;
vector<vector<ll>> adj(mx);

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
    ll ans = 0;
    adj[1].push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() > 1) {
            ans += ceil(log(adj[i].size() - 1) / log(2)) + adj[i].size();
            if (log(adj[i].size() - 1) / log(2) != floor(log(adj[i].size() - 1) / log(2))) {
                --ans;
            }
        }
    }
    cout << ans;
}