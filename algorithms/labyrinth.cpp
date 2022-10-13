#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

ll n, m;
vector<vector<pair<ll, ll>>> adj(mx);
vector<ll> vis(mx), ansvec;
vector<pair<ll, ll>> parent(mx);

void bfs(ll node, ll target)
{
    queue<ll> neq;
    neq.push(node);
    while (neq.size()) {
        vis[neq.front()] = parent[neq.front()].first + 1;
        for (auto a : adj[neq.front()]) {
            if (!vis[a.first]) {
                neq.push(a.first);
                vis[a.first] = 1;
                parent[a.first] = {neq.front(), a.second};
            }
        }
        neq.pop();
    }
    if (!vis[target]) {
        cout << "NO";
    }
    else {
        vector<ll> ans = {target};
        ll a = target;
        while (parent[a].first) {
            ans.push_back(parent[a].second);
            a = parent[a].first;
        }
        cout << "YES\n" << ans.size() - 1 << "\n";
        vector<char> dir = {'0', 'U', 'D', 'R', 'L'};
        for (ll i = ans.size() - 1; i > 0; --i) {
            cout << dir[ans[i]];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    ll start, iter = 1, target;
    vector<vector<ll>> grid2(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] != '#') {
                grid2[i][j] = iter;
                if (grid[i][j] == 'A') {
                    start = iter;
                }
                else if (grid[i][j] == 'B') {
                    target = iter;
                }
                if (i - 1 >= 0 && grid2[i - 1][j]) {
                    adj[grid2[i - 1][j]].push_back({iter, 2});
                    adj[iter].push_back({grid2[i - 1][j], 1});
                }
                if (j - 1 >= 0 && grid2[i][j - 1]) {
                    adj[grid2[i][j - 1]].push_back({iter, 3});
                    adj[iter].push_back({grid2[i][j - 1], 4});
                }
                ++iter;
            }
        }
    }
    bfs(start, target);
}