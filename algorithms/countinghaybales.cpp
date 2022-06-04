#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    fin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        fin >> l >> r;
        auto it1 = lower_bound(v.begin(), v.end(), l), it2 = upper_bound(v.begin(), v.end(), r);
        fout << it2 - it1 << "\n";
    }
}