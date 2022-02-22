#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    vector<ll> v(n + 1);
    for (ll i = 1; i < n; ++i) {
        cin >> v[i];
    }
    ll checker = 1;
    while (checker <= n) {
        if (checker == t) {
            cout << "YES";
            return 0;
        }
        if (checker + v[checker] <= t) {
            checker += v[checker];
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "NO";
}