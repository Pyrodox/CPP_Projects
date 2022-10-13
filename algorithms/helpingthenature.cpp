#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; ++i) 
            cin >> a[i];
        ll pre = 0, suf = 0;    
        for (ll i = 0; i < n - 1; ++i) {
            if (a[i + 1] - a[i] < 0) {
                pre -= a[i + 1] - a[i];
            }
            else {
                suf += a[i + 1] - a[i];
            }
        }
        cout << pre + suf + abs(pre - a[0]) << "\n";
    }
}