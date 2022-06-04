#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    ll mx = 0;
    vector<ll> v(n);
    for (ll& i : v) {
        cin >> i;
        mx = max(mx, i);
    }
    ll l = 0, r = mx * t;
    while (l < r) {
        ll mid = l + (r - l) / 2, total = 0;
        for (ll i : v) {
            total += mid / i;
            if (total >= t) {
                r = mid;
                break;
            }
        }
        if (total >= t) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}