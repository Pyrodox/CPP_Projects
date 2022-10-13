#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

vector<ll> adj[mx];
ll visited[mx], odd[mx], timer = 1;
vector<pair<ll, ll>> ans;

void dfs(ll node, ll parent = 0)
{
	visited[node] = timer++;
	for (ll a : adj[node]) {
        if (a != parent) {
            if (!visited[a]) {
                dfs(a, node);
                if (odd[a]) {
                    ans.push_back({a, node});
                    odd[a] = false;
                }
                else {
                    ans.push_back({node, a});
                    odd[node] ^= 1;
                }
            }
            else if (visited[node] > visited[a]) {
                ans.push_back({node, a});
                odd[node] ^= 1;
            }
        }
    }
}

int main()
{
	ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int a = 1; a <= n; a++) {
        if (!visited[a]) {
            dfs(a);
        }
    }
	for (ll i = 1; i <= n; ++i) {
        if (odd[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
	for (auto val : ans) {
        cout << val.first << " " << val.second << "\n";
    }
}