#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0, l = 0, r = n - 1, cnt = 0;
    while (l < r) {
        if (v[l] + v[r] <= x) {
            ++ans;
            ++l;
            --r;
        }
        else if (v[l] + v[r] > x) {
            --r;
            ++cnt;
        }
        if (l == r) {
            ++cnt;
        }
    }
    cout << ans + cnt;
}