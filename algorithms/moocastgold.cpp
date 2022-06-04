#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, mid, visamount;
vector<pair<ll, ll>> adj(1001);

void dfs(ll node, vector<bool>& vis)
{
    ++visamount;
    vis[node] = true;
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i] && pow(adj[i].first - adj[node].first, 2) + pow(adj[i].second - adj[node].second, 2) <= mid) {
            dfs(i, vis);
        }
    }
}

int main()
{
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    for (ll i = 1; i <= n; ++i) {
        ll a, b;
        fin >> a >> b;
        adj[i] = {a, b};
    }
    ll l = 0, r = 2 * 25000 * 25000;
    while (l < r) {
        mid = l + (r - l) / 2;
        visamount = 0;
        vector<bool> vis(n + 1);
        dfs(1, vis);
        if (visamount < n) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    fout << l;
}