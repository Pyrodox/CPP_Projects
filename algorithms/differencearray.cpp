#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> v;
        ll zeroamt = n;
        for (ll i = 0; i < n; ++i) {
            ll b;
            cin >> b;
            if (b) {
                v.push_back(b);
            }
            if (zeroamt == n && b) {
                zeroamt = i;
            }
        }
        for (ll i = 0; i < n - 1; ++i) {
            vector<ll> a;
            if (zeroamt && v.size()) {
                a.push_back(v[0]);
            }
            zeroamt = max((ll)0, zeroamt - 1);
            for (ll j = 0; j < max((ll)0, (ll)v.size() - 1); ++j) {
                if (v[j + 1] - v[j] == 0) {
                    ++zeroamt;
                }
                else {
                    a.push_back(v[j + 1] - v[j]);
                }
            }
            v = a;
            sort(v.begin(), v.end());
        }
        if (zeroamt) {
            cout << 0 << "\n";
        }
        else {
            cout << v[0] << "\n";
        }
    }
}