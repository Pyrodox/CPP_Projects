#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t, n;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; ++i) {
            v[i] = stoi(s.substr(i - 1, 1));
        }
        for (int i = 1; i <= n; ++i) {
            v[i] += v[i - 1];
        }
        map<ll, ll> m;
        m[0] = 1;
        for (ll i = 1; i <= n; ++i) {
            m[v[i] - i]++;
        }
        ll ans = 0;
        for (auto val : m) {
            ans += val.second * (val.second - 1) / 2;
        }
        cout << ans << "\n";
    }
}