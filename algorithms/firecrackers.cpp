#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b;
        ll edge;
        if (a < b) {
            edge = 1;
        }
        else {
            edge = n;
        }
        ll timeforguardtoreachend = abs(b - edge), permit = abs(b - edge) - 1;
        vector<ll> fireworks;
        for (ll i = 0; i < m; ++i) {
            ll c;
            cin >> c;
            if (c <= permit) {
                fireworks.push_back(c);
            }
        }
        sort(fireworks.begin(), fireworks.end());
        ll l = 0, r = min((ll)fireworks.size(), abs(b - a) - 1) + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2, sec = 1;
            if (mid == 0) {
                break;
            }
            bool flag = true;
            for (ll i = mid - 1; i >= 0; --i) {
                if (fireworks[i] + sec > timeforguardtoreachend) {
                    flag = false;
                    break;
                }
                ++sec;
            }
            if (flag) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        cout << max((ll)0, l - 1) << "\n";
    }
}