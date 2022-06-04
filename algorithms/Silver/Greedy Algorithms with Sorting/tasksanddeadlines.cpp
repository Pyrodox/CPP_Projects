#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }

    return a[0] < b[0];
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0, time = 0;
    for (ll i = 0; i < n; ++i) {
        time += v[i][0];
        ans += v[i][1] - time;
    }
    cout << ans;
}