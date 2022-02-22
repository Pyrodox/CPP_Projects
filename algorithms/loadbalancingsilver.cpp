#include <bits/stdc++.h>
using namespace std;
using ll = long long unsigned int;

int main()
{
    ll n;
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    fin >> n;
    vector<vector<ll>> xy;
    for (ll i = 0; i < n; ++i) {
        vector<ll> tmp(2);
        fin >> tmp[0] >> tmp[1];
        tmp[1] /= 2;
        xy.push_back(tmp);
    }
    sort(xy.begin(), xy.end(), [] (vector<ll> v1, vector<ll> v2) {
        if (v1[0] == v2[0]) {
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    });
    ll mn = n;
    for (int i = 0; i < n; ++i) {
        vector<vector<ll>> low, hgh;
        for (int j = 0; j < n; ++j) {
            if (xy[j][1] > xy[i][1]) {
                hgh.push_back(xy[j]);
            }
            else {
                low.push_back(xy[j]);
            }
        }
        ll lowindex = 0, hghindex = 0;
        while (lowindex < low.size() || hghindex < hgh.size()) {
            ll xborder = 10000000;
            if (lowindex < low.size()) {
                xborder = min(xborder, low[lowindex][0]);
            }
            if (hghindex < hgh.size()) {
                xborder = min(xborder, hgh[hghindex][0]);
            }
            while (lowindex < low.size() && low[lowindex][0] == xborder) {
                ++lowindex;
            }
            while (hghindex < hgh.size() && hgh[hghindex][0] == xborder) {
                ++hghindex;
            }
            mn = min(mn, max(max(lowindex, low.size() - lowindex), max(hghindex, hgh.size() - hghindex)));
        }
    }
    fout << mn;
}