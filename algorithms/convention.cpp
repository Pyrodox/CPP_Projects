#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, cap;
    ifstream fin("convention.in");
    ofstream fout("convention.out");
    fin >> n >> m >> cap;
    vector<ll> v(n);
    ll mx = 0;
    for (ll& i : v) {
        fin >> i;
        mx = max(mx, i);
    }
    sort(v.begin(), v.end());
    ll l = 0, r = mx;
    while (l < r) {
        ll mid = l + (r - l) / 2, current = 0;
        vector<vector<ll>> buses(m);
        for (ll i = 0; i < m && current < n; ++i) {
            for (ll j = 0; j < cap && current < n; ++j) {
                if (buses[i].size() > 0 && v[current] - buses[i][0] > mid) {
                    break;
                }
                else {
                    buses[i].push_back(v[current]);
                    ++current;
                }
            }
        }
        if (current == n) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    fout << l; 
}