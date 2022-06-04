#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<ll> v(n), nodup;
    map<ll, ll> mp;
    for (ll& i : v) {
        cin >> i;
        mp[i]++;
        if (mp[i] == 1) {
            nodup.push_back(i);
        }
    }
    sort(nodup.begin(), nodup.end());
    ll l = 0, r = nodup.size() - 1;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        vector<ll> prefix(n);
        for (ll i = 0; i < n; ++i) {
            if (v[i] >= nodup[mid]) {
                prefix[i] = 1;
            }
            else {
                prefix[i] = -1;
            }
        }
        for (ll i = 1; i < n; ++i) {
            prefix[i] += prefix[i - 1];
        }
        ll mx = prefix[k - 1], mn = 0;
        for (ll i = k; i < n; ++i) {
            mn = min(mn, prefix[i - k]);
            mx = max(mx, prefix[i] - mn);
        }
        if (mx > 0) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << nodup[l];
}