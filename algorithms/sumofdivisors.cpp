#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll calc(ll a)
{
     return (a % mod * (a % mod + (ll)1) / (ll)2) % mod;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll ans = (n % mod + calc(n)) % mod - 1;
    ans %= mod;
    for (ll i = 2; i * i <= n; ++i) {
        ans += (calc(n / i) - calc(i - (ll)1)) % mod;
        ans %= mod;
        ans += (i % mod * (n / i % mod) % mod - (i % mod * (i % mod) % mod) % mod) % mod;
        ans %= mod;
    }
    cout << ans % mod;
}