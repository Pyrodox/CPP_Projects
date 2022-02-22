#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    fin >> n;
    vector<vector<ll>> x, y;
    for (ll i = 0; i < n; ++i) {
        vector<ll> tmp(2), tmp2(2);
        fin >> tmp[0] >> tmp[1];
        tmp2[0] = tmp[1];
        tmp2[1] = tmp[0];
        x.push_back(tmp);
        y.push_back(tmp2);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll minarea = 99999999999;
    vector<vector<ll>> removeparts;
    removeparts.push_back(x[0]);
    removeparts.push_back(x[x.size() - 1]);
    vector<ll> lowesty = y[0];
    swap(lowesty[0], lowesty[1]);
    removeparts.push_back(lowesty);
    vector<ll> highesty = y[y.size() - 1];
    swap(highesty[0], highesty[1]);
    removeparts.push_back(highesty);
    for (ll i = 0; i < 4; ++i) {
        vector<vector<ll>> tmp = x;
        tmp.erase(find(tmp.begin(), tmp.end(), removeparts[i]));
        vector<vector<ll>> tmp2 = y;
        vector<ll> tmp3 = removeparts[i];
        swap(tmp3[0], tmp3[1]);
        tmp2.erase(find(tmp2.begin(), tmp2.end(), tmp3));
        minarea = min(minarea, (tmp[tmp.size() - 1][0] - tmp[0][0]) * (tmp2[tmp2.size() - 1][0] - tmp2[0][0]));
    }
    fout << minarea;
}