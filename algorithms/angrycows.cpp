#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll explosionind(vector<ll>& v, ll i, bool b)
{
    int lexpind = i;
    int rad = 1;
    while (lexpind > 0 && lexpind < v.size() - 1) {
        int dir = 0;
        if (b) {
            dir = -1;
        }
        else {
            dir = 1;
        }
        int nxtind = lexpind;
        while (nxtind + dir >= 0 && nxtind + dir < v.size() && abs(v[nxtind + dir] - v[lexpind]) <= rad) {
            nxtind += dir;
        }
        if (nxtind == lexpind) {
            break;
        }
        lexpind = nxtind;
        ++rad;
    }
    
    return lexpind;
}

int main()
{
    ll n;
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        ll l = explosionind(v, i, true);
        ll r = explosionind(v, i, false);
        ll num = r - l + 1;
        if (num > ans) {
            ans = num;
        }
    }
    fout << ans;
}