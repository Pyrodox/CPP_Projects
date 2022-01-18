#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    map<ll, ll> m;
    vector<ll> v2;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        ll det, val;
        cin >> det;
        if (det == 0) {
            ll k;
            cin >> k >> val;
            m[k] = val;
        }
        else {
            cin >> val;
            v2.push_back(m[val]);
        }
    }
    for (auto val : v2) {
        cout << val << "\n";
    }
}