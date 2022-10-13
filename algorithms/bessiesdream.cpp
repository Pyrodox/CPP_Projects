#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e3 + 1;

ll n, m;
vector<vector<ll>> grid(mx, vector<ll>(mx));
vector<ll> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

bool inbound(ll x, ll y, ll orangescent)
{
    return x < n && x >= 0 && y < m && y >= 0 && grid[x][y] && (orangescent || !orangescent && grid[x][y] != 3);
}

pair<ll, ll> traverse(ll i, ll xa, ll ya)
{
    if (i == 0) {
        ++ya;
    }
    else if (i == 1) {
        ++xa;
    }
    else if (i == 2) {
        --ya;
    }
    else {
        --xa;
    }

    return {xa, ya};
}

ll bfs()
{
    queue<vector<ll>> que;
    vector<vector<vector<ll>>> depth(mx, vector<vector<ll>>(mx, vector<ll>(4, -1)));
    que.push({0, 0, 0}); //starting x, starting y, if smells like oranges
    depth[0][0][0] = 0;
    depth[n - 1][m - 1][0] = 1e9;
    depth[n - 1][m - 1][1] = 1e9;
    while (que.size()) {
        ll x = que.front()[0], y = que.front()[1], iforange = que.front()[2];
        que.pop();  
        if (x == n - 1 && y == m - 1) {
            break;
        }
        for (ll i = 0; i < 4; ++i) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (inbound(nx, ny, iforange)) {
                if (grid[nx][ny] == 1 && (depth[nx][ny][iforange] == -1 || depth[x][y][iforange] + 1 < depth[nx][ny][iforange])) {
                    depth[nx][ny][iforange] = depth[x][y][iforange] + 1;
                    que.push({nx, ny, iforange}); 
                }
                else if (grid[nx][ny] == 2 && (depth[nx][ny][1] == -1 || depth[x][y][iforange] + 1 < depth[nx][ny][1])) {
                    depth[nx][ny][1] = depth[x][y][iforange] + 1;
                    que.push({nx, ny, 1});
                }
                else if (grid[nx][ny] == 3 && (depth[nx][ny][1] == -1 || depth[x][y][iforange] + 1 < depth[nx][ny][1])) {
                    depth[nx][ny][1] = depth[x][y][iforange] + 1;
                    que.push({nx, ny, 1});
                }
                else if (grid[nx][ny] == 4 && (depth[nx][ny][i] == -1 || depth[x][y][iforange] + 1 < depth[nx][ny][i])) {
                    ll xa = 0, ya = 0;
                    while (inbound(nx + traverse(i, xa, ya).first, ny + traverse(i, xa, ya).second, 0)) {
                        xa = traverse(i, xa, ya).first, ya = traverse(i, xa, ya).second;
                        if (grid[nx + xa][ny + ya] != 4) {
                            break;
                        }
                    }
                    depth[nx][ny][i] = depth[x][y][iforange] + 1;
                    ll ab = (grid[nx + xa][ny + ya] == 2);
                    if (depth[nx + xa][ny + ya][ab] == -1 || depth[x][y][iforange] + xa + ya + 1 < depth[nx + xa][ny + ya][ab]) {
                        depth[nx + xa][ny + ya][ab] = depth[x][y][iforange] + xa + ya + 1; 
                        que.push({nx + xa, ny + ya, ab});
                    }
                }
            }
        }
    }
    if (depth[n - 1][m - 1][0] == 1e9 && depth[n - 1][m - 1][1] == 1e9) {
        return -1;
    }
    return min(depth[n - 1][m - 1][0], depth[n - 1][m - 1][1]);
}

int main()
{
    //ifstream cin("dream.in");
    //ofstream cout("dream.out");
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << bfs();
}