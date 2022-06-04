#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll q, n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n;
        vector<ll> v(n);
        for (ll& i : v) {
            cin >> i;
        }
        sort(v.begin(), v.end());
        ll x, a, y, b, k;
        cin >> x >> a >> y >> b >> k;
        bool ans = false;
        ll l = 1, r = n + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            //cout << "testing mid: " << mid << "\n";
            vector<ll> tmp(mid + 1);
            for (ll i = 1; i <= mid; ++i) {
                if (i % a == 0 && i % b == 0) {
                    tmp[i] = x + y;
                }
                else if (i % a == 0) {
                    tmp[i] = x;
                }
                else if (i % b == 0) {
                    tmp[i] = y;
                }
                else {
                    tmp[i] = 0;
                }
            }
            sort(tmp.begin(), tmp.end());
            /*cout << "tmp:\n";
            for (auto val : tmp) {
                cout << val << " ";
            }*/
            //cout << "\n";
            ll total = 0;
            bool check = false;
            ll i2 = mid;
            for (ll i = n - 1; i > n - 1 - mid; --i) {
                total += tmp[i2] * (v[i] / 100);
                //cout << tmp[i2] << " " << v[i] << " ";
                //cout << "total: " << total << "\n";
                if (total >= k) {
                    check = true;
                    ans = true;
                    break;
                }
                /*if (tmp[i2] * v[i] == 0) {
                    break;
                }*/
                --i2;
            }
            if (check) {
                //cout << "r from " << r << "\n";
                r = mid;
            }
            else {
                //cout << "l from " << l << "\n";
                l = mid + 1;
            }
        }
        if (!ans) {
            cout << -1 << "\n";
        }
        else {
            cout << l << "\n";
        }
    }
}