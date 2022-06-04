#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e2 + 1;

ll n, k, r, cnt;
vector<vector<bool>> grid(mx, vector<bool>(mx));
vector<vector<vector<bool>>> roads(mx, vector<vector<bool>>(mx, vector<bool>(4)));
vector<vector<bool>> vis(mx, vector<bool>(mx)), permavis(mx, vector<bool>(mx));
vector<ll> pairs;

void floodfill(ll r, ll c)
{
    if (r < 1 || r > n || c < 1 || c > n || vis[r][c] || permavis[r][c]) {
        return;
    }
    if (grid[r][c]) {
        ++cnt;
        permavis[r][c] = true;
    }
    vis[r][c] = true;
    if (!roads[r][c][3]) {
        floodfill(r - 1, c);
    }
    if (!roads[r][c][2]) {
        floodfill(r + 1, c);
    }
    if (!roads[r][c][1]) {
        floodfill(r, c - 1);
    }
    if (!roads[r][c][0]) {
        floodfill(r, c + 1);
    }
}

int main()
{
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");
    fin >> n >> k >> r;
    for (ll i = 0; i < r; ++i) {
        ll a, b, c, d;
        fin >> a >> b >> c >> d;
        if (d > b) {
            roads[a][b][0] = true;
            roads[c][d][1] = true;
        }
        else if (b > d) {
            roads[a][b][1] = true;
            roads[c][d][0] = true;
        }
        else if (a < c) {
            roads[a][b][2] = true;
            roads[c][d][3] = true;
        }
        else {
            roads[a][b][3] = true;
            roads[c][d][2] = true;
        }
    }
    for (ll i = 0; i < k; ++i) {
        ll a, b;
        fin >> a >> b;
        grid[a][b] = true;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (grid[i][j] && !permavis[i][j]) {
                cnt = 0;
                floodfill(i, j);
                vis = vector<vector<bool>>(mx, vector<bool>(mx));
                pairs.push_back(cnt);
            }
        }
    }
    ll ans = 0, k2 = k;
    for (ll i = 0; i < pairs.size(); ++i) {
        k2 -= pairs[i];
        ans += pairs[i] * k2;
    }
    fout << ans;
}