#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        vector<pair<ll, ll>> ev(n + 1);
        for (ll i = 1; i <= n; ++i) {
            cin >> b[i];
            ev[i] = {i / (b[i] + 1) + 1, i};
        }
        sort(ev.begin(), ev.end());
        set<pair<ll, ll>> s;
        ll j = 1;
        for (ll i = 1; i <= n; ++i) {
            while (j <= n && ev[j].first == i) {
                ll id = ev[j++].second;
                s.insert({b[id] ? (id) / b[id] : n, id}); 
            }
            a[s.begin()->second] = i;
            s.erase(s.begin());
        }
        for (ll x : a) {
            if (x) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
}