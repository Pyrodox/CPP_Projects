#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll> v, ll n, ll i, ll s1, ll s2)
{
    if (i == n) {
        return abs(s1 - s2);
    }
    
    return min(solve(v, n, i + 1, s1 + v[i], s2), solve(v, n, i + 1, s1, s2 + v[i]));
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(v, n, 0, 0, 0);
}