#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    set<ll> s;
    map<ll, ll> mp;
    for (ll i = 0; i < n; ++i) {
        ll a1, a2;
        cin >> a1 >> a2;
        s.insert(a1);
        s.insert(a2 + 1);
        mp[a1]++;
        mp[a2 + 1]--;
    }
    vector<ll> ans(n);
    ll current = 0;
    for (auto it = s.begin(); it != --s.end(); ++it) {
        auto it2 = it;
        ++it2;
        if (mp[*it] - 1 + current >= 0 && mp[*it] - 1 + current < n) {
            ans[mp[*it] - 1 + current] += *it2 - *it;
        }
        current += mp[*it];
    }
    for (ll i : ans) {
        cout << i << " ";
    }
}