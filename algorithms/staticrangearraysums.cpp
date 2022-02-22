#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    ll v[n], q1[q], q2[q];
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (ll i = 0; i < q; ++i) {
        cin >> q1[i] >> q2[i];
    }
    ll prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        prefix[i] = v[i - 1] + prefix[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        cout << prefix[q2[i]] - prefix[q1[i]] << "\n";
    }
}