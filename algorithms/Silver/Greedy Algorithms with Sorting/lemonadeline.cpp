#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    fin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        fin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> lne;
    for (ll i = n - 1; i >= 0; --i) {
        if (v[i] >= lne.size()) {
            lne.push_back(v[i]);
        }
    }
    fout << lne.size();
}