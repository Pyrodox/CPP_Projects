#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 4e3;

ll n, m;
vector<string> snow(mx);

bool inside(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m && snow[x][y] != '.';
}

int main()
{
    vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        cin >> snow[i];
    }
    deque<pair<ll, ll>> que;
    que.push_back({0, 0});
    ll ans = 1;
    vector<vector<ll>> depth(mx, vector<ll>(mx));
    depth[0][0] = 1;
    while (que.size()) {
        auto u = que.front();
        ll x = u.first, y = u.second;
        que.pop_front();
        ans = max(ans, depth[x][y]);
        for (ll i = 0; i < 4; ++i) {
            if (inside(x + dx[i], y + dy[i]) && !depth[x + dx[i]][y + dy[i]]) {
                if (snow[x][y] == snow[x + dx[i]][y + dy[i]]) {
                    que.push_front({x + dx[i], y + dy[i]});
                    depth[x + dx[i]][y + dy[i]] = depth[x][y];
                }
                else {
                    que.push_back({x + dx[i], y + dy[i]});
                    depth[x + dx[i]][y + dy[i]] = depth[x][y] + 1;
                }
            }
        }
    }
    cout << ans;
}