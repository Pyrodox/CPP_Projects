#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2001;

ll n, cnt = 0;
vector<vector<bool>> cowpresent(mx, vector<bool>(mx)), vis(mx, vector<bool>(mx));

pair<ll, ll> comfortable(ll a, ll b)
{
    ll cnttmp = 0;
    pair<ll, ll> retpair = {a, b};

    if (cowpresent[a - 1][b]) { ++cnttmp; } else { retpair = {a - 1, b}; }
    if (cowpresent[a + 1][b]) { ++cnttmp; } else { retpair = {a + 1, b}; }
    if (cowpresent[a][b - 1]) { ++cnttmp; } else { retpair = {a, b - 1}; }
    if (cowpresent[a][b + 1]) { ++cnttmp; } else { retpair = {a, b + 1}; }
    
    if (cnttmp == 3) {
        return retpair;
    }

    return {-1, -1};
}

void floodfill(ll r, ll c)
{
    if (r < 1 || r >= mx || c < 1 || c >= mx || vis[r][c] || !cowpresent[r][c]) {
        return;
    }
    vis[r][c] = true;
    auto add = comfortable(r, c);
    if (add.first >= 0) {
        ++cnt;
            cowpresent[add.first][add.second] = true;
            vis[add.first - 1][add.second] = false;
            floodfill(add.first - 1, add.second);
            vis[add.first + 1][add.second ] = false;
            floodfill(add.first + 1, add.second);
            vis[add.first][add.second - 1] = false;
            floodfill(add.first, add.second - 1);
            vis[add.first][add.second + 1] = false;
            floodfill(add.first, add.second + 1);
    }
    else {
        floodfill(r + 1, c);
        floodfill(r - 1, c);
        floodfill(r, c + 1);
        floodfill(r, c - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        a += 1000;
        b = mx - 1000 - b;
        if (cowpresent[b][a]) {
            --cnt;
        }
        else {
            cowpresent[b][a] = true;
            floodfill(b, a);
            vis = vector<vector<bool>>(mx, vector<bool>(mx));
        }
        v.push_back(cnt);
    }
    for (ll a : v) {
        cout << a << "\n";
    }
}