#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> n;
    multiset<ll> s;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll ans = 0;
    while (s.size() >= 2) {
        auto it1 = s.begin(), it2 = s.begin();
        ++it2;
        ans += *it1 + *it2;
        s.insert(*it1 + *it2);
        s.erase(s.find(*it1));
        s.erase(s.find(*it2));
    }
    cout << ans;
}