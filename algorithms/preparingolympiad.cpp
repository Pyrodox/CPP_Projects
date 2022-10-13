#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> v;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    vector<vector<ll>> subs{{}};
    for (ll a : v) {
        ll s = subs.size();
        for (ll i = 0; i < s; ++i) {
            subs.push_back(subs[i]);
            subs.back().push_back(a);
        }
    }
    ll ans = 0;
    for (auto val : subs) {
        if (val.size() >= 2) {
            ll mn = 1e9, mx = 0, total = 0;
            for (ll a : val) {
                mn = min(mn, a);
                mx = max(mx, a);
                total += a;
            }
            if (total >= l && total <= r && mx - mn >= x) {
                ++ans;
            } 
        }
    }
    cout << ans;
}