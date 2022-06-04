#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<ll> v(n);
    ll l = 0, r = 0;
    for (ll& i : v) {
        cin >> i;
        r += i;
    }
    while (l < r) {
        ll mid = l + (r - l) / 2, divisioncount = 1, ttl = 0, mx = 0;
        for (ll i : v) {
            if (ttl + i <= mid) {
                ttl += i;
                //cout << mid << ": " << ttl << "\n";
            }
            else {
                ++divisioncount;
                ttl = i;
                //cout << mid << ": " << ttl << "\n";
            }
            mx = max(mx, ttl);
        } 
        if (divisioncount <= k && mid >= mx) {
            //cout << "r -> " << mid << "\n";
            r = mid;
        }
        else {
            //cout << "l -> " << mid + 1 << "\n";
            l = mid + 1;
        }
    }
    cout << l;
}