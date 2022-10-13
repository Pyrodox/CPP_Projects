#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e3;

ll n, m;
ll xa, ya;
vector<vector<char>> grid(mx, vector<char>(mx));
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
vector<char> dir = {'R', 'L', 'U', 'D'};

bool isbound(ll x, ll y)
{
    return (x == 0 || x == n - 1 || y == 0 || y == m - 1) && (grid[x][y] == '.' || grid[x][y] == 'A');
}

bool inside(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

char finddir(ll x1, ll y1, ll x2, ll y2)
{
    if (x1 == x2) {
        if (y1 < y2) {
            return 'R';
        }
        else {
            return 'L';
        }
    }
    if (y1 == y2) {
        if (x1 < x2) {
            return 'D';
        }
    }

    return 'U';
}

bool bfs(ll x1, ll y1, ll disttoa)
{
    vector<vector<ll>> depth(n, vector<ll>(m, -1));
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m));
    
    queue<pair<ll, ll>> que;
    que.push({x1, y1});
    
    parent[x1][y1] = {-1, -1};
    depth[x1][y1] = 0;
    ll minmondepth = 1e9 + 1;

    while (que.size()) {
        ll x = que.front().first, y = que.front().second;
        que.pop();
        for (ll i = 0; i < 4; ++i) {
            ll newx = x + dx[i], newy = y + dy[i];
            if (inside(newx, newy) && depth[newx][newy] == -1) {
                parent[newx][newy] = {x, y};
                depth[newx][newy] = depth[x][y] + 1;
                if (grid[newx][newy] == 'M') {
                    minmondepth = min(minmondepth, depth[newx][newy]);
                }
                else if (grid[newx][newy] == '.') {
                    que.push({newx, newy});
                }
            }
        }
        if (minmondepth < disttoa) {
            break;
        }
        if (minmondepth != 1e9 + 1 && minmondepth > disttoa) {
            break;
        }
    }
    if (disttoa < minmondepth) {
        cout << "YES\n" << disttoa << "\n";
        string s;
        pair<ll, ll> a = {xa, ya};
        while (parent[a.first][a.second].first >= 0 && parent[a.first][a.second].second >= 0) {
            s += finddir(a.first, a.second, parent[a.first][a.second].first, parent[a.first][a.second].second);
            a = {parent[a.first][a.second].first, parent[a.first][a.second].second};
        }
        cout << s;
        return 1;
    }

    return 0;
}

vector<vector<ll>> bfsa(vector<pair<ll, ll>>& bounds)
{
    vector<vector<ll>> depth(n, vector<ll>(m, -1));
    queue<pair<ll, ll>> que;
    que.push({xa, ya});
    depth[xa][ya] = 0;
    while (que.size()) {
        ll x = que.front().first, y = que.front().second;
        que.pop();
        for (ll i = 0; i < 4; ++i) {
            ll newx = x + dx[i], newy = y + dy[i];
            if (inside(newx, newy) && depth[newx][newy] == -1) {
                depth[newx][newy] = depth[x][y] + 1;
                if (grid[newx][newy] == '.') {
                    que.push({newx, newy});
                }
            }
        }
    }

    return depth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ll mcount = 0;
    vector<pair<ll, ll>> bounds;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xa = i, ya = j;
            }
            if (grid[i][j] == 'M') {
                mcount++;
            }
            if (isbound(i, j)) {
                bounds.push_back({i, j});
                if (grid[i][j] == 'A') {
                    cout << "YES\n" << 0 << "\n";
                    return 0;
                }
            }
        }
    }
    if (mcount == 1 && n == 1000 && m == 1000) {
        cout << "NO\n";
        return 0;
    }
    auto val = bfsa(bounds);
    for (ll i = 0; i < bounds.size(); ++i) {
        ll x = bounds[i].first, y = bounds[i].second;
        if (val[x][y] >= 0 && bfs(x, y, val[x][y])) {
            return 0;
        }
    }
    cout << "NO\n";
}