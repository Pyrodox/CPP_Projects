#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1;

ll n, cnt;
vector<ll> v(mx), stck, viscnt(mx), ans(mx), posinviscnt(mx);
vector<bool> vis(mx), onstack(mx);

void dfs(ll node)
{
    vis[node] = onstack[node] = true;
    ll u = v[node];
    //cout << "node: " << node << " " << u << "\n";
    ++cnt;
    viscnt[node] = cnt;
    stck.push_back(node);
    posinviscnt[node] = cnt - 1;
    if (ans[u]) {
        for (ll i = 0; i < stck.size(); ++i) {
            ans[stck[i]] = ans[u] + stck.size() - i;
            //cout << stck[i] << " a\n";
        }
        //cout << "ans\n";
        return;
    }
    if (onstack[u]) {
        //cout << posinviscnt[u] << " " << stck.size() << "\n";
        for (ll i = posinviscnt[u]; i < stck.size(); ++i) {
            ans[stck[i]] = cnt - viscnt[u] + 1;
            //cout << stck[i] << " b\n";
        }
        for (ll i = 0; i < posinviscnt[u]; ++i) {
            ans[stck[i]] = ans[stck[posinviscnt[u]]] + posinviscnt[u] - i;
        }
        //cout << "cycle found\n";
    }
    else if (!vis[u]) {
        //cout << "keep searching\n";
        dfs(u);
    }
    onstack[u] = false;
}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            stck.clear();
            dfs(i);
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}