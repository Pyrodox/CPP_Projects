#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binarysearchlow(vector<ll>& v, ll x)
{
    ll l = -1, r = v.size(), mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (v[mid] <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    return l + 1;
}

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<ll> v(n);
    for (ll& a : v) {
        cin >> a;
    }
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        cout << binarysearchlow(v, x) << "\n";
    }
}