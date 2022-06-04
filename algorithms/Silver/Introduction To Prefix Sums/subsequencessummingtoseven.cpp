#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    vector<ll> present(n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if (present[v[i] % 7] == 0) {
            present[v[i] % 7] = i;
        }
        if (present[v[i] % 7]) {
            ans = max(ans, i - present[v[i] % 7]);
        }
    }
    cout << ans;
}