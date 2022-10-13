#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll p)
{
    a %= mod;
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * a % mod; 
        }
        a = a * a % mod;
        p >>= 1;
    }

    return res;
}

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cnt = 0;
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a % 2 == 0) {
            ++cnt;
        }
    }
    if (cnt < k) {
        cout << 0;

        return 0;
    }
    ll top = 1, bot = 1;
    for (ll i = 2; i <= cnt; ++i) {
        top *= i;
        if (i <= k) {
            bot *= i;
        }
        if (i <= cnt - k) {
            bot *= i;
        }
    }
    cout << top / bot;
}