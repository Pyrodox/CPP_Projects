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
    vector<ll> rooms, ans;
    rooms.push_back(1);
    vector<vector<ll>> v;
    multimap<vector<ll>, ll> mpv;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        mpv.insert(pair<vector<ll>, ll>({a, b}, i));
    }
    sort(v.begin(), v.end(), cmp);
    vector<ll> ansv;
    for (ll i = 0; i < n; ++i) {
        ansv.push_back(mpv.find(v[i])->second);
        mpv.erase(mpv.find(v[i]));
    }
    vector<ll> mn = {v[0][1], 0};
    ll mxroom = 1, mnasocroom = 1;
    multiset<vector<ll>> ms;
    ms.insert({v[0][1], 0});
    for (ll i = 1; i < n; ++i) {
        if (v[i][0] > mn[0]) {
            ms.insert({v[i][1], i});
            ms.erase(ms.find(mn));
            mn = *ms.begin();
            ans.push_back(mn[1]);
        }
        else {
            ans.push_back(++mxroom);
            ms.insert(v[i][1]);
            rooms.push_back(mxroom);
            mn = *ms.begin();
        }
    }
    cout << mxroom << "\n";
    for (ll i = 0; i < n - 1; ++i) {
        cout << ans[i] << " "; //ans[ansv[i]]
    }
    cout << ans[n - 1];
}