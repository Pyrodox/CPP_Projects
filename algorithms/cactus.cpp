#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mx = 1e5 + 1;
 
vector<ll> adj[mx], adjtemp[mx];
ll finalcyclenum = 0, color[mx], mark[mx], par[mx], cyclenumarray[mx], newpar[mx], cnt[mx];
vector<pair<ll, ll>> queries;
 
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
 
void dfs(ll node, ll parent)
{
    cnt[node] = cnt[parent];
    if (node <= finalcyclenum) {
        ++cnt[node];
    }
    for (ll a : adj[node]) {
        if (a != parent) {
            newpar[a] = node;
            dfs(a, node);
        }
    }
}
 
void dfslca(int u, int p, int **memo, int *lev, int log)
{
    memo[u][0] = p;
    for (int i = 1; i <= log; i++)
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    for (int v : adj[u])
    {
        if (v != p)
        {
            lev[v] = lev[u] + 1;
            dfslca(v, u, memo, lev, log);
        }
    }
}
 
int lca(int u, int v, int log, int *lev, int **memo)
{
    // The node which is present farthest
    // from the root node is taken as u
    // If v is farther from root node
    // then swap the two
    if (lev[u] < lev[v])
        swap(u, v);
 
    // Finding the ancestor of u
    // which is at same level as v
    for (int i = log; i >= 0; i--)
        if ((lev[u] - pow(2, i)) >= lev[v])
            u = memo[u][i];
 
    // If v is the ancestor of u
    // then v is the LCA of u and v
    if (u == v)
        return u;
 
    // Finding the node closest to the root which is
    // not the common ancestor of u and v i.e. a node
    // x such that x is not the common ancestor of u
    // and v but memo[x][0] is
    for (int i = log; i >= 0; i--)
    {
        if (memo[u][i] != memo[v][i])
        {
            u = memo[u][i];
            v = memo[v][i];
        }
    }
 
    // Returning the first ancestor
    // of above found node
    return memo[u][0];
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adjtemp[a].push_back(b);
        adjtemp[b].push_back(a);
        queries.push_back({a, b});
    }
    int c = 0;
    findcycles(1, 0, c);
    for (ll i = 1; i <= n; ++i) {
        cyclenumarray[i] = mark[i];
    }
    ll newnodeassign = finalcyclenum + 1;
    for (ll i = 1; i <= n; ++i) {
        if (!cyclenumarray[i]) {
            cyclenumarray[i] = newnodeassign++;
        }
    }
    vector<vector<ll>> veca;
    for (auto val : queries) {
        if (cyclenumarray[val.first] != cyclenumarray[val.second] && (cyclenumarray[val.first] || cyclenumarray[val.second])) {
            adj[cyclenumarray[val.first]].push_back(cyclenumarray[val.second]);
            adj[cyclenumarray[val.second]].push_back(cyclenumarray[val.first]);
            veca.push_back({cyclenumarray[val.first], cyclenumarray[val.second]});
        }   
    }
    ll q;
    cin >> q;
    vector<vector<ll>> quevec;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        quevec.push_back({cyclenumarray[a], cyclenumarray[b]});
    }
    dfs(1, 0);
    int log = (int)ceil(log2(n));
    int **memo = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        memo[i] = new int[log + 1];
 
    int *lev = new int[n + 1];
    for (int i = 0; i <= n; i++)
        memset(memo[i], -1, sizeof memo[i]);
 
    dfslca(1, 1, memo, lev, log);
    for (auto val : quevec) {
        ll lcaanc = lca(val[0], val[1], log, lev, memo);
        if (lcaanc <= finalcyclenum) {
            //cout << (1LL << cnt[val[0]] - cnt[lcaanc]) % 1000000007 * (1LL << cnt[val[1]] - cnt[lcaanc]) % 1000000007 * 2 % 1000000007 << "\n";
            cout << binpow(2, cnt[val[0]] + cnt[val[1]] - 2 * cnt[lcaanc] + 1, 1000000007) << "\n";
        }
        else {
            //cout << (1LL << cnt[val[0]] - cnt[lcaanc]) % 1000000007 * (1LL << cnt[val[1]] - cnt[lcaanc]) % 1000000007 % 1000000007 << "\n";
            cout << binpow(2, cnt[val[0]] + cnt[val[1]] - 2 * cnt[lcaanc], 1000000007) << "\n";
        }
    }
}