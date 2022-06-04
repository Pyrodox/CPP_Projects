#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    vector<ll> pfx(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> pfx[i];
        pfx[i] += pfx[i - 1];
    }
    ll l = 0, r = 1, ans = 0;
    while (r <= n && l <= n) {
        if (pfx[r] - pfx[l] > t) {
            ++l;
        }
        else if (pfx[r] - pfx[l] < t) {
            ans = max(ans, r - l);
            ++r;
        }
        else {
            ans = max(ans, r - l);
            ++l;
        }
    }
    cout << ans;
}