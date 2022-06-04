#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        multiset<ll> m;
        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            m.insert(a);
        }
        ll cnt = 0;
        while (m.size() > 0) {
            if (m.find(*m.begin() * x) == m.end()) {
                ++cnt;
                m.erase(m.find(*m.begin()));
            }
            else {
                m.erase(m.find(*m.begin() * x));
                m.erase(m.find(*m.begin()));
            }
        }
        cout << cnt << "\n";
    }
}