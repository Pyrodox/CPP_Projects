#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 501;

ll n, m, wpreach;
vector<vector<pair<ll, ll>>> grid(mx, vector<pair<ll, ll>>(mx));
vector<vector<bool>> vis;

void floodfill(ll r, ll c, ll d)
{
    if (r < 1 || r > m || c < 1 || c > n || vis[r][c]) {
        return;
    }
    vis[r][c] = true;
    if (grid[r][c].second) {
        ++wpreach;
    }
    if (abs(grid[r][c].first - grid[r - 1][c].first) <= d) {
        floodfill(r - 1, c, d);
    } 
    if (r + 1 <= m && abs(grid[r][c].first - grid[r + 1][c].first) <= d) {
        floodfill(r + 1, c, d);
    }
    if (abs(grid[r][c].first - grid[r][c - 1].first) <= d) {
        floodfill(r, c - 1, d);
    }
    if (c + 1 <= n && abs(grid[r][c].first - grid[r][c + 1].first) <= d) {
        floodfill(r, c + 1, d);
    }
}

int main()
{
    ifstream fin("ccski.in");
    ofstream fout("ccski.out");
    fin >> m >> n;
    ll lowelv = 1e9, highelv = 0;
    for (ll i = 1; i <= m; ++i) {
        for (ll j = 1; j <= n; ++j) {
            fin >> grid[i][j].first;
            lowelv = min(lowelv, grid[i][j].first);
            highelv = max(highelv, grid[i][j].first);
        }
    }
    ll wpr, wpc, wpcount = 0;
    for (ll i = 1; i <= m; ++i) {
        for (ll j = 1; j <= n; ++j) {
            fin >> grid[i][j].second;
            if (grid[i][j].second) {
                wpr = i, wpc = j;
                ++wpcount;
            }
        }
    }
    ll l = 0, r = highelv - lowelv;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        wpreach = 0;
        vis = vector<vector<bool>>(m + 1, vector<bool>(n + 1));
        floodfill(wpr, wpc, mid);
        if (wpreach < wpcount) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    fout << l;
}