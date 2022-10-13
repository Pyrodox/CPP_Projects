#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 501;

ll n, m, startx, starty, endx, endy;
vector<vector<char>> grid(mx, vector<char>(mx));
vector<vector<vector<ll>>> gflip(2, vector<vector<ll>>(mx, vector<ll>(mx))), dropdown(mx, vector<vector<ll>>(mx, vector<ll>(2))); //gflip[1][x][y] is downward gravity, gflip[0][x][y] is upward gravity
vector<vector<vector<ll>>> depth(mx, vector<vector<ll>>(mx, vector<ll>(2, -1)));

ll calcgflip(ll x, ll y, ll g, bool actualflip) {
    ll ogx = x;
    if (g) {
        while (x && grid[x][y] != '#') {
            if (grid[x][y] == 'D' && actualflip) {
                depth[x][y][0] = min(min(depth[x][y][1], depth[x][y][0]), depth[ogx][y][g] + 1); 
            }
            else if (grid[x][y] == 'D' && !actualflip) {
                depth[x][y][0] = min(min(depth[x][y][1], depth[x][y][0]), depth[ogx][y][g]); 
            }
            --x;
        }
        ++x;
    }
    else {
        while (x <= n && grid[x][y] != '#') {
            if (grid[x][y] == 'D' && actualflip) {
                depth[x][y][0] = min(min(depth[x][y][1], depth[x][y][0]), depth[ogx][y][g] + 1); 
            }
            else if (grid[x][y] == 'D' && !actualflip) {
                depth[x][y][0] = min(min(depth[x][y][1], depth[x][y][0]), depth[ogx][y][g]); 
            }
            ++x;
        }
        --x;
    }
    if ((g == 1 && x == 1 && grid[1][y] != '#') || (g == 0 && x == n && grid[n][y] != '#')) {
        return -1;
    }

    return x;
}

ll bfs()
{
    queue<vector<ll>> que;
    que.push({startx, starty, 1});
    depth[startx][starty][1] = 0;
    depth[endx][endy][0] = 1e9;
    depth[endx][endy][1] = 1e9;
    while (que.size()) {
        ll x = que.front()[0], y = que.front()[1], g = que.front()[2];
        que.pop();
        ll newx = dropdown[x][y][g];
        if (!dropdown[x][y][g]) {
            newx = calcgflip(x, y, !g, 0);
            dropdown[x][y][g] = newx;
        }
        if (dropdown[x][y][g] != -1) {
            depth[newx][y][g] = depth[x][y][g];
            ll gx = gflip[g][newx][y];
            if (!gflip[g][newx][y]) {
                gx = calcgflip(newx, y, g, 1);
                gflip[g][newx][y] = gx; 
            }
            if (gflip[g][newx][y] != -1 && (depth[gx][y][!g] == -1 || depth[newx][y][g] + 1 < depth[gx][y][!g])) {
                que.push({gx, y, !g});
                depth[gx][y][!g] = depth[newx][y][g] + 1;
            }
            if (y - 1 >= 1 && grid[newx][y - 1] != '#' && (depth[newx][y - 1][g] == -1 || depth[newx][y][g] < depth[newx][y - 1][g])) {
                que.push({newx, y - 1, g});
                depth[newx][y - 1][g] = depth[newx][y][g];
            }
            if (y + 1 <= m && grid[newx][y + 1] != '#' && (depth[newx][y + 1][g] == -1 || depth[newx][y][g] < depth[newx][y + 1][g])) {
                que.push({newx, y + 1, g});
                depth[newx][y + 1][g] = depth[newx][y][g];
            }
        }
    }
    ll ans = min(depth[endx][endy][1], depth[endx][endy][0]);
    if (ans != 1e9) {
        return ans;
    }
    else {
        return -1;
    }
}

int main()
{
    ifstream cin("gravity.in");
    ofstream cout("gravity.out");
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (ll j = 1; j <= m; ++j) {
            grid[i][j] = s[j - 1];
            if (s[j - 1] == 'C') {
                startx = i;
                starty = j;
            }
            else if (s[j - 1] == 'D') {
                endx = i;
                endy = j;
            }
        }
    }
    cout << bfs();
}