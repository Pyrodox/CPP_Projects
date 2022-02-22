#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool flag = true;

void dfs(vector<vector<ll>>& v, vector<ll>& colorvec, vector<bool>& visited, ll color, ll node, ll startnode)
{
    if (visited[node]) {
        if (node != startnode && colorvec[node] == colorvec[startnode]) {
            cout << "IMPOSSIBLE";
            flag = false;
        }
        return;
    }
    visited[node] = true;
    colorvec[node] = color % 2 + 1;
    ++color;
    for (auto val : v[node]) {
        if (flag) {
            dfs(v, colorvec, visited, color, val, node);
        }
    }
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<ll>> v(n + 1);
    vector<ll> colorvec(n + 1); //colors are 1 or 2
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visited(n + 1);
    for (ll i = 1; i <= n; ++i) {
        if (!visited[i] && flag) {
            dfs(v, colorvec, visited, 0, i, i);
        }
    }
    if (flag) {
        for (ll i = 1; i < n; ++i) {
            cout << colorvec[i] << " ";
        }
        cout << colorvec[n];
    }
}