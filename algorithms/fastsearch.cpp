#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll low(vector<ll>& v, ll x)
{
    ll l = -1, r = v.size(), mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (v[mid] >= x) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    return r + 1;
}

ll high(vector<ll>& v, ll x)
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
    cin >> n;
    vector<ll> v(n);
    for (ll& a : v) {
        cin >> a;
    }
    cin >> k;
    sort(v.begin(), v.end());
    while (k--) {
        ll l, r;
        cin >> l >> r;
        cout << high(v, r) - low(v, l) + 1 << "\n";
    }
}