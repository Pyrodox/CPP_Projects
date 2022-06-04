#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (ll i = 1; i <= n; ++i) {
        ll h = v[v[i]], t = v[i];
        while (h != t) {
            h = v[v[h]];
            t = v[t];
        }
        h = i;
        while (h != t) {
            h = v[h];
            t = v[t];
        }
        cout << h << " ";
    }
}