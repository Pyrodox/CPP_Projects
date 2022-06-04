#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 101;

ll n, m, ans = 1, cnt = 1, c = 1, d = 1;
vector<vector<vector<pair<ll, ll>>>> grid(mx, vector<vector<pair<ll, ll>>>(mx));
vector<vector<bool>> vis(mx, vector<bool>(mx)), lighton(mx, vector<bool>(mx));
vector<vector<bool>> permavis(mx, vector<bool>(mx));
bool flag = true;

void floodfill(ll r, ll c)
{
    if (r < 1 || r > n || c < 1 || c > n || vis[r][c] || permavis[r][c] || !lighton[r][c]) {
        return;
    }
    if ((r - 1 < 1 || vis[r - 1][c]) && (c - 1 < 1 || vis[r][c - 1]) && (r + 1 > n || vis[r + 1][c]) && (c + 1 > n || (vis[r][c + 1]))) {
        permavis[r][c] = true;
    }
    vis[r][c] = true;
    for (ll i = 0; i < grid[r][c].size(); ++i) {
        if (!lighton[grid[r][c][i].first][grid[r][c][i].second]) {
            lighton[grid[r][c][i].first][grid[r][c][i].second] = true;
            ++ans;
            ++cnt;
        }
    }
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main()
{
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    fin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll x, y, a, b;
        fin >> x >> y >> a >> b;
        grid[x][y].push_back({a, b});
    }
    lighton[1][1] = true;
    while (cnt >= 0) {
        floodfill(c, d);
        vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
        cnt -= 3;
    }
    fout << ans;
}