#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll prefix = 0, first = 0, mx = 0;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        mx = max(mx, a);
        v[i] = a;
        if (!i) {
            first = a;
        }
        prefix += a;
    }
    ll l = first, r = mx + 1;
    while (l < r) {
        ll mid = l + (r - l) / 2, overflow = 0, flag = 1;
        for (ll i = 0; i < n; ++i) {
            if (overflow + mid < v[i]) {
                flag = 0;
                break;
            }
            overflow = max((ll)0, mid + overflow - v[i]);
        }
        if (flag) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    } 
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
        if (a >= first && ceil((double)prefix / a) <= n && a >= l) {
            cout << ceil((double)prefix / a) << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}