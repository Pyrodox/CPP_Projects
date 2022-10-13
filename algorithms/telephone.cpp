#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 5e4 + 1;

ll n, k;
vector<ll> seq;
vector<vector<ll>> adj(51), grid(51, vector<ll>(51));

void bfs()
{
    queue<ll> que;
    que.push(1);
    vector<ll> depth(mx, -1);
    depth[1] = 0;
    while (que.size()) {
        ll x = que.front();
        que.pop();
        for (ll j = 1; j <= k; ++j) {
            if (grid[seq[x - 1]][j]) {
                for (ll i = 0; i < adj[j].size(); ++i) {
                    if (adj[j][i] - x != 0 && (depth[adj[j][i]] == -1 || abs(adj[j][i] - x) + depth[x] < depth[adj[j][i]])) {
                        if (adj[j][i] != n && adj[j][i] != 1) {
                            que.push(adj[j][i]);
                        }
                        depth[adj[j][i]] = abs(adj[j][i] - x) + depth[x];
                    }
                }
            }
        }
    }
    cout << depth[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        seq.push_back(a);
    }
    for (ll i = 1; i <= k; ++i) {
        string s;
        cin >> s;
        for (ll j = 0; j < k; ++j) {
            grid[i][j + 1] = s[j] - '0';
        }
    }
    for (ll i = 0; i < n; ++i) {
        adj[seq[i]].push_back(i + 1);
    }
    bfs();
}