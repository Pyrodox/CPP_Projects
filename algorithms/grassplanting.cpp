#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    fin >> n;
    vector<ll> a[n + 1];
    for (ll i = 0; i < n - 1; ++i) {
        ll tmp1, tmp2;
        fin >> tmp1 >> tmp2;
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
    int mx = 0;
    for (auto val : a) {
        mx = max(mx, (int) val.size());
    }
    fout << mx + 1; 
}