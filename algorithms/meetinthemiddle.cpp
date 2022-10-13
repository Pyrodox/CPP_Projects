#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void subsets(vector<ll>& v, vector<ll>& splitvec)
{
    v = {0};
    for (ll a : splitvec) {
        ll n = v.size();
        for (ll i = 0; i < n; ++i) {
            v.push_back(v[i] + a);
        }
    }
}

int main()
{
    ll n, x, a;
    vector<ll> v1, v2, subs1, subs2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (ll i = 0; i < n / 2; ++i) {
        cin >> a;
        v1.push_back(a);
    }
    for (ll i = n / 2; i < n; ++i) {
        cin >> a;
        v2.push_back(a);
    }
    subsets(subs1, v1);
    subsets(subs2, v2);
    ll ans = 0;
    map<ll, ll> mp;
    sort(subs2.begin(), subs2.end());
    for (ll a : subs2) {
        mp[a]++;
    }
    for (ll a : subs1) {
        if (binary_search(subs2.begin(), subs2.end(), x - a)) {
            ans += mp[x - a]; 
        }
    }
    cout << ans;
}