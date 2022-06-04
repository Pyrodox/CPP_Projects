#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> grid(1000, vector<ll>(1000));
vector<vector<bool>> vis(1000, vector<bool>(1000));
ll n, m;

void floodfill(ll r, ll c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != '.' || vis[r][c]) {
        return;
    }
    vis[r][c] = true;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == '.') {
                floodfill(i, j);
                ++ans;
            }
        }
    }
    cout << ans;
}