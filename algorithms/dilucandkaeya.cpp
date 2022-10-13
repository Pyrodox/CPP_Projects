#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 5e5 + 1;

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        map<pair<ll, ll>, ll> amtperratio;
        ll kzeroratioamt = 0, dzeroamt = 0, cntD = 0, cntK = 0;;
        string s;
        cin >> s;
        for (ll i = 0; i < n; ++i) {
            ll ans = 0;
            if (s[i] == 'D') {
                ++cntD;
            }
            else {
                ++cntK;
            }
            if (cntK == 0) {
                kzeroratioamt++;
                ans = kzeroratioamt;
            }
            else if (cntD == 0) {
                dzeroamt++;
                ans = dzeroamt;
            }
            else {
                amtperratio[{cntD / __gcd(cntD, cntK), cntK / __gcd(cntD, cntK)}]++;
                ans = amtperratio[{cntD / __gcd(cntD, cntK), cntK / __gcd(cntD, cntK)}];
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}