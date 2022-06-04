#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 52;

ll n, m, goodvisit;
vector<vector<char>> grid(mx, vector<char>(mx));
vector<vector<bool>> vis(mx, vector<bool>(mx));
bool flag;

void floodfill(ll r, ll c)
{
    if (r < 1 || r > n || c < 1 || c > m || grid[r][c] == '#' || vis[r][c]) {
        return;
    }
    if (grid[r][c] == 'G') {
        ++goodvisit;
    }
    vis[r][c] = true;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        flag = true;
        goodvisit = 0;
        ll goodsreach = 0;
        grid = vector<vector<char>>(n + 2, vector<char>(m + 2));
        vis = vector<vector<bool>>(n + 2, vector<bool>(m + 2));
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'G') {
                    ++goodsreach;
                }
            }
        }
        for (ll i = 1; i <= n && flag; ++i) {
            for (ll j = 1; j <= m; ++j) {
                if (grid[i][j] == 'B') {
                    if (grid[i - 1][j] == 'G' || grid[i + 1][j] == 'G' || grid[i][j - 1] == 'G' || grid[i][j + 1] == 'G') {
                        flag = false;
                        break;
                    }
                    if (grid[i - 1][j] != 'B') {
                        grid[i - 1][j] = '#';
                    }
                    if (grid[i + 1][j] != 'B') {
                        grid[i + 1][j] = '#';
                    }
                    if (grid[i][j - 1] != 'B') {
                        grid[i][j - 1] = '#';
                    }
                    if (grid[i][j + 1] != 'B') {
                        grid[i][j + 1] = '#';
                    }
                }
            }
        }
        if (flag) {
            floodfill(n, m);
        }
        if (goodvisit == goodsreach && flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}