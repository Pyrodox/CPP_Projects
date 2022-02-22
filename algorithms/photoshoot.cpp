#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    fin >> n;
    vector<ll> b(n - 1);
    for (ll i = 0; i < n - 1; ++i) {
        fin >> b[i];
    }
    map<ll, ll> check;
    for (ll i = 1; i <= n; ++i) {
        check[i]++;
    }
    vector<ll> a(n);
    vector<vector<ll>> aa;
    for (ll i = 0; i < b[0]; ++i) {
        a[0] = b[0] - i;
        int j = 1;
        while (j < n - 1 && b[j - 1] - a[j - 1] > 0) {
            a[j] = b[j - 1] - a[j - 1];
            ++j;
        }
        a[a.size() - 1] = b[b.size() - 1] - a[a.size() - 2];
        map<ll, ll> tmpmap;
        for (ll k = 0; k < n; ++k) {
            tmpmap[a[k]]++;
        }
        if (check == tmpmap) {
            aa.push_back(a);
        }
    }
    sort(aa.begin(), aa.end());
    for (ll i = 0; i < aa[0].size() - 1; ++i) {
        fout << aa[0][i] << " ";
    }
    fout << aa[0][aa[0].size() - 1];
}