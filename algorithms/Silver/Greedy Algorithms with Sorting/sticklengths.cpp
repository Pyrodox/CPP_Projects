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
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll med1 = v[v.size() / 2], med2 = v[v.size() / 2 - 1];
    ll ans1 = 0, ans2 = 0;
    for (ll i = 0; i < n; ++i) {
        ans1 += abs(v[i] - med1);
        ans2 += abs(v[i] - med2);
    }
    cout << min(ans1, ans2);
}