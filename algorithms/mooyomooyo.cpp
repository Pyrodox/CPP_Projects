#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e2 + 1;

ll n, k, cnt = 0;
vector<vector<ll>> grid(mx, vector<ll>(11));
vector<vector<bool>> vis(mx, vector<bool>(11));
vector<pair<ll, ll>> clearvec;

void dropgrid()
{
    for (ll j = 10; j >= 1; --j) {
        bool searching = true, nextzero = false;
        ll a, b, moveamnt = 0;
        for (ll i = n; i >= 1; --i) {
            if (!grid[i][j] && searching) {
                a = i;
                searching = false;
            }
            else if (!searching && grid[i][j] != 0 && !nextzero) {
                b = i;
                moveamnt = a - b;
                nextzero = true;
            }
            else if (nextzero && (i == 1 || grid[i][j] == 0)) {
                for (ll k = b; k >= i; --k) {
                    grid[k + moveamnt][j] = grid[k][j];
                    grid[k][j] = 0;
                }
                i = n;
                a = 0, b = 0, moveamnt = 0;
                nextzero = false, searching = true;
            }
        }
    }
}

void floodfill(ll r, ll c, ll val)
{
    if (r < 1 || r > n || c < 1 || c > 10 || grid[r][c] != val || vis[r][c]) {
        return;
    }
    ++cnt;
    vis[r][c] = true;
    clearvec.push_back({r, c});
    floodfill(r - 1, c, val);
    floodfill(r + 1, c, val);
    floodfill(r, c - 1, val);
    floodfill(r, c + 1, val);
}

int main()
{
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    fin >> n >> k;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= 10; ++j) {
            char c;
            fin >> c;
            grid[i][j] = (ll) (c - '0');
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= 10; ++j) {
                if (grid[i][j]) {
                    vis = vector<vector<bool>>(n + 1, vector<bool>(11));
                    floodfill(i, j, grid[i][j]);
                    if (cnt >= k) {
                        for (ll i = 0; i < clearvec.size(); ++i) {
                            grid[clearvec[i].first][clearvec[i].second] = 0;
                        }
                        flag = true;
                    }
                    cnt = 0;
                    clearvec.clear();
                }
            }
        }
        dropgrid();
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= 10; ++j) {
            fout << grid[i][j];
        }
        fout << "\n";
    }
}