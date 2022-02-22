#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> match(vector<ll> v)
{
    vector<vector<ll>> mv(3);
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j <= v.size(); ++j) {
            mv[i].push_back(0);
        }
    }
    for (ll i = 0; i < v.size(); ++i) {
        for (ll j = 0; j < 3; ++j) {
            mv[j][i + 1] = mv[j][i];
        }
        mv[v[i]][i + 1]++;
    }

    return mv;
}

int main()
{
    ll n;
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    fin >> n;
    vector<ll> v(n), reversev(n);
    for (int i = 0; i < n; ++i) {
        string s;
        fin >> s;
        if (s == "P") {
            v[i] = 1;
        }
        else if (s == "S") {
            v[i] = 2;
        }
        reversev[v.size() - 1 - i] = v[i];
    }
    vector<vector<ll>> prefm = match(v);
    vector<vector<ll>> suffm = match(reversev);
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            for (ll k = 0; k < 3; ++k) {
                ans = max(ans, prefm[j][i] + suffm[k][n - i]);
            }
        }
    }
    fout << ans;
}