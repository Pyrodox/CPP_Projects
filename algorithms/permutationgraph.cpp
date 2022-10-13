#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2.5e5 + 1;

vector<ll> v(mx);
vector<ll> prefixmin(mx), prefixmax(mx), suffixmin(mx), suffixmax(mx);

ll disleft(ll l, ll r, ll ismx = 1)
{
    if (l == r) {
        return 0;
    }
    ll mnind, mxind;
    if (ismx) {
        mnind = prefixmin[r];
    }
    else {
        mxind = prefixmax[r];
    }
    if (ismx) {
        return 1 + disleft(0, mnind, !ismx);
    }

    return 1 + disleft(0, mxind, !ismx);
}

ll disright(ll l, ll r, ll ismx = 1)
{
    if (l == r) {
        return 0;
    }
    ll mnind, mxind;
    if (ismx) {
        mnind = suffixmin[l];
    }
    else {
        mxind = suffixmax[l];
    }
    if (ismx) {
        return 1 + disright(mnind, r, !ismx);
    }
    
    return 1 + disright(mxind, r, !ismx);
}

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n;
        ll mxind = 0, mxval = 0, mnind = 0, mnval = mx;
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] > mxval) {
                mxind = i;
                mxval = v[i];
            }
            if (v[i] < mnval) {
                mnind = i;
                mnval = v[i];
            }
            prefixmax[i] = mxind;
            prefixmin[i] = mnind;
        }
        ll oldmxind = mxind;
        mxind = 0, mxval = 0, mnind = 0, mnval = mx;
        for (ll i = n - 1; i >= 0; --i) {
            ll a = v[i];
            if (a > mxval) {
                mxind = i;
                mxval = a;
            }
            if (a < mnval) {
                mnind = i;
                mnval = a;
            }
            suffixmax[i] = mxind;
            suffixmin[i] = mnind;
        }
        cout << disleft(0, oldmxind) + disright(oldmxind, n - 1) << "\n";
    }   
}