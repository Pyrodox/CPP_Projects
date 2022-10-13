#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(vector<ll>& a, vector<ll>& b)
{
    return a[1] > b[1];
}

int main()
{
    ll l, n, fj, bessie;
    //ifstream cin("reststops.in");
    //ofstream cout("reststops.out");
    cin >> l >> n >> fj >> bessie;
    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0, bound = 0;
    for (ll i = 0; i < n; ++i) {
        if (v[i][0] > bound) {
            ans += v[i][1] * (v[i][0] - bound) * (fj - bessie);
            cout << v[i][1] * (v[i][0] - bound) * (fj - bessie) << "\n";
            bound = v[i][0];
        }
    }
    cout << ans;
}