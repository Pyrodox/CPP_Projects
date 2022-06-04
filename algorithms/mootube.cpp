#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 5e3 + 1;

ll n, q, ans = 0;
vector<vector<pair<ll, ll>>> adj(mx);

void dfs(ll s, ll e, ll minrel)
{
    for (auto val : adj[s]) {
        if (val.first == e || val.second < minrel) {
            continue;
        }
        ++ans;
        dfs(val.first, s, minrel);
    }
}

int main()
{
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin >> n >> q;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b, c;
        fin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    while (q--) {
        ll k, v;
        fin >> k >> v;
        dfs(v, 0, k);
        fout << ans << "\n";
        ans = 0;
    }
}