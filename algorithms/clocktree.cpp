#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> adj[2501];
ll val[2501];
ll n, g1 = 0, g2 = 0, s1 = 0, s2 = 0;

void dfs(ll s, ll e, bool color)
{
    if (color) {
        g1++;
        s1 += val[s];
    }
    else {
        g2++;
        s2 += val[s];
    }
    for (ll a : adj[s]) {
        if (a != e) {
            dfs(a, s, !color);
        }
    }
}

int main()
{
    ifstream cin("clocktree.in");
    ofstream cout("clocktree.out");
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> val[i + 1];
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    if (s1 % 12 == s2 % 12) {
        cout << n;
    }
    else if ((s1 + 1) % 12 == s2 % 12) {
        cout << g2;
    }
    else if ((s2 + 1) % 12 == s1 % 12) {
        cout << g1;
    }
    else {
        cout << 0;
    }
}