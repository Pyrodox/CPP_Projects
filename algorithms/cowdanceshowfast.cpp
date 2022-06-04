#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    fin >> n >> t;
    vector<ll> v(n);
    for (ll& a : v) {
        fin >> a;
    }
    ll l = 1, r = n;
    while (l < r) {
        ll m = l + (r - l) / 2;
        priority_queue<ll, vector<ll>, greater<ll>> p(v.begin(), v.begin() + m);
        map<ll, vector<ll>> mp;
        map<ll, ll> mm;
        for (ll j = 0; j < m; ++j) {
            mp[v[j]].push_back(j);
        }
        vector<ll> v2;
        for (ll j = 0; j < m; ++j) {
            v2.push_back(v[j]);
        }
        ll j = m;
        bool check = true;
        while (j != n) {
            ll a = mp[p.top()][mm[p.top()]];
            v2[mp[p.top()][mm[p.top()]]] += v[j];
            if (v2[mp[p.top()][mm[p.top()]]] > t) {
                check = false;
                break;
            }
            mm[p.top()]++;
            p.pop();
            p.push(v2[a]);
            mp[v2[a]].push_back(a);
            ++j;
        }
        if (check) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    fout << l;
}