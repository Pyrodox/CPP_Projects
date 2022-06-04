#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5;

vector<set<ll>> adj(mx + 1);
set<ll> unvis;
vector<ll> components(mx + 1);
ll cur = 0;

void dfs(ll node)
{
    components[cur]++;
    unvis.erase(node);
    auto it = unvis.begin();
    while (it != unvis.end()) {
        if (adj[node].find(*it) != adj[node].end()) {
            ++it;
        }
        else {
            ll x = *it;
            dfs(x);
            it = unvis.upper_bound(x);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (ll i = 1; i <= n; ++i) {
        unvis.insert(i);
    }
    for (ll i = 1; i <= n; ++i) {
        if (unvis.find(i) != unvis.end()) {
            ++cur;
            dfs(i);
        }
    }
    sort(components.begin() + 1, components.begin() + cur + 1);
    cout << cur << "\n";
    for (ll i = 1; i <= cur; ++i) {
        cout << components[i] << " ";
    }
}