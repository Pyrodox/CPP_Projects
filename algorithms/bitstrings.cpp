#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b) {
        if (b % 2) {
            res = ((res % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b /= 2;
    }

    return res % mod;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << power(2, n, 1000000007);
}