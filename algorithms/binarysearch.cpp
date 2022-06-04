#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string binarysearch(vector<ll>& v, ll k)
{
    ll l = 0, r = v.size() - 1;
    bool ok = false;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (v[mid] == k) {
            ok = true;
            break;
        }
        else if (k > v[mid]) {
            l = mid + 1;
        }
        else if (k < v[mid]) {
            r = mid - 1;
        }
    }
    if (ok) {
        return "YES\n";
    }
    return "NO\n";
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
    while (k--) {
        ll a;
        cin >> a;
        cout << binarysearch(v, a);
    }
}