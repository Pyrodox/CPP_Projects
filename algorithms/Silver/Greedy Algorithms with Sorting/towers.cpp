#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n);
    multiset<ll> ans;
    ll mx = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] >= mx) {
            ans.insert(v[i]);
            mx = v[i];
        }
        else {
            auto it = ans.upper_bound(v[i]);
            ans.erase(ans.find(*it));
            ans.insert(v[i]);
            mx = *(--ans.end());
        }
    }
    cout << ans.size();
}