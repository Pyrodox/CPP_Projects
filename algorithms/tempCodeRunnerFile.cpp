#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 801;
ll n, s, startr, startc, endr, endc;

vector<vector<char>> grid(mx, vector<char>(mx));
vector<pair<ll, ll>> bees;
vector<vector<ll>> beevis(mx, vector<ll>(mx, -1));

void bfs()
{
    queue<vector<ll>> que;
    que.push({startr, startc, 0, mx * mx});
    vector<vector<ll>> depth(mx, vector<ll>(mx, -1));
    depth[startr][startc] = mx * mx;
    ll ans = -1;
    auto check = [&](ll newx, ll newy, ll truemoves, ll keepmin)
    {
        if (newx < n && newx >= 0 && newy < n && newy >= 0 && grid[newx][newy] != 'T' && 
        (grid[newx][newy] == 'D' || (truemoves / s + 1 <= beevis[newx][newy] && (truemoves + 1) % s) || (truemoves / s + 1 < beevis[newx][newy] && (truemoves + 1) % s == 0))) {
            ll dif = beevis[newx][newy] - (truemoves / s + 1);
            if (grid[newx][newy] == 'D') {
                dif = mx * mx;
            }
            ll a = min(keepmin, dif);
            if (grid[newx][newy] == 'D' || dif > depth[newx][newy] || depth[newx][newy] == -1) {
                if (grid[newx][newy] != 'D') {
                    que.push({newx, newy, truemoves + 1, a});
                }
                else {
                    ans = max(ans, a);
                }
                depth[newx][newy] = dif;
            }
        }
    };
    while (que.size()) {
        ll x = que.front()[0], y = que.front()[1], truemoves = que.front()[2], keepmin = que.front()[3];
        //cout << x << " " << y << " " << truemoves << " " << keepmin << "\n";
        que.pop();
        check(x + 1, y, truemoves, keepmin);
        check(x - 1, y, truemoves, keepmin);
        check(x, y + 1, truemoves, keepmin);
        check(x, y - 1, truemoves, keepmin);
    }
    cout << ans;
}

void floodfill(ll r, ll c, ll fillval)
{
    if (r < 0 || r >= n || c < 0 || c >= n || (beevis[r][c] <= fillval && fillval && beevis[r][c] != -1) || grid[r][c] == 'T' || grid[r][c] == 'D') {
        return;
    }
    beevis[r][c] = fillval;
    floodfill(r - 1, c, fillval + 1);
    floodfill(r + 1, c, fillval + 1);
    floodfill(r, c - 1, fillval + 1);
    floodfill(r, c + 1, fillval + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                startr = i;
                startc = j;
            }
            else if (grid[i][j] == 'D') {
                endr = i;
                endc = j;
            }
            else if (grid[i][j] == 'H') {
                bees.push_back({i, j});
                beevis[i][j] = 0;
            }
        }
    }
    for (ll i = 0; i < bees.size(); ++i) {
        floodfill(bees[i].first, bees[i].second, 0);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            //cout << beevis[i][j] << " ";
        }
        //cout << "\n";
    }
    bfs();
}