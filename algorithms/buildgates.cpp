#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1002;

ll n, x = 0, y = 0, ans = 0;
vector<vector<bool>> vis(2 * mx, vector<bool>(2 * mx)), fencednew(2 * mx, vector<bool>(2 * mx));
vector<vector<ll>> grid;
vector<pair<ll, ll>> fenced;
bool flag = true;

void move(char c)
{
    if (c == 'N') {
        y += 2;
    }
    else if (c == 'S') {
        y -= 2;
    }
    else if (c == 'E') {
        x += 2;
    }
    else {
        x -= 2;
    }
}

void floodfill(ll r, ll c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
        flag = false;
        return;
    }
    if (vis[r][c] || fencednew[r][c]) {
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
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    string s;
    fin >> n >> s;
    ll maxx = -mx, minx = mx, maxy = -mx, miny = mx;
    fenced.push_back({0, 0});
    for (ll i = 0; i < n; ++i) {
        move(s[i]);
        fenced.push_back({x, y});
        if (s[i] == 'N') {
            fenced.push_back({x, y - 1});
        }
        else if (s[i] == 'S') {
            fenced.push_back({x, y + 1});
        }
        else if (s[i] == 'E') {
            fenced.push_back({x - 1, y});
        }
        else {
            fenced.push_back({x + 1, y});
        }
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
    }
    grid = vector<vector<ll>>(abs((maxy - miny + 1)), vector<ll>((maxx - minx + 1)));
    ll shiftr = -minx, shiftup = -miny;
    for (ll i = 0; i < fenced.size(); ++i) {
        fencednew[max((ll)0, (ll)(grid.size() - 1 - (fenced[i].second + shiftup)))][fenced[i].first + shiftr] = true;
    }
    /*for (ll i = 0; i < grid.size(); ++i) {
        for (ll j = 0; j < grid[i].size(); ++j) {
            cout << fencednew[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (ll i = 0; i < grid.size(); ++i) {
        for (ll j = 0; j < grid[i].size(); ++j) {
            if (!fencednew[i][j] && !vis[i][j]) {
                floodfill(i, j);
                if (flag) {
                    ++ans;
                }
                flag = true;
            }
        }
    }
    fout << ans;
}