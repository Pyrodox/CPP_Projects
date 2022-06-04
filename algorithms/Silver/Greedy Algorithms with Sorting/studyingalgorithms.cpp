#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    multiset<ll> s;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll ttl = 0, ans = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        ttl += *it;
        if (ttl <= x) {
            ++ans;
        }
        else {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
}