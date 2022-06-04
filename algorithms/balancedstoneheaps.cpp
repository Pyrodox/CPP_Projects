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
        vector<ll> v(n);
        ll maxval = 1;
        for (ll& i : v) {
            cin >> i;
            if (i > maxval) {
                maxval = i;
            }
        }
        ll l = 1, r = maxval;
        while (l < r) {
            ll mid = l + (r - l + 1) / 2;
            vector<ll> tmp = v, add(n);
            bool check = true;
            for (ll i = n - 1; i >= 2; --i) {
                if (add[i] >= mid) {
                    ll d = tmp[i] / 3;
                    add[i - 1] += d;
                    add[i - 2] += 2 * d;
                }
                else if (add[i] < mid) {
                    if (mid - add[i] > tmp[i]) {
                        check = false;
                        break;
                    }
                    ll d = (tmp[i] + add[i] - mid) / 3;
                    add[i - 1] += d;
                    add[i - 2] += 2 * d;
                }
            }
            if (check && add[0] + tmp[0] >= mid && add[1] + tmp[1] >= mid) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
}