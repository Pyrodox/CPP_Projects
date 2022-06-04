#include <bits/stdc++.h>
using namespace std; 
 
#define pii pair<int, int>
#define f first
#define s second
 
const int mx = 1e5 + 5;
 
int n, m; long double X, ans[mx]; pii val[mx]; vector<pii> adj[mx]; vector<int> cmp, V;
 
void dfs(int cur){
    cmp.push_back(cur); V.push_back(val[cur].f * val[cur].s * -1);
    for (auto [nxt, c] : adj[cur]){
        int sgn = -val[cur].f, v = c - val[cur].s;
        if (val[nxt].f){
            if (val[nxt].f == sgn){
                if (val[nxt].s != v) cout<<"NO\n", exit(0); 
                continue;
            }            
            long double ret = sgn * (val[nxt].s - v) / 2.0;
            if (X != -1e9 and ret != X) cout<<"NO\n", exit(0); 
            X = ret;
        }
        if (!val[nxt].f) val[nxt] = {sgn, v}, dfs(nxt);
    }
}
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++) if (!val[i].f){
        val[i] = {1, 0}; X = -1e9; cmp.clear(); V.clear();
        dfs(i);
        if (X == -1e9) sort(V.begin(), V.end()), X = V[V.size() / 2];
        
        for (int node : cmp) ans[node] = X * val[node].f + val[node].s;
    }
    cout<<"YES\n";
    for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}
/*
(This solution solves for some component)

Let the value of some node in the component be X.

Then every node in the component can be represented as: sgn * X + val
which can be found with a dfs.

There are 2 cases for finding X:
1) Some node in the component can be represented by 2 DIFFERENT equations:

   sgn1 * X + val1 = sgn2 * X + val2

   We can solve for X or determine if there's no solution.

2) Every node in the component can only be represented by 1 equation:

   For every node in the component let: V[i] = value for X that would make the equation 0
                                        V[i] = val * sgn * -1
    
   We want to minimize: ⅀|X - V[i]| so it's clear that we should
   set X to be the MEDIAN of array V
*/