#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1001;

ll n, curarea = 0, curper = 0;
vector<vector<char>> grid(mx, vector<char>(mx));
vector<vector<bool>> vis(mx, vector<bool>(mx));
void floodfill(ll r, ll c)
{
    if (r <= 0 || r > n || c <= 0 || c > n || grid[r][c] == '.') {
        ++curper;
        return;
    }
    if (vis[r][c]) {
        return;
    }
    vis[r][c] = true;
    ++curarea;
    floodfill(r + 1, c);
    floodfill(r - 1, c);
    floodfill(r, c + 1);
    floodfill(r, c - 1);
}

int main()
{
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    fin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            fin >> grid[i][j];
        }
    }
    ll mxarea = 0, mnper = 1e9;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (!vis[i][j] && grid[i][j] == '#') {
                floodfill(i, j);
                if (curarea == mxarea) {
                    mnper = min(mnper, curper);
                }
                else if (curarea > mxarea) {
                    mxarea = curarea;
                    mnper = curper;
                }
                curarea = 0, curper = 0;
            }
        }
    }
    fout << mxarea << " " << mnper;
}