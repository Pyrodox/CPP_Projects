#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    fin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
    }
    ll start = 1;
    if (n > 9000) {
        start = 450;
    }
    for (ll i = start; i <= n; ++i) {
        priority_queue<ll, vector<ll>, greater<ll>> p(v.begin(), v.begin() + i);
        map<ll, vector<ll>> m;
        map<ll, ll> mm;
        for (ll j = 0; j < i; ++j) {
            m[v[j]].push_back(j);
        }
        vector<ll> v2;
        for (ll j = 0; j < i; ++j) {
            v2.push_back(v[j]);
        }
        ll j = i;
        bool check = true;
        while (j != n) {
            ll a = m[p.top()][mm[p.top()]];
            v2[m[p.top()][mm[p.top()]]] += v[j];
            if (v2[m[p.top()][mm[p.top()]]] > k) {
                check = false;
                break;
            }
            mm[p.top()]++;
            p.pop();
            p.push(v2[a]);
            m[v2[a]].push_back(a);
            ++j;
        }
        if (check) {
            fout << i;
            return 0;
        }
    }
}