#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 5e5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    ll v[mx], q1[mx], q2[mx];
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (ll i = 0; i < q; ++i) {
        cin >> q1[i] >> q2[i];
    }
    ll prefix[mx + 1];
    prefix[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        prefix[i] = v[i - 1] + prefix[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        cout << prefix[q2[i]] - prefix[q1[i]] << "\n";
    }
}