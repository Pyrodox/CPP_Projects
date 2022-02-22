#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<ll>& visited, vector<vector<ll>>& adj, ll node)
{
    if (visited[node] == 1) {
        return;
    }    
    visited[node] = 1;
    for (auto u : adj[node]) {
        dfs(visited, adj, u);
    }
}

int main()
{
    ll p, c;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> p >> c;
        if (p == 0 && c == 0) {
            return 0;
        }
        vector<vector<ll>> adj(p);
        vector<vector<ll>> edges(c);
        for (ll i = 0; i < c; ++i) {
            ll tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            adj[tmp1].push_back(tmp2);
            adj[tmp2].push_back(tmp1);
            edges[i] = {tmp1, tmp2};
        }
        for (auto val : adj) {
            for (auto u : val) {
                cout << u << " ";
            }
            cout << "\n";
        }
        bool flag = true;
        for (ll i = 0; i < c; ++i) {
            vector<ll> visited(p);
            vector<vector<ll>> adj2 = adj;
            adj2[edges[i][0]].erase(find(adj2[edges[i][0]].begin(), adj2[edges[i][0]].end(), edges[i][1]));
            adj2[edges[i][1]].erase(find(adj2[edges[i][1]].begin(), adj2[edges[i][1]].end(), edges[i][0]));
            dfs(visited, adj2, i);
            if (count(visited.begin(), visited.end(), 0) > 0) {
                cout << "YES\n";
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        }
    }
}