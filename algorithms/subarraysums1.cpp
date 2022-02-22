#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    ll l = 0, r = 1;
    vector<ll> pfx(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> pfx[i];
        pfx[i] += pfx[i - 1];
    }
    ll ans = 0;
    while (r <= n) {
        if (pfx[r] - pfx[l] < x) {
            ++r;
        }
        else if (pfx[r] - pfx[l] > x) {
            ++l;
        }
        else {
            ++ans;
            ++r;
        }
    }
    cout << ans;
}