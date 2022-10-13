#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e6 + 1;

vector<ll> nums(mx);

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void sieve()
{      
    for (ll i = 2; i * i < mx; ++i) {
        if (nums[i] == i) {
            for (ll j = i * i; j < mx; j += i) {
                if (nums[j] == j) {
                    nums[j] = i;
                }
            }
        }
    }
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i < mx; ++i) {
        nums[i] = i;
    }
    sieve();
    vector<ll> listoffactors(mx);
    ll mxfactor = 1;    
    while (n--) {
        ll x;
        cin >> x;
        vector<ll> forx;
        while (x != 1) {
            ll y = nums[x], c = 0, sz = forx.size();
            while (x % y == 0) {
                ++c;
                x /= y;
                ll pw = binpow(y, c);
                forx.push_back(pw);
                listoffactors[pw]++;
                if (listoffactors[pw] >= 2) {
                    mxfactor = max(mxfactor, pw);
                }
            }
            ll tmp = forx.size();
            for (ll i = sz; i < tmp; ++i) {
                for (ll j = 0; j < sz; ++j) {
                    listoffactors[forx[i] * forx[j]]++;
                    if (listoffactors[forx[i] * forx[j]] >= 2) {
                        mxfactor = max(mxfactor, forx[i] * forx[j]);
                    }
                    forx.push_back(forx[i] * forx[j]);
                }
            }
        }
    }
    cout << mxfactor;
}