#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 2, LOG = 17;

vector<vector<ll>> m(mx, vector<ll>(LOG + 1));

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> m[i][0];
    }
    for (ll i = 1; i <= LOG; ++i) {
        for (ll j = 1; j <= n + 1 - (1 << (i - 1)); ++j) {
            m[j][i] = m[j][i - 1] + m[j + (1 << (i - 1))][i - 1];
        }
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll length = b - a + 1, sum = 0;
        for (ll i = 0; i <= LOG && a <= b; ++i) {
            if ((1 << i) & length) {
                sum += m[a][i];
                a += (1 << i);
            }
        }
        cout << sum << "\n";
    }
}