#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5 + 1;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n);
    ll reach = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        reach += v[i];
    }
    sort(v.begin(), v.end());
    set<ll> ans;
    vector<ll> dp(mx + 1);
    dp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = reach - v[i]; j >= 0; --j) {
            if (dp[j]) {
                dp[j + v[i]] = 1;
                ans.insert(j + v[i]);
            }
        }
    }
    cout << ans.size() << "\n";
    for (ll a : ans) {
        cout << a << " ";
    }
}