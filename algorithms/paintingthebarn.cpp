#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    ll n, k;
    fin >> n >> k;
    vector<vector<ll>> pref(1001, vector<ll>(1001));
    for (ll i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        pref[x1][y1]++;
        pref[x1][y2]--;
        pref[x2][y1]--;
        pref[x2][y2]++;
    }
    ll ans = 0;
    for (ll i = 0; i < 1000; ++i) {
        for (ll j = 0; j < 1000; ++j) {
            if (i > 0) {
                pref[i][j] += pref[i - 1][j];
            }
            if (j > 0) {
                pref[i][j] += pref[i][j - 1];
            }
            if (i > 0 && j > 0) {
                pref[i][j] -= pref[i - 1][j - 1];
            }
            if (pref[i][j] == k) {
                ++ans;
            }
        }
    }
    fout << ans;
}