#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<ll> v(n + 1);
        ll ans = 0;
        map<ll, ll> mp;
        for (ll i = 1; i <= n; ++i) {
            v[i] = s[i - 1] - '0' + v[i - 1];
            mp[v[i - 1] - i + 1]++;
            ans += mp[v[i] - i];
        }
        cout << ans << "\n";
    }
}