#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;
 
ll binpow(ll a, ll p, ll modu)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res % modu * (a % modu) % modu;
        }
        a = a % modu * (a % modu) % modu;
        p >>= 1;
    }
 
    return res % modu;
}
 
int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll modforprod = 1, numofdivisors = 1, sumofdivisors = 1, prodofdivisors = 1;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; ++i) {
        ll p, a;
        cin >> p >> a;
        numofdivisors = numofdivisors % mod * ((a % mod + 1) % mod) % mod;
        sumofdivisors = (sumofdivisors % mod * ((binpow(p, a + 1, mod) - 1) % mod * (binpow(p - 1, mod - 2, mod) % mod) % mod)) % mod; 
        prodofdivisors = binpow(prodofdivisors, a + 1, mod)  * (binpow(binpow(p, a * (a + 1) / 2, mod), modforprod, mod)) % mod;
        modforprod = modforprod % (mod - 1) * ((a % (mod - 1) + 1) % (mod - 1)) % (mod - 1);
        v.push_back({p, a});
    }
    cout << numofdivisors << " " << sumofdivisors << " " << prodofdivisors;
}