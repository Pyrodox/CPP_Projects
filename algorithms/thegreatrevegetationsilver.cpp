#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

ll n, m;
vector<vector<ll>> v(mx);
vector<ll> colorv(mx);
vector<bool> vis(mx);
map<vector<ll>, string> mp;
bool good = true;

void dfs(ll node, ll color)
{
    vis[node] = true;
    colorv[node] = color;
    for (ll a : v[node]) {
        if (!vis[a]) {
            if (mp[{node, a}] == "S") {
                dfs(a, color);
            }
            else {
                dfs(a, !color);
            }
        }
    }
}

int main()
{
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    fin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        string s;
        ll a, b;
        fin >> s >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        mp[{a, b}] = s;
        mp[{b, a}] = s;
    }
    ll cnt = 0;
    for (ll i = 1; i <= n && good; ++i) {
        if (!vis[i]) {
            ++cnt;
            dfs(i, 0);
        }
        else {
            for (ll j = 0; j < v[i].size(); ++j) {
                if (mp[{i, v[i][j]}] == "S" && colorv[i] != colorv[v[i][j]]) {
                    good = false;
                    break;
                }
                if (mp[{i, v[i][j]}] == "D" && colorv[i] == colorv[v[i][j]]) {
                    good = false;
                    break;
                }
            }
        }
    }
    if (!good) {
        fout << 0;
        return 0;
    }
    fout << "1";
    for (ll i = 0; i < cnt; ++i) {
        fout << "0";
    }
}