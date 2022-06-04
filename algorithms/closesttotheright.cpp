#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binarysearchhigh(vector<ll>& v, ll x)
{
    ll l = -1, r = v.size(), mid;
    while (r > l + 1) {
        ll mid = (l + r) / 2;
        if (v[mid] >= x) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return r + 1;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll& a : v) {
        cin >> a;
    }
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        cout << binarysearchhigh(v, x) << "\n";       
    }
}