#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, k;
vector<vector<ll>> adj(mx);
queue<pair<ll, ll>> que;
vector<pair<ll, ll>> depth(mx, {0, -1});
set<ll> anss;

void bfs()
{
    while (que.size()) {
        ll x = que.front().first, p = que.front().second;
        que.pop();
        for (ll a : adj[x]) {
            if (a != p && (depth[a].second == -1 || depth[x].second + 1 < depth[a].second)) {
                depth[a] = {depth[x].first, depth[x].second + 1};
                que.push({a, x}); 
            }
        }
    }
}

void bfsk()
{
    while (que.size()) {
        ll x = que.front().first, p = que.front().second;
        que.pop();
        for (ll a : adj[x]) {
            if (a != p && (depth[a].second == -1 || depth[x].second + 1 < depth[a].second)) {
                depth[a] = {depth[x].first, depth[x].second + 1};
                que.push({a, x}); 
            }
            else if (a != p) {
                //cout << a << " depths: " << depth[a].first << " " << depth[a].second << "\n";
                anss.insert(depth[a].first);
            }
        }
    }
}

int main()
{
    ifstream cin("atlarge.in");
    ofstream cout("atlarge.out");
    cin >> n >> k;
    depth[k] = {k, 0};
    vector<ll> appearances(mx);
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        appearances[a]++;
        appearances[b]++;
    }
    for (ll i = 1; i <= n; ++i) {
        if (appearances[i] == 1) {
            if (i == k) {
                cout << 1; return 0;
            }
            que.push({i, 0});
            depth[i] = {i, 0};
        }
    }
    bfs();
    que.push({k, 0});
    bfsk();
    /*for (ll a : anss) {
        cout << a << " ";
    }
    cout << "\n";*/
    cout << anss.size();
}