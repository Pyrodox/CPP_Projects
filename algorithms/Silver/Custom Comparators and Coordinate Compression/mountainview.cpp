#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const vector<ll>& a, const vector<ll>& b)
{
    if (a[0] - a[1] == b[0] - b[1]) {
        return a[1] > b[1];
    }
    return a[0] - a[1] < b[0] - b[1];
}

int main()
{
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
    ll n;
    cin >> n;
    vector<vector<ll>> v;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    ll cnt = 0, mxr = 0;
    for (ll i = 0; i < n; ++i) {
        if (mxr >= v[i][0] + v[i][1]) {
            ++cnt;
        }
        mxr = max(mxr, v[i][0] + v[i][1]);
    }
    cout << n - cnt;
}