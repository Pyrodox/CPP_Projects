#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<vector<ll>> pfx(n + 1);
    for (auto &val : pfx) {
        vector<ll> tmp(n + 1);
        val = tmp;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                pfx[i][j] = pfx[i][j - 1] + pfx[i - 1][j] - pfx[i - 1][j - 1];
            }
            else {
                pfx[i][j] = pfx[i][j - 1] + pfx[i - 1][j] - pfx[i - 1][j - 1] + 1;
            }
        }
    }
    for (ll i = 0; i < q; ++i) {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pfx[y2][x2] + pfx[y1 - 1][x1 - 1] - pfx[y2][x1 - 1] - pfx[y1 - 1][x2] << "\n";
    }
}