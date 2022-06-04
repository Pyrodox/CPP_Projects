#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(vector<ll>& a, vector<ll>& b)
{
    if (a[0] == b[0]) {
        return a[1] <= b[1];
    }
    return a[0] < b[0];
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> ans;
    vector<vector<ll>> v;
    multimap<vector<ll>, int> mpv;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        mpv.insert(pair<vector<ll>, int>({a, b}, i));
    }
    sort(v.begin(), v.end(), cmp);
    vector<ll> ansv(n);
    for (ll i = 0; i < n; ++i) {
        ansv[mpv.find(v[i])->second] = i;
        mpv.erase(mpv.find(v[i]));
    }
    vector<ll> mn = {v[0][1], 0};
    ans.push_back(1);
    ll mxroom = 1;
    multiset<vector<ll>> ms;
    ms.insert({v[0][1], 0});
    for (ll i = 1; i < n; ++i) {
        if (v[i][0] > mn[0]) {
            ans.push_back(ans[mn[1]]);
            ms.erase(ms.find(mn));
        }
        else {
            ans.push_back(++mxroom);
        }
        ms.insert({v[i][1], i});
        mn = *ms.begin();
    }
    cout << mxroom << "\n";
    for (ll i = 0; i < n - 1; ++i) {
        cout << ans[ansv[i]] << " ";
    }
    cout << ans[ansv[n - 1]];
}