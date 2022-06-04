#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll n, m;
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/
    cin >> n >> m;
    set<ll> s, ms2;
    map<ll, ll> mp;
    s.insert(-1);
    mp[-1] = 1000000;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        s.insert(a);
        mp[a]++;
    }
    vector<ll> v;
    for (ll i = 0; i < m; ++i) {
        ll b;
        cin >> b;
        v.push_back(b);
        ms2.insert(b);
    }
    for (ll i = 0; i < m; ++i) {
        auto it = s.lower_bound(v[i]);
        while ((it != s.begin() && *it > v[i]) || mp[*it] <= 0) {
            --it;
        }
        cout << *it << "\n";
        mp[*it]--;
        if (mp[*it] <= 0) {
            s.erase(it);
        }
    }
}