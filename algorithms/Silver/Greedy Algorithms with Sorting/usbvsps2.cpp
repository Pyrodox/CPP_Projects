#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b, c, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c >> m;
    vector<ll> usb, ps2;
    for (ll i = 0; i < m; ++i) {
        ll a;
        string s;
        cin >> a >> s;
        if (s == "USB") {
            usb.push_back(a);
        }
        else {
            ps2.push_back(a);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    ll ans1 = 0, ans2 = 0, i = 0, j = 0;
    for (; i < usb.size() && a > 0; ++i) {
        ++ans1;
        ans2 += usb[i];
        //cout << usb[i] << "\n";
        --a;
    }
    for (; j < ps2.size() && b > 0; ++j) {
        ++ans1;
        ans2 += ps2[j];
        //cout << ps2[j] << "\n";
        --b;
    }
    vector<ll> merged;
    merge(usb.begin() + i, usb.end(), ps2.begin() + j, ps2.end(), back_inserter(merged));
    for (ll i = 0; i < merged.size() && c > 0; ++i) {
        ++ans1;
        ans2 += merged[i];
        --c;
    }
    cout << ans1 << " " << ans2;
}