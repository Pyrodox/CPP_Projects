#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    return a[1] < b[1];
}

int main()
{
    ll n;
    ifstream cin("split.in");
    ofstream cout("split.out");
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end());
    ll leftx = v[0][0], rightx = v[n - 1][0], minh = v[0][1], maxh = v[0][1];
    multiset<ll> seth;
    for (ll i = 0; i < n; ++i) {
        seth.insert(v[i][1]);
    }
    ll ans = (rightx - leftx) * (*seth.rbegin() - *seth.begin());
    ll originalans = ans;
    for (ll i = 0; i < n - 1; ++i) {
        seth.erase(seth.find(v[i][1]));
        minh = min(minh, v[i][1]);
        maxh = max(maxh, v[i][1]);
        if (v[i][0] != v[i + 1][0] || (*seth.rbegin() < minh || *seth.begin() > maxh)) {
            ans = min(ans, (maxh - minh) * (v[i][0] - leftx) + (rightx - v[i + 1][0]) * (*seth.rbegin() - *seth.begin()));
        }
    }
    sort(v.begin(), v.end(), cmp);
    ll lowx = v[0][1], upx = v[n - 1][1], minw = v[0][0], maxw = v[0][0];
    multiset<ll> setw;
    for (ll i = 0; i < n; ++i) {
        setw.insert(v[i][0]);
    }
    for (ll i = 0; i < n - 1; ++i) {
        setw.erase(setw.find(v[i][0]));
        minw = min(minw, v[i][0]);
        maxw = max(maxw, v[i][0]);
        if (v[i][1] != v[i + 1][1] || (*setw.rbegin() < minw || *setw.begin() > maxh)) {
            ans = min(ans, (maxw - minw) * (v[i][1] - lowx) + (upx - v[i + 1][1]) * (*setw.rbegin() - *setw.begin()));
        }
    }
    cout << originalans - ans;
}