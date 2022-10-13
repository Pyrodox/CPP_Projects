#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v;
    ll ogn = n;
    for (ll i = 2; i * i <= ogn; ++i) {
        if (n % i == 0) {
            v.push_back(0);
            while (n % i == 0) {
                v[v.size() - 1]++;
                n /= i;
            }
        }
    }
    ll ans = 0;
    if (n > 1) {
        v.push_back(1);
    }
    for (ll a : v) {
        ll cnt = 1;
        for (ll i = 1; i <= a; i += cnt) {
            ++ans;
            ++cnt;
        }
    }
    cout << ans;
}