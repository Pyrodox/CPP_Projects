#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ifstream cin("sort.in");
    ofstream cout("sort.out");
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> v[i][0];
        v[i][1] = i;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans = max(ans, v[i][1] - i);
    }
    cout << ans + 1;
}