#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    bitset<2001> bt[2001];
    vector<vector<ll>> v(2001, vector<ll>(2001));
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        bt[a][b] = 1;
        bt[b][a] = 1;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            if ((bt[i] & bt[j]).count() && v[i][j]) {
                cnt += (bt[i] & bt[j]).count();
            }
        }
    }
    cout << cnt / 3;
}   