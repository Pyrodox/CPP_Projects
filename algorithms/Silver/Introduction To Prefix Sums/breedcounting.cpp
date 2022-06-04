#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a == 1) {
            v[i][0]++;
        }
        else if (a == 2) {
            v[i][1]++;
        }
        else {
            v[i][2]++;
        }
    }
    vector<vector<ll>> pfx(n + 1, vector<ll>(3));
    for (ll i = 1; i <= n; ++i) {
        pfx[i][0] = v[i - 1][0] + pfx[i - 1][0];
        pfx[i][1] = v[i - 1][1] + pfx[i - 1][1];
        pfx[i][2] = v[i - 1][2] + pfx[i - 1][2];
    }
    for (ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << pfx[b][0] - pfx[a - 1][0] << " " << pfx[b][1] - pfx[a - 1][1] << " " << pfx[b][2] - pfx[a - 1][2] << "\n";
    }
}