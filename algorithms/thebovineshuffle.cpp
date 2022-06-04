#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, ans = 0, numberofcycles = 0, cnt = 0;
vector<ll> adj(mx), vcnt(mx);
vector<bool> vis(mx), onstack(mx);
set<ll> st;

void dfs(ll node)
{
    vis[node] = onstack[node] = true;
    ++cnt;
    vcnt[node] = cnt;
    ll u = adj[node];
    if (onstack[u]) {
        numberofcycles++;
        st.insert(u);
        ans += cnt - vcnt[u] + 1;
        cnt = 0;
    }
    else if (!vis[u]) {
        dfs(u);
    }
    onstack[node] = false;
}

int main()
{
    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> adj[i];
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
        }
    }
    cout << ans;
}