#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, cnt, ans = 0;
vector<ll> v(mx), moos(mx), stck, placeinstck(mx);
bool vis[mx], onstack[mx], alreadyfoundans[mx];

void dfs(ll node)
{
    vis[node] = onstack[node] = true;
    placeinstck[node] = cnt;
    ++cnt;
    stck.push_back(node);
    ll u = v[node];
    if (alreadyfoundans[u]) {
        for (ll i = 0; i < stck.size(); ++i) {
            ans += moos[stck[i]];
            alreadyfoundans[stck[i]] = true;
        }
    }
    else if (onstack[u]) {
        ll mn = 1e9;
        for (ll i = 0; i < stck.size(); ++i) {
            if (i >= placeinstck[u]) {
                mn = min(mn, moos[stck[i]]);
            }
            ans += moos[stck[i]];
            alreadyfoundans[stck[i]] = true;
        }
        ans -= mn;
    }
    else if (!vis[u]) {
        dfs(u);
    }
}

int main()
{
    cin >> n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i] >> moos[i];
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            stck.clear();
            dfs(i);
        }
    }
    cout << ans;
}