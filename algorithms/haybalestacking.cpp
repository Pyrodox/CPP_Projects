#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (ll i = 0; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        v[a]++;
        v[b]--;                      
    }
    vector<ll> data(n);
    ll val = 0;
    for (ll i = 0; i < n; ++i) {
        val += v[i];
        data[i] = val;
    }
    sort(data.begin(), data.end());
    cout << data[n / 2];
}