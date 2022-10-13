#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s >> q;
    ll oamt[s.size() + 1], camt[s.size() + 1], wamt[s.size() + 1];
    oamt[0] = 0, wamt[0] = 0, camt[0] = 0;
    for (ll i = 1; i <= s.size(); ++i) {
        camt[i] = camt[i - 1];
        oamt[i] = oamt[i - 1];
        wamt[i] = wamt[i - 1];
        if (s[i - 1] == 'C') {
            ++camt[i];
        }
        else if (s[i - 1] == 'O') {
            ++oamt[i];
        }
        else {
            ++wamt[i];
        }
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll c = camt[r] - camt[l - 1], w = wamt[r] - wamt[l - 1], o = oamt[r] - oamt[l - 1];
        if (c % 2 == 1 && w % 2 == 0 && o % 2 == 0) {
            cout << "Y";
        }
        else if (c % 2 == 0 && w % 2 == 1 && o % 2 == 1) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
}