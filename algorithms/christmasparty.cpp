#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7; 

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll d[n + 1];
    d[1] = 0;
    d[2] = 1;
    for (ll i = 3; i <= n; ++i) {
         d[i] = (d[i - 1] + d[i - 2]) % mod * (i - 1) % mod;
    }
    cout << d[n];
}