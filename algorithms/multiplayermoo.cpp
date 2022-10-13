#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 62501;

ll n, ans1 = 0, ans2 = 0;
vector<ll> coordcomp(mx), grouptonum(mx), numofvalsingroup(mx);
vector<vector<ll>> grid(250, vector<ll>(250)), vis(250, vector<ll>(250));
vector<ll> groups(mx);
vector<vector<ll>> adj(mx);

void findmx(ll node, vector<ll>& beenthere, ll cow1, ll cow2)
{
    beenthere[node] = 1;
    
}

void floodfill(ll r, ll c, ll from, ll group)
{
    if (r < 0 || r >= n || c < 0 || c >= n || vis[r][c]) {
        return;
    }
    vis[r][c] = 1;
    if (from == -1 && group == -1) {
        ++group;
        grouptonum[group] = grid[r][c];
        groups[grid[r][c]] = group;
        numofvalsingroup[group]++;
    }
    else if (grid[r][c] == from) {
        groups[grid[r][c]] = group;
        numofvalsingroup[group]++;
    }
    else {
        groups[grid[r][c]] = group + 1;
        numofvalsingroup[group + 1]++;
        adj[group].push_back(group + 1);
        ++group;
    }
    ans1 = max(ans1, numofvalsingroup[group]);
    floodfill(r - 1, c, grid[r][c], group);
    floodfill(r + 1, c, grid[r][c], group);
    floodfill(r, c - 1, grid[r][c], group);
    floodfill(r, c + 1, grid[r][c], group);
}

int main()
{
    cin >> n;
    ll uniqueiter = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (coordcomp[grid[i][j]]) {
                grid[i][j] = coordcomp[grid[i][j]];
            }
            else {
                ll tmp = grid[i][j];
                grid[i][j] = uniqueiter;
                coordcomp[tmp] = uniqueiter++;
            }
        }
    }
    floodfill(0, 0, -1, -1);
    cout << ans1 << "\n";
    vector<ll> beenthere(mx);
    findmx(0, beenthere, -1, -1);
}