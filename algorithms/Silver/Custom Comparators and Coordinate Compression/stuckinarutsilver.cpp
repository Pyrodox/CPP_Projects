#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
    char dir;
    ll ind, x, y;
};

bool vis[1000];
ll ans[1000];
vector<ll> adj[1000];

ll dfs(ll node)
{   
    if (vis[node]) {
        return ans[node];
    }
    vis[node] = true;
    for (ll a : adj[node]) {
        ans[node] += dfs(a) + 1;
    }

    return ans[node];
}

bool cmp(const pair<ll, vector<point>>& a, const pair<ll, vector<point>>& b)
{
    return a.first < b.first;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<point> east, north, stop(n);
    vector<bool> stopped(n);
    vector<pair<ll, vector<point>>> v;
    for (ll i = 0; i < n; ++i) {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        if (c == 'E') {
            east.push_back({'E', i, x, y});
        }
        else {
            north.push_back({'N', i, x, y});
        }
    }
    for (ll i = 0; i < east.size(); ++i) {
        for (ll j = 0; j < north.size(); ++j) {
            if (east[i].x < north[j].x && east[i].y > north[j].y) {
                if (north[j].x - east[i].x > east[i].y - north[j].y) {
                    v.push_back({north[j].x - east[i].x, {east[i], north[j]}});
                }
                else if (north[j].x - east[i].x < east[i].y - north[j].y) {
                    v.push_back({east[i].y - north[j].y, {north[j], east[i]}});
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto p : v) {
        ll i = p.second[0].ind;
        if (!stopped[i] && (!stopped[p.second[1].ind] || 
        (p.second[0].dir == 'E' && stop[p.second[1].ind].y >= p.second[0].y || 
        p.second[0].dir == 'N' && stop[p.second[1].ind].x >= p.second[0].x))) {
            stopped[i] = true;
            stop[i] = p.second[1];
            adj[p.second[1].ind].push_back(i);
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
}