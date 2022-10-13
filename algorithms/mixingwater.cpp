#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        ll hot, cold, desiredtemp;
        cin >> hot >> cold >> desiredtemp;
        double sum = (hot + cold) / 2.0;
        if (sum >= desiredtemp) {
            cout << 2 << "\n";
        }
        else {
            ll l = 0, r = 99999999999, assocmid = 2;
            while (l < r) {
                ll mid = (l + (r - l) / 2) * 2 + 1;
                double total = assocmid * (hot * ceil(mid / 2.0) + cold * floor(mid / 2.0) - desiredtemp * mid);
                double curtotal = mid * (hot * ceil(assocmid / 2.0) + cold * floor(assocmid / 2.0) - desiredtemp * assocmid);
                if (abs(total) < abs(curtotal) || abs(total) == abs(curtotal) && mid < assocmid) {
                    assocmid = mid;
                    sum = total;
                }
                if ((hot * ceil(mid / 2.0) + cold * floor(mid / 2.0)) / mid < desiredtemp) {
                    r = l + (r - l) / 2;
                }
                else {
                    l = l + (r - l) / 2 + 1;
                }
            }
            cout << assocmid << "\n";
        }
    }
}