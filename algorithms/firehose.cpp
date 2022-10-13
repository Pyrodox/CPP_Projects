#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll h, k;
    cin >> h;
    vector<ll> houses(h);
    for (ll i = 0; i < h; ++i) {
        cin >> houses[i];
    }
    cin >> k;
    sort(houses.begin(), houses.end());
    ll l = 0, r = 500000;
    while (l < r) {
        ll mid = l + (r - l) / 2, flag = 1, count = 1, secondflag = 0;
        auto houses2 = houses;
        for (ll i = 0; i < h; ++i) {
            ll target = houses2[0] + 2 * mid, rotation = 0;
            for (ll j = 0; j < h; ++j) {
                if (houses2[j] + rotation > target) {
                    ++count;
                    target = houses2[j] + 2 * mid;
                }
                if (j + 1 < h && houses2[j + 1] < houses2[j]) {
                    rotation = 1000000;
                }
                if (count > k) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                secondflag = 1;
                break;
            }
            flag = 1, count = 1;
            rotate(houses2.begin(), houses2.begin() + 1, houses2.end());
        }
        if (flag && secondflag) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}