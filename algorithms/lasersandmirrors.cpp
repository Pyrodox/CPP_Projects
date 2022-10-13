#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 10;

ll n, xl, yl, xr, yr, ans = mx;
vector<vector<ll>> adj(mx);
vector<ll> xvals, yvals;
vector<pair<ll, ll>> graph(mx);

void bfs()
{
    vector<ll> depth(mx, -1);
    queue<pair<ll, ll>> que;
    que.push({1, 0});
    que.push({1, 1});
    depth[1] = 0;
    while (que.size()) {
        ll node = que.front().first, dir = que.front().second; //dir = 0 for vertical, dir = 1 for horizontal
        que.pop();
        for (ll a : adj[node]) {
            if (!dir && graph[a].second == graph[node].second && (depth[node] < depth[a] || depth[a] == -1)) {
                que.push({a, 0});
                depth[a] = depth[node];
            }
            else if (dir && graph[a].first == graph[node].first && (depth[node] < depth[a] || depth[a] == -1)) {
                que.push({a, 1});
                depth[a] = depth[node];
            }
            else if (!dir && graph[a].second != graph[node].second && (depth[node] + 1 < depth[a] || depth[a] == -1)) {
                que.push({a, 1});
                depth[a] = depth[node] + 1;
            }
            else if (dir && graph[a].first != graph[node].first && (depth[node] + 1 < depth[a] || depth[a] == -1)) {
                que.push({a, 0});
                depth[a] = depth[node] + 1;
            }
        }
    }
    ans = depth[2];
}

int main()
{
    ifstream cin("lasers.in");
    ofstream cout("lasers.out");
    cin >> n >> xl >> yl >> xr >> yr;
    xvals.push_back(xl);
    if (xl != xr) 
        xvals.push_back(xr);
    yvals.push_back(yl);
    if (yl != yr)
        yvals.push_back(yr);
    graph[1] = {xl, yl};
    graph[2] = {xr, yr};
    map<ll, ll> foundx, foundy;
    foundx[xl] = 1, foundx[xr] = 1, foundy[yl] = 1, foundy[yr] = 1;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (!foundx[a]) {
            xvals.push_back(a);
            foundx[a] = 1;
        }
        if (!foundy[b]) {
            yvals.push_back(b);
            foundy[b] = 1;
        }
        graph[i + 3] = {a, b};
    }
    sort(xvals.begin(), xvals.end());
    sort(yvals.begin(), yvals.end());
    map<ll, ll> compx, compy;
    for (ll i = 0; i < xvals.size(); ++i) {
        compx[xvals[i]] = i;
    }
    for (ll j = 0; j < yvals.size(); ++j) {
        compy[yvals[j]] = j;
    }
    vector<set<pair<ll, ll>>> newxcoords(mx), newycoords(mx);
    ll maxx = 0, maxy = 0;
    for (ll i = 0; i < n + 2; ++i) {
        ll x = compx[graph[i + 1].first], y = compy[graph[i + 1].second];
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        newxcoords[x].insert({y, i + 1});
        newycoords[y].insert({x, i + 1});
        graph[i + 1] = {x, y};
    }
    for (ll i = 0; i < maxx; ++i) {
        for (auto it = ++newxcoords[i].begin(); it != newxcoords[i].end(); ++it) {
            auto val = *(--it);
            ++it;
            adj[(*it).second].push_back(val.second);
            adj[val.second].push_back((*it).second);
        }
    }
    for (ll i = 0; i < maxy; ++i) {
        for (auto it = ++newycoords[i].begin(); it != newycoords[i].end(); ++it) {
            auto val = *(--it);
            ++it;
            adj[(*it).second].push_back(val.second);
            adj[val.second].push_back((*it).second);
        }
    }
    bfs();
    cout << ans;
}