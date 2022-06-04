#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, m, cnt = 1;
string cows;
vector<pair<vector<ll>, ll>> adj(mx);
vector<bool> vis(mx);

void dfs(ll s, ll e, char c)
{
    adj[s].second = cnt;
    vis[s] = true;
    for (ll a : adj[s].first) {
        if (a != e && cows[a - 1] == c) {
            dfs(a, s, c);
        }
    }
}

int main()
{
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m >> cows;
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].first.push_back(b);
        adj[b].first.push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 0, cows[i - 1]);
            ++cnt;
        }
    }   
    string ans = "";
    while (m--) {
        ll a, b;
        char c;
        cin >> a >> b >> c;
        if (adj[a].second != adj[b].second || cows[a - 1] == c) {
            ans += "1";
        }
        else {
            ans += "0";
        }
    }
    cout << ans;
}