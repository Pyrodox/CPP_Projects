#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<ll> v(n);
    vector<vector<ll>> pref(n + 1, vector<ll>(30));
    vector<ll> powref = {1};
    for (ll i = 1; i <= 29; ++i) {
        powref.push_back(2 * powref[i - 1]);
    }
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        for (ll j = 29; j >= 0; --j) {
            if (v[i] - powref[j] >= 0) {
                v[i] -= powref[j];
                pref[i + 1][j]++;
            }
            pref[i + 1][j] += pref[i][j];
        }
    }
    for (ll i = 0; i < q; ++i) {
        ll a, b, sum = 0;
        cin >> a >> b;
        for (ll j = 29; j >= 0; --j) {
            if ((pref[b][j] - pref[a - 1][j]) % 2 == 1) {
                sum += powref[j];
            }
        }
        cout << sum << "\n";
    }
}