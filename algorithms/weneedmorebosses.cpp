#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 3e5 + 1;

vector<ll> vis(mx), dp(mx), visdiam(mx);
vector<ll> adj[mx], adjtemp[mx];
vector<ll> mark(mx), cyclenumarray(mx);
ll finalcyclenum = 0, color[mx], par[mx], newpar[mx], cnt[mx];
vector<pair<ll, ll>> queries;
ll maxnode = 1, maxdist = 0;
 
void findcycles(ll node, ll parent, int& cyclenum)
{
    if (color[node] == 2) {
        return;
    }
    if (color[node] == 1) {
        ++cyclenum;
        finalcyclenum = max(finalcyclenum, (ll)cyclenum);
        ll cur = parent;
        mark[cur] = cyclenum;
        while (cur != node) {
            cur = par[cur];
            mark[cur] = cyclenum;
        }
        return;
    }
    par[node] = parent;
    color[node] = 1;
    for (ll a : adjtemp[node]) {
        if (a == par[node]) {
            continue;
        }
        findcycles(a, node, cyclenum);
    }
    color[node] = 2;
}

void visit(ll node, ll parent)
{
    for (ll a : adjtemp[node]) {
        if (a != parent) {
            visit(a, node);
        }
    }
}

void diameter(ll node, ll par, ll cnt)
{
    visdiam[node] = true;
    if (cnt > maxdist) {
        maxdist = cnt;
        maxnode = node;
    }
    for (ll a : adj[node]) {
        if (a != par) {
            diameter(a, node, cnt + 1);
        }
    }
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<pair<ll, ll>> queries;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adjtemp[a].push_back(b);
        adjtemp[b].push_back(a);
        queries.push_back({a, b});
    }
    int c = 0;
    findcycles(1, 0, c);
    cyclenumarray = mark;
    for (auto val : queries) {
        if (cyclenumarray[val.first] != cyclenumarray[val.second]) {
            adj[cyclenumarray[val.first]].push_back(cyclenumarray[val.second]);
            adj[cyclenumarray[val.second]].push_back(cyclenumarray[val.first]);
        }   
    }
    diameter(1, 0, 0);
    visdiam = vector<ll>(mx);
    diameter(maxnode, 0, 0);
    cout << maxdist;   
}