#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<ll> v(n);
    vector<vector<ll>> v2(n + 1);
    map<ll, ll> mp;
    for (ll& i : v) {
        cin >> i;
        mp[i]++;
    }
    vector<ll> validindices;
    map<ll, ll> arbitrarymap;
    for (auto val : mp) {
        v2[val.second].push_back(val.first);
        if (arbitrarymap[val.second] == 0) {
            validindices.push_back(val.second);
        }
        arbitrarymap[val.second]++;
    }
    sort(validindices.begin(), validindices.end());
    vector<ll> ans;
    ll l = 1, r = n + 1;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        bool check = false;
        vector<ll> anstmp;
        for (ll i = validindices.size() - 1; i >= 0 && !check; --i) {
            for (ll j = 0; j < v2[validindices[i]].size(); ++j) {
                for (ll k2 = 0; k2 < validindices[i] / mid && anstmp.size() < k; ++k2) {
                    anstmp.push_back(v2[validindices[i]][j]);
                }
                if (anstmp.size() >= k) {
                    check = true;
                    break;
                }
            }
        }
        if (check) {
            l = mid;
            ans = anstmp;
        }
        else {
            r = mid - 1;
        }
    }
    if (ans.size() == 0) {
        for (ll i = 0; i < k; ++i) {
            cout << v[i] << " ";
        }
    }
    else {
        for (auto val : ans) {
            cout << val << " ";
        }
    }
}