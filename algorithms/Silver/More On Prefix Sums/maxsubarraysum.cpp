#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> prefix(n + 1);
    for (ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        prefix[i] = prefix[i - 1] + a;
    }
    ll minval = 0;
    ll maxval = prefix[1];
    for (ll i = 1; i <= n; ++i) {
        maxval = max(maxval, prefix[i] - minval);
        minval = min(minval, prefix[i]);
    }
    cout << maxval;
}